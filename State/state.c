#include "state.h"
#include <stdlib.h>

struct State
{
    size_t value;
};

struct State *state_crate(size_t value)
{
    struct State *state;
    
    state = malloc(sizeof(struct State));
    state->value = value;
    
    return state;
}

void state_destroy(struct State **state)
{
    free(*state);
    *state = NULL;
}

size_t state_set_value(struct State *state, size_t new_value)
{
    int old_value;
    
    old_value = state->value;
    state->value = new_value;
    
    return old_value;
}

size_t state_get_value(const struct State *state)
{
    return state->value;
}
