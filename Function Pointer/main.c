#include <stdio.h>


static void call(void (*func)(const char *));
static void foo(const char *msg);
static void bar(const char *msg);


int main(int argc, const char * argv[])
{
    call(foo);
    call(bar);

    return 0;
}


static void call(void (*func)(const char *))
{
    func("Hello, World!");
}


static void foo(const char *msg)
{
    printf("foo says %s\n", msg);
}


static void bar(const char *msg)
{
    printf("bar says %s\n", msg);
}
