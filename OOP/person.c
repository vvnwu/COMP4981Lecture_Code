#include "person.h"
#include <stdlib.h>
#include <string.h>


struct Person *person_create(void)
{
    struct Person *this;
    
    this = calloc(1, sizeof(struct Person));

    return this;
}

void person_destroy(struct Person **pthis)
{
    free(*pthis);
    *pthis = NULL;
}

void person_init(struct Person *this, const char *first_name, const char *last_name)
{
    this->get_first_name = person_get_first_name;
    this->get_last_name = person_get_last_name;
    strcpy(this->first_name, first_name);
    strcpy(this->last_name, last_name);
}

const char *person_get_first_name(const struct Person *this)
{
    return this->first_name;
}

const char *person_get_last_name(const struct Person *this)
{
    return this->last_name;
}
