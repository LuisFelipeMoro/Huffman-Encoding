#include "Heap.h"

struct HuffmanNode *extractMin(struct Heap *heap);

void decreaseMinHeapKey(struct Heap *heap, int i, struct HuffmanNode *node);

void insertMinHeap(struct Heap *heap, struct HuffmanNode *node);