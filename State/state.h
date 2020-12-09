#ifndef STATE_H
#define STATE_H


#include <stddef.h>


struct State;

struct State *state_crate(size_t value);
void state_destroy(struct State **state);
size_t state_set_value(struct State *state, size_t new_value);
size_t state_get_value(const struct State *state);


#endif
