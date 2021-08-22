#include "MemoryManager.h"

typedef struct MemoryManagerCDT {

	char *nextAddress;

} MemoryManagerCDT;

MemoryManagerADT createManager (void *const restrict memoryForManager, void *const restrict managedMemory) {

	MemoryManagerADT memoryManager = (MemoryManagerADT) memoryForManager;
	memoryManager->nextAddress = managedMemory;

	return memoryManager;
}

void *allocMemory (MemoryManagerADT const restrict mem, const size_t memoryToAllocate) {

	char *allocation = mem->nextAddress;
	mem->nextAddress += memoryToAllocate;

	return (void *) allocation;
}
