#include "Heap.h"

struct HuffmanNode *minimum(struct Heap *heap);

struct HuffmanNode *extractMin(struct Heap *heap);

void decreaseMinHeapKey(struct Heap *heap, struct HuffmanNode *node);

void insertMinHeap(struct Heap *heap, struct HuffmanNode *node);