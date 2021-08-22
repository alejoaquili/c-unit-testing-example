#include "MemoryManager.h"

typedef struct MManagerCDT {
	char *nextA;
} MemoryManagerCDT;

MemoryManagerADT create
(void *const restrict memory, 
	void *const restrict managedMemory) 
{

	MemoryManagerADT manager = (MemoryManagerADT) memory;

	manager->nextA = managedMemory;

	return manager;

}

void *alloc
(MemoryManagerADT const restrict manager, const size_t alloc) 

{
	char *allocation = 
	manager->nextA;
	
	manager->nextA += alloc;

	return (void *) allocation;
}
