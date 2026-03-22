#include "MemoryManager.h"

typedef struct MemoryManagerCDT {
	char *nextAddress;
} MemoryManagerCDT;

MemoryManagerADT createMemoryManager(void *restrict memoryForMemoryManager, void *restrict managedMemory) {
	((MemoryManagerADT) memoryForMemoryManager)->nextAddress = managedMemory;
	return memoryForMemoryManager;
}

void *allocMemory(MemoryManagerADT restrict memoryManager, size_t memoryToAllocate) {
	char *allocation = memoryManager->nextAddress;

	memoryManager->nextAddress += memoryToAllocate;

	return (void *) allocation;
}
