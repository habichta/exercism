#include "pythagorean_triplet.h"
#include "stdlib.h"
#include <stddef.h>
#include <stdint.h>

void free_triplets(triplets_t *triplets) { free(triplets); }

triplets_t *triplets_with_sum(uint16_t sum) {

  size_t triplet_count = 0;

  triplets_t *triplets = malloc(sizeof(size_t) + sizeof(triplet_t));
  triplets->count = 0;

  for (int a = 0; a < sum; a++) {
    for (int b = a + 1; b < sum; b++) {
      uint16_t c = sum - a - b;

      if (c > a && c > b && a * a + b * b == c * c) {
        triplet_count++;
        triplet_t triplet = {.a = a, .b = b, .c = c};

        triplets = realloc(triplets,
                           sizeof(size_t) + triplet_count * sizeof(triplet_t));

        triplets->count = triplet_count;
        triplets->triplets[triplet_count - 1] = triplet;
      }
    }
  }
  return triplets;
}
