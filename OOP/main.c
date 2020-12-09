#include "person.h"
#include "student.h"
#include <stdio.h>
#include <stdlib.h>


static void print(struct Person *person);


int main(int argc, const char * argv[])
{
    struct Person *personA;
    struct Student *personB;

    personA = person_create();
    personB = student_create();
    person_init(personA, "D'Arcy", "Smith");
    student_init(personB, "Albert", "Wei", "A00000000");

    print(personA);
    print(personB);

    return EXIT_SUCCESS;
}


static void print(struct Person *person)
{
    const char *first;
    const char *last;

    first = person->get_first_name(person);
    last = person->get_last_name(person);

    printf("%s %s\n", first, last);
}
