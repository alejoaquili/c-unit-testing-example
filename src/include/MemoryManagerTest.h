#ifndef MEMORY_MANAGER_TEST
#define MEMORY_MANAGER_TEST

#include "CuTest.h"

typedef void (*Test)(CuTest *const cuTest);

CuSuite *getMemoryManagerTestSuite(void);

#endif
