#include "./dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// Creates the new array and returns the pointer
Array *new_array() {
  // Allocate the memory
  Array *new_a = malloc(sizeof(Array));

  new_a->capacity = 1;
  new_a->length = 0;

  // Allocate array for just one item
  new_a->array = malloc(1);

  return new_a;
}

// This is almost O(1)
int array_push(Array *array, int item) {
  if (array->capacity == array->length) {
    // We need to reallocate
    Uint *new_alloc = realloc(array->array, array->capacity * 2);

    // if we cant allocate
    if (new_alloc == NULL) {
      return 1;
    }

    // Multiply capacity with
    // this is the way the dynamic array works
    array->capacity *= 2;

    // New pointer
    array->array = new_alloc;
  }

  // Now we insert
  // We need to insert to the
  array->array[array->length] = item;

  array->length += 1;

  return 0;
}

Uint *array_get(Array *array, Uint index) {
  if (index >= array->length) {
    // Index out of bound
    printf("Index out of bound %i", index);
    exit(1);
  }

  return &array->array[index];
}

// copy array to a new array
//
// new_a[n] = a[n]
// n <= a.length
Array *array_copy(Array *array) {
  Array *clone_array = new_array();
  Uint i = 0;

  do {
    array_push(clone_array, *array_get(array, i));

    i += 1;
  } while (array->length != i);

  return clone_array;
}

int main(void) {
  Array *a1 = new_array();

  array_push(a1, 10);
  array_push(a1, 256);
  array_push(a1, 'c');

  Array *a1_clone = array_copy(a1);
  Uint *first_item = array_get(a1_clone, 1);

  printf("%i %i, %i, a1: %p a1_clone: %p", a1->length, a1->capacity,
         *first_item, a1, a1_clone);

  return 0;
}
