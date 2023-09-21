#include "rational_numbers.h"
#include <math.h>
#include <stdint.h>

int gcd_custom(int a, int b) {

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

rational_t power(int base, int16_t exponent) {
  int result = 1;

  int sign = exponent < 0 ? -1 : 1;

  for (int i = 0; i < exponent * sign; i++) {
    result *= base;
  }

  if (sign < 0) {
    rational_t newRational = {.numerator = 1, .denominator = result};
    return newRational;
  }

  else {
    rational_t newRational = {.numerator = result, .denominator = 1};
    return newRational;
  }
}

rational_t reduce(rational_t rational) {
  int numerator = rational.numerator;
  int denominator = rational.denominator;
  int gcd = gcd_custom(numerator, denominator);

  rational.numerator = numerator / gcd;
  rational.denominator = denominator / gcd;

  if (rational.denominator < 0) {
    rational.denominator *= -1;
    rational.numerator *= -1;
  }

  return rational;
}

rational_t multiply(rational_t first, rational_t sec) {

  int newNumerator = first.numerator * sec.numerator;

  int newDenominator = first.denominator * sec.denominator;

  rational_t newRational = {.numerator = newNumerator,
                            .denominator = newDenominator};

  newRational = reduce(newRational);
  return newRational;
}

rational_t absolute(rational_t first) {

  if (first.denominator < 0) {
    first.denominator = -first.denominator;
  }

  if (first.numerator < 0) {
    first.numerator = -first.numerator;
  }

  first = reduce(first);
  return first;
}

rational_t divide(rational_t first, rational_t sec) {

  int newNumerator = first.numerator * sec.denominator;

  int newDenominator = first.denominator * sec.numerator;

  rational_t newRational = {.numerator = newNumerator,
                            .denominator = newDenominator};

  if (newRational.denominator < 0) {
    newRational.denominator = -newRational.denominator;
    newRational.numerator = -newRational.numerator;
  }

  newRational = reduce(newRational);
  return newRational;
}

rational_t exp_rational(rational_t first, int16_t s) {

  rational_t numerator_power = power(first.numerator, s);
  rational_t denominator_power = power(first.denominator, s);

  rational_t newRational = divide(numerator_power, denominator_power);

  newRational = reduce(newRational);
  return newRational;
}
float exp_real(uint16_t first, rational_t sec) {

  double result = pow(first, (double)sec.numerator / (double)sec.denominator);

  return result;
}

rational_t add(rational_t first, rational_t sec) {

  int newNumerator =
      first.numerator * sec.denominator + sec.numerator * first.denominator;

  int newDenominator = first.denominator * sec.denominator;

  rational_t newRational = {.numerator = newNumerator,
                            .denominator = newDenominator};

  newRational = reduce(newRational);
  return newRational;
}

rational_t subtract(rational_t first, rational_t sec) {

  int newNumerator =
      first.numerator * sec.denominator - sec.numerator * first.denominator;

  int newDenominator = first.denominator * sec.denominator;

  rational_t newRational = {.numerator = newNumerator,
                            .denominator = newDenominator};

  newRational = reduce(newRational);
  return newRational;
}
