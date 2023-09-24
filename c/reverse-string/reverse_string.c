#include "reverse_string.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char *reverse(const char *value) {
  size_t len = strlen(value);
  char *reversed = (char *)malloc((len + 1) * sizeof(char));

  size_t j = 0;

  for (int i = len - 1; i >= 0; i--) {
    reversed[j] = value[i];
    j++;
  }

  reversed[len] = '\0';

  return reversed;
}
