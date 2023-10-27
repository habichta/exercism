#include "clock.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int get_hour(char text[]) {

  int hour_1 = 10 * (text[0] - '0');
  int hour_2 = text[1] - '0';
  return hour_1 + hour_2;
}
int get_minute(char text[]) {
  int min_1 = 10 * (text[3] - '0');
  int min_2 = text[4] - '0';
  return min_1 + min_2;
}

clock_t clock_create(int hour, int minute) {

  int overflowHours = minute / 60;
  int overflowMinutes = minute % 60;
  overflowHours = hour + overflowHours;
  overflowHours = overflowHours % 24;

  if (overflowMinutes < 0) {
    overflowMinutes = 60 + overflowMinutes;
    overflowHours--;
  }

  if (overflowHours < 0) {
    overflowHours = 24 + overflowHours;
  }

  char hourQuotient = '0' + overflowHours / 10;
  char hourRemainder = '0' + overflowHours % 10;

  char minuteQuotient = '0' + overflowMinutes / 10;
  char minuteRemainder = '0' + overflowMinutes % 10;

  char clockStr[MAX_STR_LEN];

  clockStr[0] = hourQuotient;
  clockStr[1] = hourRemainder;
  clockStr[2] = ':';
  clockStr[3] = minuteQuotient;
  clockStr[4] = minuteRemainder;
  clockStr[5] = '\0';

  clock_t clock;

  strcpy(clock.text, clockStr);

  return clock;
}
clock_t clock_add(clock_t clock, int minute_add) {

  int hour = get_hour(clock.text);
  int minute = get_minute(clock.text);

  minute = minute + minute_add;
  return clock_create(hour, minute);
}
clock_t clock_subtract(clock_t clock, int minute_subtract) {
  int hour = get_hour(clock.text);
  int minute = get_minute(clock.text);

  minute = minute - minute_subtract;
  return clock_create(hour, minute);
}
bool clock_is_equal(clock_t a, clock_t b) { return !strcmp(a.text, b.text); }
