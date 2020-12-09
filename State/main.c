#include "state.h"
#include <stdio.h>
#include <string.h>


static void func(const char *str, struct State *state);


int main(int argc, const char * argv[])
{
    struct State *state;
    size_t length;
    
    state = state_crate(0);
    printf("%p\n", (void *)state);

    length = strlen(argv[0]);
    
    for(int i = 0; i < length; i++)
    {
        func(argv[0], state);
    }
    
    state_destroy(&state);
    printf("%p\n", (void *)state);
    
    // https://stackoverflow.com/questions/40776233/how-do-i-get-rid-of-the-unused-parameter-warning-in-c-with-gcc-4-8-4-wunused-p/40776275
    (void)argc;
    
    return 0;
}

static void func(const char *str, struct State *state)
{
    size_t index;
    
    index = state_get_value(state);
    printf("%zu = %c\n", index, str[index]);
    state_set_value(state, index + 1);
}
