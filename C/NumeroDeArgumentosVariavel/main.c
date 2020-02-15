#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int foo(int n, int m, ...);

int
main (int argc, char *argv[])
{
    int n = 10;
    int m = 15;
    int p = 20;
    //foo (n, m);
    foo(n, m);

    return EXIT_SUCCESS;
}

int foo (int n, int m, ...)
{
    va_list ap;
    int p;
    char *str;

    va_start (ap, m);
    p = va_arg (ap, int);
    n = m + p;
    printf ("%d.\n", n);
    va_end (ap);
    return 0;
}
