
#define Uint unsigned int

typedef struct array_type {
  // The Allocated memory size
  // starts from 1
  Uint capacity;
  // The length of array
  // starts from 0
  Uint length;

  // The pointer to start of array
  Uint *array;
} Array;

Array *new_array();
int array_push(Array *array, int item);
Uint *array_get(Array *array, Uint index);
Array *array_copy(Array *array);
