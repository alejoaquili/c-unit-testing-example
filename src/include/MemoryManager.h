#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <stdlib.h>

typedef struct MemoryManagerCDT *MemoryManagerADT;

MemoryManagerADT createMemoryManager(void *restrict memoryForMemoryManager, void *restrict managedMemory);

void *allocMemory(MemoryManagerADT restrict memoryManager, size_t memoryToAllocate);

#endif
