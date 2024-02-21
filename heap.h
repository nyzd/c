#ifndef HEAP_H_

#define HEAP_H_

#include "dynamic_array.h"

typedef struct IntHeap {
  int length;
  int heap_size;
  Array *nodes;
} IntHeap;

IntHeap *new_heap(int root);

void print_heap(IntHeap *heap);
void push_node(IntHeap *heap, int value);
void build_max_heap(IntHeap *heap);

#endif // !HEAP_H_
