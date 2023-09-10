#include "hamming.h"
#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// static inline uint64_t rdtsc() {
//   uint32_t lo, hi;
//   asm volatile("rdtsc"              // Read timestamp counter
//                : "=a"(lo), "=d"(hi) // Output registers
//                :                    // No input registers
//                : "%ebx", "%ecx");   // Clobbered registers
//   return ((uint64_t)hi << 32) | lo;
// }

int compute2(const char *lhs, const char *rhs) {
  size_t lhsLen = strlen(lhs);
  size_t rhsLen = strlen(rhs);

  if (lhsLen != rhsLen) {
    return -1;
  }
  int hammingDistance = 0;
  for (size_t p = 0; p < lhsLen; p++) {

    if (lhs[p] != rhs[p]) {
      hammingDistance++;
    }
  }

  return hammingDistance;
}

int compute(const char *lhs, const char *rhs) {
  if (!lhs || !rhs)

    return -1;

  int distance = 0;
  for (; *lhs && *rhs; lhs++, rhs++) {
    if (*lhs != *rhs)
      distance++;
  }
  return (*lhs || *rhs) ? -1 : distance;
}

// int main() {
//   uint64_t start = rdtsc();
//   compute("ABCDEFGS", "ABCDEFF");
//   uint64_t end = rdtsc();
//   uint64_t start2 = rdtsc();
//   compute2("ABCDEFGS", "ABCDEFF");
//   uint64_t end2 = rdtsc();
//
//   printf("copute 1 %lu cycles, compute 2 %lu cycles", end - start,
//          end2 - start2);
//
//   return 0;
// }
