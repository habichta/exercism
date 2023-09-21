#include "circular_buffer.h"
#include <stdlib.h>

circular_buffer_t *new_circular_buffer(size_t capacity) {

  circular_buffer_t *buffer;
  buffer_value_t *buffer_values;
  buffer = (circular_buffer_t *)calloc(1, sizeof(circular_buffer_t));

  buffer_values = (buffer_value_t *)calloc(capacity, sizeof(buffer_value_t));

  buffer->values = buffer_values;
  buffer->current_buffer_pointer = buffer_values;
  buffer->capacity = capacity;

  return buffer;
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value) {}

void clear_buffer(circular_buffer_t *buffer) {}

void delete_buffer(circular_buffer_t *buffer) {
  free(buffer->values);
  free(buffer);
}
