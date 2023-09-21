#include "circular_buffer.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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

  return buffer;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *valAddr) {

  if (buffer->count > 0) {

    *valAddr = *buffer->current_old;
    if (buffer->current_old == buffer->end) {
      buffer->current_old = buffer->start;
    } else {
      buffer->current_old++;
    }
    buffer->count--;

    return 0;

  } else {
    return EXIT_FAILURE;
  }
}
int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {

  *(buffer->current_new) = value;
  buffer->count++;

  if (buffer->current_new == buffer->end) {
    buffer->current_new = buffer->start;
  } else {
    buffer->current_new++;
  }

  return 0;
}
int16_t write(circular_buffer_t *buffer, buffer_value_t value) {

  if (buffer->capacity >= buffer->count) {

    *(buffer->current_new) = value;
    buffer->count++;

    if (buffer->current_new == buffer->end) {
      buffer->current_new = buffer->start;
    } else {

      buffer->current_new++;
    }

    printf("count %zu\n", buffer->count);
    return 0;
  } else {
    return EXIT_FAILURE;
  }
}

void clear_buffer(circular_buffer_t *buffer) {

  buffer_value_t *temp = buffer->start;
  for (size_t i = 0; i < buffer->capacity; i++) {
    *(temp + i) = 0;
  }
}

void delete_buffer(circular_buffer_t *buffer) {
  free(buffer->start);
  free(buffer);
}
