#include "resistor_color.h"

resistor_band_t band[] = {BLACK, BROWN, RED,    ORANGE, YELLOW,
                          GREEN, BLUE,  VIOLET, GREY,   WHITE};

int color_code(resistor_band_t color) {
  for (int i = 0; i < 10; i++) {

    if (band[i] == color) {
      return i;
    }
  }

  return -1;
}

resistor_band_t *colors() { return band; }
