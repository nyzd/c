#include <stdio.h>

// Prints all of the string (chars)
// expects pointer to the string
int print_str(char *str) {
  // The pointer is null :|
  // What am i goin to do with null pointer ?
  if (str == NULL)
    return 1;

  // create a new pointer, a copy from the original pointer
  char *pointer = str;

  do {
    // Print the current char (derefrence it)
    fprintf(stdout, "%c", *pointer);

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

  return 0;
}

