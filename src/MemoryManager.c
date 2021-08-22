#include "MemoryManager.h"

typedef struct MemoryManagerCDT {
	char *nextAddress;
} MemoryManagerCDT;

MemoryManagerADT create
(void *const restrict memory, 
	void *const restrict managedMemory) 
{

	MemoryManagerADT memoryManager = (MemoryManagerADT) memory;

	memoryManager->nextAddress = managedMemory;

	return memoryManager;
}

void *alloc
(MemoryManagerADT const restrict manager, 
	const size_t alloc) 

{
	char *allocation = manager->next;

	manager->next += alloc;

	return (void *) allocation;
}
