#ifndef Array
    #include "dynamic_array.h"
#endif // !Array

typedef struct string_type {
  Array *chars;
} String;

String *new_string();
String *from_chars(char *chars);
