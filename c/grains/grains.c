#include "grains.h"
#include <stdint.h>
#include <stdio.h>

uint64_t square(uint8_t index) {

  if (index <= 0 || index > 64) {
    return 0;
  }

  uint64_t grains = 1UL;

  grains = (grains << (index - 1));

  return grains;
}

uint64_t total(void) {
  uint64_t grains = (((1UL << 63) - 1) << 1) + 1;
  return grains;
}
