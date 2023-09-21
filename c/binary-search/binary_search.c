#include "binary_search.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length) {

  if (length == 0) {
    return NULL;
  }

  size_t middle = length >> 1;

  printf("%zu, %zu\n", middle, length);

  int middleVal = arr[middle];

  if (value == middleVal) {
    return &arr[middle];
  }

  else if (value > middleVal) {
    size_t newLength = length - middle - 1;
    return binary_search(value, &arr[middle + 1], newLength);
  } else {

    size_t newLength = middle;
    return binary_search(value, arr, newLength);
  }
}
