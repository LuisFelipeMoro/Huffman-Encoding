#include "PriorityQueue.h"

struct HuffmanNode *minimum(struct Heap *heap) {
    return heap->array[0];
}

struct HuffmanNode *extractMin(struct Heap *heap) {
    struct HuffmanNode **array = heap->array;
    if (heap->size < 1) {
        printf("error: heap underflow");
        return NULL;
    }
    int min = array[0];
    heap->size--;
    array[0] = array[heap->size];
    minHeapify(heap, 0);
    return min;
}

void decreaseMinHeapKey(struct Heap *heap, int i, struct HuffmanNode *node) {
    if (node->frequency > heap->array[i]) {
        printf("error: larger frequency while trying to decrease");
        return;
    }
    heap->array[i] = node;
    while (i > 0 && heap->array[((i-1)/2)]->frequency > heap->array[i]->frequency) {
        swapNode(heap->array[i], heap->array[((i-1)/2)]);
        i = ((i-1)/2);
    }
}

void insertMinHeap(struct Heap *heap, struct HuffmanNode *node) {
    heap->size++;
    heap->array[heap->size - 1] = node;
    decreaseMinHeapKey(heap, heap->size - 1, node);
}