#include "./dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// Creates the new array and returns the pointer
Array *new_array() {
  // Allocate the memory
  Array *new_a = (Array *)malloc(sizeof(Array));

  new_a->capacity = 1;
  new_a->length = 0;

  // Allocate array for just one item
  new_a->array = (int *)malloc(1);

  return new_a;
}

// This is almost O(1)
int array_push(Array *array, int item) {
  if (array->capacity == array->length) {
    // We need to reallocate
    // FIX: Is this OK? im so noob at c
    int *new_alloc =
        (int *)realloc(array->array, sizeof(int) * array->capacity * 2);

    // if we can't allocate
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

int array_get(Array *array, Uint index) {
  if (index >= array->length) {
    // Index out of bound
    printf("Index out of bound %i", index);
    exit(1);
  }

  return array->array[index];
}

// copy array to a new array
//
// new_a[n] = a[n]
// n <= a.length
Array *array_copy(Array *array) {
  Array *clone_array = new_array();
  Uint i = 0;

  do {
    array_push(clone_array, array_get(array, i));

    i += 1;
  } while (array->length != i);

  return clone_array;
}
