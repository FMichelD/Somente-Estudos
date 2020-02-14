#ifndef OBJECT_H
#define OBJECT_H

#include <stddef.h>

extern const void * Object;

void* clone (const void * self);
int differ(const void* self, const void* b);
size_t sizeOf(const void* self);

#endif // OBJECT_H
