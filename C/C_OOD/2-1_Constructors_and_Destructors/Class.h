#ifndef CLASS_H
#define CLASS_H

#include <stddef.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void* (*ctor) (void* self, va_list* ap);
    void* (*dtor) (void* self);
    void* (*clone) (const void* self);
    int (*differ) (const void* sefl, const void* b);
    size_t (*object_size) (const void* self);
};

#endif // CLASS_H
