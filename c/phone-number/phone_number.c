#include "phone_number.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *phone_number_clean(const char *input) {
  size_t strLen = strlen(input);
  enum PhoneState currentState = COUNTRY_CODE;

  char *phoneNumber = malloc(11 * sizeof(char));
  phoneNumber[10] = '\0';
  char *currentPointer = phoneNumber;

  size_t phoneNrCount = 0;

  for (size_t i = 0; i < strLen; i++) {

    char c = input[i];

    if (isdigit(c) || (c == '+' && currentState == COUNTRY_CODE)) {

      switch (currentState) {

      case COUNTRY_CODE:
        if (c == '+' && input[i + 1] == '1') {
          currentState = NUMBER;
          i++;

        } else if (c == '1') {
          currentState = NUMBER;

        } else if (isdigit(c)) {
          currentState = NUMBER;
          *currentPointer = c;
          currentPointer++;
          phoneNrCount++;

        } else {
          currentState = ILLEGAL_STATE;
        }
        break;

      case NUMBER:
        if (phoneNrCount < 10) {
          *currentPointer = c;
          currentPointer++;
          phoneNrCount++;
        } else {
          currentState = ILLEGAL_STATE;
        }
        break;

      case ILLEGAL_STATE:
        break;
      }

    } else if (c == ' ' || c == '-' || c == '(' || c == ')' || c == '.') {
      continue;

    } else {
      currentState = ILLEGAL_STATE;
    }
  }

  if (phoneNrCount != 10) {
    currentState = ILLEGAL_STATE;
  }

  if (phoneNumber[0] - '0' < 2 || phoneNumber[3] - '0' < 2) {
    currentState = ILLEGAL_STATE;
  }

  if (currentState == ILLEGAL_STATE) {
    currentPointer = phoneNumber;
    for (int i = 0; i < 10; i++) {
      *currentPointer = '0';
      currentPointer++;
    }
  }

  return phoneNumber;
}
