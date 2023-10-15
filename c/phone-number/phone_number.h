#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H

enum PhoneState { COUNTRY_CODE, NUMBER, ILLEGAL_STATE };

char *phone_number_clean(const char *input);

#endif
