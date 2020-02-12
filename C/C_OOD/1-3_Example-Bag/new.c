#include "new.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

void * new (const void * type, ...)
{	const size_t size = * (const size_t *) type;
    void * p = calloc(1, size);

    assert(p);
    return p;
}
//------------------------------------------------------------------------------

void delete(void* _item)
{
    free(_item);
}
//-----------------------------------------------------------------------------
