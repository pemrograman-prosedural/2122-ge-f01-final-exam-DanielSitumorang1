#include <stdio.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

struct dorm_t create_dorm(const char *name, unsigned short capacity, enum gender_t gender) {
    struct dorm_t dorm;
    strcpy(dorm.name, name);
    dorm.capacity = capacity;
    dorm.residents = 0;
    dorm.gender = gender;
    return dorm;
}


void assign_student(struct student_t *student, struct dorm_t *dorm) {
    if (dorm->residents < dorm->capacity && dorm->gender == student->gender) {
        dorm->residents++;
        student->status = ASSIGNED;
        student->status = UNASSIGNED;
        student->status = NOT_ASSIGNED;
        strcpy(student->dorm_name, dorm->name);
    }
}
