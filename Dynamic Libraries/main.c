#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <dc/dlfcn.h>


int main(int argc, const char * argv[])
{
    void *handle;
    size_t (*func)(const char *);
    size_t value;
    
    handle = dc_dlopen(argv[1], RTLD_LOCAL | RTLD_LAZY);
    func = dc_dlsym(handle, "foo");
    value = func(argv[2]);
    printf("%zu\n", value);
    dc_dlclose(handle);
    
    return EXIT_SUCCESS;
}
