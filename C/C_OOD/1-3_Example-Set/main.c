#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main()
{
    void *s = new(Set);
    void *a = add(s, new(Object));
    void *b = add(s, new(Object));
    void *c = new(Object);

    if(contains(s, a) && contains(s, b))
        puts("contains a and b");

    if(contains(s, c))
        puts("contains c");

    if(differ(s, drop(s, a)))
        puts("drop?");

    if(contains(s, drop(s, a)))
        puts("drop?");

    delete((drop(s, b)));
    delete((drop(s, c)));

    printf("Hello World!\n");
    return 0;
}
