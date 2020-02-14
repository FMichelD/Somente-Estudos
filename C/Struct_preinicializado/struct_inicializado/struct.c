#include "struct.h"

struct Structure{
    int value_1;
    int value_2;
    char* text;
};

static const struct Structure stInitialied = {
    1,
    25,
    "Test"
};

const void* Structure = &stInitialied;
