#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main ()
{
    void * s = new(Set);
    void * a = add(s, new(Object));
    void * b = add(s, new(Object));
    void * c = new(Object);
    void * d = add(s, new(Object));

    if (contains(s, a) && contains(s, b))
        puts("ok");

    if (contains(s, c))
        puts("contains!");
    else
        puts("Not contains!");

    if (differ(a, add(s, a)))
        puts("differ!");
    else
        puts("Not differ!");

    if (differ(a, add(s, d)))
        puts("differ!");
    else
        puts("Not differ!");

    if (contains(s, drop(s, b)))
        puts("drop!");

    delete(drop(s, b));
    delete(drop(s, c));

    return 0;
}
