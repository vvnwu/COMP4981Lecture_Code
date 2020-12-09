#ifndef shape_h
#define shape_h


struct Person
{
    char first_name[100];
    char last_name[100];
    const char *(*get_first_name)(const struct Person *);
    const char *(*get_last_name)(const struct Person *);
};


struct Person *person_create(void);
void person_destroy(struct Person **pthis);
void person_init(struct Person *this, const char *first_name, const char *last_name);
const char *person_get_first_name(const struct Person *this);
const char *person_get_last_name(const struct Person *this);


#endif
