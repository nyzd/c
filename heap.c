#include "./heap.h"
#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

// [node1, node2, node3]
//    -------^
//    --------------^

IntHeap *new_heap(int root) {
  // TODO: use static initialization
  IntHeap *new_heap = malloc(sizeof(IntHeap));

  Array *nodes = new_array();

  array_push(nodes, root);

  new_heap->length += 1;
  new_heap->heap_size = 0;

  new_heap->nodes = nodes;

  return new_heap;
}

void push_node(IntHeap *heap, int value) {
  heap->length += 1;

  array_push(heap->nodes, value);
}

void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;

  *b = temp;
}

void max_heapify(IntHeap *heap, int i) {
  int left_node_index = 2 * i;
  int right_node_index = 2 * i + 1;

  int largest = 0;

  if (left_node_index <= heap->heap_size &&
      array_get(heap->nodes, left_node_index) > array_get(heap->nodes, i)) {

    largest = left_node_index;
  } else {
    largest = i;
  }

  if (right_node_index <= heap->heap_size &&
      array_get(heap->nodes, right_node_index) >
          array_get(heap->nodes, largest)) {

    largest = right_node_index;
  }

  if (largest != i) {
    swap(&heap->nodes->array[i], &heap->nodes->array[largest]);

    max_heapify(heap, largest);
  }
}

void build_max_heap(IntHeap *heap) {
  heap->heap_size = heap->length - 1;
  for (int i = (heap->length - 1) / 2; i >= 0; i--) {
    max_heapify(heap, i);
  }
}

void print_heap(IntHeap *heap) {
  printf("Heap [ ");

  for (int x = 0; x < heap->length; x++) {
    printf("%i, ", array_get(heap->nodes, x));
  }

  printf(" ]\n");
}
