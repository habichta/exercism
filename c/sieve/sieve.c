#include "sieve.h"
#include <math.h>
#include <stdio.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {

  int size = limit - 1;
  int numberArray[size];

  for (int i = 0; i < size; i++) {
    numberArray[i] = 1;
  }

  uint32_t primeCount = 0;
  uint32_t *primes_ptr = primes;

  for (uint32_t i = 2; i <= limit; i++) {

    if (numberArray[i - 2] == 1 && primeCount < max_primes) {
      primeCount++;
      *primes_ptr = i;
      primes_ptr++;
      uint32_t multiple = 2;
      uint32_t nextNumber = multiple * i;
      while (nextNumber <= limit) {
        numberArray[nextNumber - 2] = 0;
        multiple++;
        nextNumber = multiple * i;
      }
    }
  }

  return primeCount;
}
/* #include "sieve.h" */
/* #include <stdbool.h> */
/* #include <string.h> */
/* uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) { */
/*   bool is_prime[limit + 1]; */
/*   memset(is_prime, true, limit + 1); */
/*   uint32_t count = 0; */
/*   for (uint32_t i = 2; i < limit + 1 && count < max_primes; i++) { */
/*     if (is_prime[i]) { */
/*       for (uint32_t j = 2 * i; j < limit + 1; j += i) { */
/*         is_prime[j] = false; */
/*       } */
/*       *(primes + count) = i; */
/*       count++; */
/*     } */
/*   } */
/*   return count; */
/* } */

/* #ifndef SIEVE_H */
/* #define SIEVE_H */

/* #include <stddef.h> */
/* #include <stdint.h> */

/* /// Calculate at most `max_primes` prime numbers in the interval [2,limit] */
/* /// using the Sieve of Eratosthenes and store the prime numbers in `primes`
 */
/* /// in increasing order. */
/* /// The function returns the number of calculate primes. */
/* uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes); */

/* #endif */
