#include "Object.h"

#include <stddef.h>

struct Object {
    unsigned count;
    struct Set * in;
};

static const size_t _Object = sizeof(struct Object);
const void * Object = & _Object;
