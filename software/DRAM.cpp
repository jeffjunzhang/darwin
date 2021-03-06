#include "DRAM.h"
#include <memory>

#include "tbb/scalable_allocator.h"
#include "tbb/tbb.h"

DRAM::DRAM()
	: size(4ull * 1024ull * 1024ull * 1024ull),
	referenceSize(0)
{

	buffer = (char*)scalable_aligned_malloc(size, 64);
}


DRAM::~DRAM()
{
    scalable_aligned_free(buffer);
}
