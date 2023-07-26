#ifndef STRING_H_

#define STRING_H_

#include "dynamic_array.h"

typedef struct string_type {
  Array *chars;
} String;

String *new_string();
String *string_from_chars(char *chars);
void push_char(String *string, char c);

#endif // !STRING_H_
