#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100
#define ARRAY_LENGTH(A) (sizeof(A) / sizeof(A[0]))

typedef int buffer_value_t;

typedef struct {
  buffer_value_t *values;
  buffer_value_t *current_buffer_pointer;
  size_t capacity;

} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);

buffer_value_t read(circular_buffer_t *, buffer_value_t *);
int16_t write(circular_buffer_t *, buffer_value_t);
int16_t overwrite(circular_buffer_t *, buffer_value_t);
void clear_buffer(circular_buffer_t *);
void delete_buffer(circular_buffer_t *);

#endif
