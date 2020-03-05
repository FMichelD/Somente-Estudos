#include <stdio.h>
#include <stdlib.h>


#include "new.h"
#include "Object.h"
#include "MyString.h"

int main()
{
    void* a = new(String, "Teste de tamanho da string");
    void* aa = clone(a);
    void* b = new(String, "b");
    void* e = new(String);

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

    printf("a: %s\n", getText(a));
    printf("e: %s\n", getText(e));
    printf("b: %s\n", getText(b));

    delete(a);
    delete(aa);
    delete(b);

    return 0;
}
