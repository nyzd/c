#include "string.h"
#include <stdio.h>

int main(void) {
    String *s = string_from_chars("Hello World");

    printf("%c", s->chars->array[0]);

    return 0;
}
