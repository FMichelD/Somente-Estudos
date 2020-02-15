#include <stdio.h>
#include <stdlib.h>


#include "new.h"
#include "Object.h"
#include "MyString.h"

int main()
{
    void* a = new(String);
    void* aa = clone(a);
    void* b = new(String, "b");

    struct Class* c;
    struct String* sa;
    c = (struct Class*)a;
    sa = (struct String*)a;

    printf("sizeOf(a) == %lu\n", (unsigned long)sizeOf(a));
    if (differ(sa, c))
        puts("ok");

    if (differ(a, aa))
        puts("differ!");
    else
        puts("Equals!");

    if (a == aa)
        puts("Same, not a clone!");
    else if (!differ(a, aa)) {
        puts("Clone!");
    }

    delete(a);
    delete(aa);
    delete(b);

    return 0;
}
