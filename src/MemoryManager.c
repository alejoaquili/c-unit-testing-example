#include "MemoryManager.h"

typedef struct MemoryManagerCDT {
	char *nextAddress;
} MemoryManagerCDT;

MemoryManagerADT create
(void *const restrict memoryForMemoryManager, 
	void *const restrict managedMemory) 
{

	MemoryManagerADT memoryManager = (MemoryManagerADT) memoryForMemoryManager;
	memoryManager->nextAddress = managedMemory;

	return memoryManager;
}

void *alloc
(MemoryManagerADT const restrict memoryManager, const size_t memoryToAllocate) 

{
	char *allocation = memoryManager->nextAddress;

	memoryManager->nextAddress += memoryToAllocate;

	return (void *) allocation;
}
