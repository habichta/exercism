#include "allergies.h"
#include <stdio.h>

bool is_allergic_to(allergen_t allergen, int score) {
  int mask = 0x1;
  int temp = score;
  bool is_alergic = false;

  for (int i = 0; i < 8; i++) {

    if ((temp & mask) == 1) {
      if (i == (int)allergen) {
        is_alergic = true;
      }
    }

    temp >>= 1;
  }

  return is_alergic;
}
allergen_list_t get_allergens(int score) {
  allergen_list_t list;
  list.count = 0;
  int mask = 0x1;
  int temp = score;

  for (int i = 0; i < 8; i++) {

    if ((temp & mask) == 0x1) {
      list.count++;
      list.allergens[i] = true;
    }

    temp >>= 1;
  }

  return list;
}
