#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stdint.h>

typedef struct {
  int numerator;
  int denominator;
} rational_t;

rational_t add(rational_t a, rational_t b);

rational_t reduce(rational_t rational);

int gcd_custom(int a, int b);
rational_t add(rational_t first, rational_t sec);
rational_t subtract(rational_t first, rational_t sec);
rational_t multiply(rational_t first, rational_t sec);
rational_t divide(rational_t first, rational_t sec);
rational_t absolute(rational_t first);
rational_t exp_rational(rational_t first, int16_t s);
float exp_real(uint16_t first, rational_t sec);
rational_t power(int base, int16_t exponent);

#endif
