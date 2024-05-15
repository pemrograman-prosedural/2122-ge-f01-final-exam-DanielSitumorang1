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

void print_dorm_detail(struct dorm_t *dorms, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s|%u|%u|%s\n",
dorms[i].name,
            dorms[i].capacity,
            dorms[i].residents,
            (dorms[i].gender == GENDER_MALE) ? "male" : "female");
    }
}

void print_dorm(struct dorm_t *dorms, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s|%s\n",
            dorms[i].name,
            (dorms[i].gender == GENDER_MALE) ? "male" : "female");
    }
}

void assign_student(struct student_t *student, struct dorm_t *dorm) {
    if (dorm->residents < dorm->capacity && dorm->gender == student->gender) {
        dorm->residents++;
        strcpy(student->dorm_name, dorm->name);
    }
}
