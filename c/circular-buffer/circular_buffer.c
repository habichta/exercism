#include "circular_buffer.h"
#include <asm-generic/errno.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// int main() {
//
//   size_t capacity = 1;
//   buffer_value_t read_value = 0;
//
//   circular_buffer_t *buffer = new_circular_buffer(capacity);
//   int16_t status = read(buffer, &read_value);
//   printf("%d\n", status);
//   delete_buffer(buffer);
//   return 0;
// }

circular_buffer_t *new_circular_buffer(size_t capacity) {

  circular_buffer_t *buffer;
  buffer_value_t *buffer_values;
  buffer = (circular_buffer_t *)calloc(1, sizeof(circular_buffer_t));

  buffer_values = (buffer_value_t *)calloc(capacity, sizeof(buffer_value_t));

  buffer->start = buffer_values;
  buffer->end = buffer->start + (capacity - 1);
  buffer->current_new = buffer_values;
  buffer->current_old = buffer_values;
  buffer->capacity = capacity;
  buffer->count = 0;

  clear_buffer(buffer);

  return buffer;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *valAddr) {

  if (buffer->count > 0) {

    *valAddr = *buffer->current_old;
    movePointer(buffer, &buffer->current_old);
    buffer->count--;

    return 0;

  } else {
    errno = ENODATA;
    return EXIT_FAILURE;
  }
}

void movePointer(circular_buffer_t *buffer, buffer_value_t **ptr) {
  if (*ptr == buffer->end) {
    *ptr = buffer->start;
  } else {
    *ptr += 1;
  }
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {

  if (buffer->capacity > buffer->count) {
    return write(buffer, value);
  } else {
    *(buffer->current_new) = value;
    movePointer(buffer, &buffer->current_new);
    movePointer(buffer, &buffer->current_old);
  }
  return 0;
}
int16_t write(circular_buffer_t *buffer, buffer_value_t value) {

  if (buffer->capacity > buffer->count) {

    *(buffer->current_new) = value;
    buffer->count++;

    movePointer(buffer, &buffer->current_new);

    return 0;
  } else {
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }
}

void clear_buffer(circular_buffer_t *buffer) {

  buffer_value_t *temp = buffer->start;
  for (size_t i = 0; i < buffer->capacity; i++) {
    *(temp + i) = 0;
  }
  buffer->count = 0;
}

void delete_buffer(circular_buffer_t *buffer) {
  free(buffer->start);
  free(buffer);
}
