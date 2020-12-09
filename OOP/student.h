#ifndef student_h
#define student_h


#include "person.h"


struct Student
{
    struct Person super;
    char student_number[10];
    const char *(*get_student_number)(const struct Student *);
};


struct Student *student_create(void);
void student_destroy(struct Student **pthis);
void student_init(struct Student *this, const char *first_name, const char *last_name, const char *student_number);
const char *student_get_student_number(const struct Student *this);
const char *student_get_last_name(const struct Student *this);


#endif
