#ifndef ARRAY_H_

#define ARRAY_H_
#define Uint unsigned int

typedef struct array_type {
  // The Allocated memory size
  // starts from 1
  Uint capacity;
  // The length of array
  // starts from 0
  Uint length;

  // The pointer to start of array
  int *array;
} Array;

Array *new_array();
int array_push(Array *array, int item);
int array_get(Array *array, Uint index);
Array *array_copy(Array *array);

#endif // !ARRAY_H_
