#include "saddle_points.h"
#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

saddle_points_t *saddle_points(size_t x, size_t y, uint8_t matrix[x][y]) {

  saddle_points_t *saddle_points =
      malloc(sizeof(size_t) + sizeof(saddle_point_t));

  saddle_points->count = 0;

  int rows_max[x];
  int cols_min[y];
  int rows_max_ind[x];
  int cols_min_ind[y];

  for (size_t i = 0; i < x; i++) {
    rows_max[i] = -1;
    rows_max_ind[i] = 0;
  }

  for (size_t i = 0; i < y; i++) {
    cols_min[i] = 1024;
    cols_min_ind[i] = 0;
  }

  for (size_t row = 0; row < x; row++) {

    for (size_t col = 0; col < y; col++) {
      int current_value = matrix[row][col];

      if (rows_max[row] <= current_value) {
        rows_max[row] = current_value;
        rows_max_ind[row] = col;
      }
      if (cols_min[col] >= current_value) {
        cols_min[col] = current_value;
        cols_min_ind[col] = row;
      }
    }
  }

  for (size_t i = 0; i < x; i++) {

    int max_col_ind = rows_max_ind[i];

    if (max_col_ind != -1) {
      int max_row_ind = cols_min_ind[max_col_ind];

      if (max_row_ind == (int)i) {
        saddle_points->count++;

        saddle_points =
            realloc(saddle_points, sizeof(size_t) + saddle_points->count *
                                                        sizeof(saddle_point_t));
        saddle_point_t sp = {.row = i + 1, .column = max_col_ind + 1};

        saddle_points->points[saddle_points->count - 1] = sp;
      }
    }
  }
  return saddle_points;
}

void free_saddle_points(saddle_points_t *saddle_points) { free(saddle_points); }
