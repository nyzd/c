#include "heap.h"
#include <stdio.h>

int main(void) {

  // 5 is Root node
  IntHeap *heap = new_heap(5);

  push_node(heap, 100);
  push_node(heap, 69);
  push_node(heap, 410);
  push_node(heap, 210);
  push_node(heap, 123);
  push_node(heap, 22);
  push_node(heap, 99);
  push_node(heap, 310);
  push_node(heap, 212);
  push_node(heap, 1000);
  push_node(heap, 4);

  printf("Before: ");
  print_heap(heap);

  printf("After: ");
  build_max_heap(heap);
  print_heap(heap);

  return 0;
}
