#include "saddle_points.h"
#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>

saddle_points_t *saddle_points(size_t x, size_t y, uint8_t matrix[x][y]) {

  size_t rows[x][2];
  size_t cols[y][2];

  for (int row = 0; row < x; row++) {
    for (int col = 0; col < y; col++) {

      // go through matrix and save index of largest point / smallest point row
      // and columnwise check if both row and col have the same index somewhere
      // -> match
    }
  }

  for (int row = 0; row < x; row++) {

    for (int col = 0; col < y; col++) {

      uint8_t point = matrix[row][col];
      uint8_t point_west = matrix[row][col + 1];
      uint8_t point_east = matrix[row][col - 1];
      uint8_t point_north = matrix[row + 1][col];
      uint8_t point_south = matrix[row - 1][col];

      if (point) {
      }
    }
  }
}

void free_saddle_points(saddle_points_t *saddle_points) { free(saddle_points); }
