#include "armstrong_numbers.h"
#include "stdio.h"

int getNrDigits(int number) {

  int nrOfDigits = 0;

  if (number == 0) {

    return 1;
  } else {
    while (number > 0) {
      number /= 10;
      nrOfDigits++;
    }

    return nrOfDigits;
  }
}

int toPow(int base, int exponent) {

  int result = 1;

  for (int e = exponent; e > 0; e--) {
    result *= base;
  }

  return result;
}

bool is_armstrong_number(int candidate) {

  int targetNumber = candidate;
  int nrDigits = getNrDigits(candidate);
  int nrDigitPos = nrDigits - 1;

  int result = 0;

  while (nrDigitPos >= 0) {

    int digit = 0;
    int power = toPow(10, nrDigitPos);

    while (candidate >= power) {
      candidate -= power;
      digit++;
    }
    result += toPow(digit, nrDigits);
    nrDigitPos--;
  }

  return result == targetNumber;
}

// int main() {
//
//   bool an = is_armstrong_number(154);
//
//   return 0;
// }
