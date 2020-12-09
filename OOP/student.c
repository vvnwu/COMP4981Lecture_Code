#include "student.h"
#include <stdlib.h>
#include <string.h>


struct Student *student_create(void)
{
    struct Student *this;
    
    this = calloc(1, sizeof(struct Student));

    return this;
}

void student_destroy(struct Student **pthis)
{
    free(*pthis);
    *pthis = NULL;
}

void student_init(struct Student *this,
                  const char *first_name,
                  const char *last_name,
                  const char *student_number)
{
    person_init(&this->super, first_name, last_name);
    this->get_student_number = student_get_student_number;
    this->super.get_last_name = student_get_last_name;
    strcpy(this->student_number, student_number);
}

const char *student_get_student_number(const struct Student *this)
{
    return this->student_number;
}

const char *student_get_last_name(const struct Student *this)
{
    return "XYZ";
}
