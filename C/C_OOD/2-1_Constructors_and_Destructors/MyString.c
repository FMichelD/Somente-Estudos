#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "MyString.h"
#include "new.h"
#include "Class.h"

struct String {
    const void * class;	/* must be first */
    char * text;
};
//------------------------------------------------------------------------------

static void * String_ctor (void* _self, va_list* app)
{
    struct String* self = _self;
    const char* text = va_arg(*app, const char*);

    self->text = malloc(strlen(text) + 1);
    assert(self->text);
    strcpy(self->text, text);
    return self;
}
//------------------------------------------------------------------------------

static void * String_dtor (void * _self)
{
    struct String * self = _self;

    free(self -> text);
    self->text = 0;
    return self;
}
//------------------------------------------------------------------------------

static void * String_clone (const void * _self)
{
    const struct String * self = _self;
    return new(String, self->text);
}
//------------------------------------------------------------------------------

static int String_differ (const void * _self, const void * _b)
{
    const struct String* self = _self;
    const struct String* b = _b;

    if (self == b)
        return 0;
    if (! b || b->class != String)
        return 1;
    return strcmp(self -> text, b -> text);
}
//------------------------------------------------------------------------------

static size_t String_size(const void* _self)
{
    const struct String* self = _self;

    return  strlen(self->text) + sizeof(self) + 1;
}
//------------------------------------------------------------------------------

static const struct Class _String = {
    sizeof(struct String),
    String_ctor,
    String_dtor,
    String_clone,
    String_differ,
    String_size
};

const void* String = &_String;
