#include <stdio.h>
#include <stdlib.h>
#include "./string.h"

String *new_string() {
  String *new_str = malloc(sizeof(String));

  new_str->chars = new_array();

  return new_str;
}

void push_char(String *string, char c) { array_push(string->chars, c); }

String *string_from_chars(char *chars) {
  String *new_str = new_string();

  // The pointer is null :|
  // What am i goin to do with null pointer ?
  if (chars == NULL)
    exit(1);

  // create a new pointer, a copy from the original pointer
  char *pointer = chars;

  do {
    // Print the current char (derefrence it)
    push_char(new_str, *pointer);

    // Increment pointer (next char)
    pointer++;
  }

  // if the current char is not equal to 0
  // continue
  //
  // When we create a string in c, it will allocate the size of
  // the string + 1, and it will put 0 at the end of the string
  // so the developers can determine the end of the string
  while (*pointer != 0);

  push_char(new_str, '\0');

  return new_str;
}

