#include "isogram.h"
#include "stdio.h"
#include "string.h"
#include <ctype.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
  uint32_t lo, hi;
  asm volatile("rdtsc"              // Read timestamp counter
               : "=a"(lo), "=d"(hi) // Output registers
               :                    // No input registers
               : "%ebx", "%ecx");   // Clobbered registers
  return ((uint64_t)hi << 32) | lo;
}

bool is_isogram(const char *word) {

  if (word == NULL) {
    return false;
  }

  size_t len = strlen(word), i, j;
  for (i = 0; i + 1 < len; i++) {

    for (j = i + 1; j < len; j++) {
      if (isalpha(word[i]) && isalpha(word[j]) &&
          (tolower(word[i]) == tolower(word[j]))) {
        return false;
      }
    }
  }

  return true;
}

int main() {

  char str[] = "He-l-o";

  uint64_t start, end;
  start = rdtsc();

  bool t = is_isogram(str);

  end = rdtsc();
  printf("CPU cycles elapsed: %lu\n", end - start);
  return 0;
}
