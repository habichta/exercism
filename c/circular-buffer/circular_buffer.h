#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef int buffer_value_t;

typedef struct {
  buffer_value_t *start;
  buffer_value_t *end;
  buffer_value_t *current_new;
  buffer_value_t *current_old;
  size_t capacity;
  size_t count;

} circular_buffer_t;

circular_buffer_t *new_circular_buffer(size_t capacity);

int16_t read(circular_buffer_t *, buffer_value_t *);

int16_t write(circular_buffer_t *, buffer_value_t);
int16_t overwrite(circular_buffer_t *, buffer_value_t);
void clear_buffer(circular_buffer_t *);
void delete_buffer(circular_buffer_t *);
void movePointer(circular_buffer_t *, buffer_value_t **);

#endif
