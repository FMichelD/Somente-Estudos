#include "new.h"
#include "Class.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

void * new (const void* _class, ...)
{
    const struct Class* class = _class;
    void* p = calloc(1, class->size);
    assert(p);
    *(const struct Class**)p = class;

    if(class->ctor)
    {
        va_list ap = NULL;
        va_start(ap, _class);
        class->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}
//------------------------------------------------------------------------------

void delete(void* self)
{
    const struct Class** cp = self;

    if(self && *cp && (*cp)->dtor)
    {
        self = (*cp)->dtor(self);
    }

    free(self);
}
//-----------------------------------------------------------------------------
