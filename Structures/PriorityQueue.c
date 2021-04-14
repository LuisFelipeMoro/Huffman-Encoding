#include "PriorityQueue.h"

struct HuffmanNode *extractMin(struct Heap *heap) {
     struct HuffmanNode *temp = heap->array[0];
    if (heap->size < 1) {
        printf("error: heap underflow");
        return NULL;
    }
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}


void decreaseMinHeapKey(struct Heap *heap, int i, struct HuffmanNode *node) {
    if (node->frequency > heap->array[i]) {
        printf("error: larger frequency while trying to decrease");
        return;
    }
     while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void insertMinHeap(struct Heap *heap, struct HuffmanNode *node) {
    ++heap->size;
    decreaseMinHeapKey(heap, heap->size - 1, node);
}