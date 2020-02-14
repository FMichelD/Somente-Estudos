#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "MyString.h"

int main()
{
    void *a = new(String, "a");
    void *aa = clone(a);
    void *b = new(String, "b");

    String sa;

    printf("sizeOf(a) == %lu\n", (unsigned long)sizeOf(a));
    if (differ(a, b))
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
