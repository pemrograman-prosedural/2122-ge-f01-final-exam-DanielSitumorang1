#ifndef DORM_H
#define DORM_H

#include "student.h"

struct dorm_t {
    char name[60];
    unsigned short capacity;
    unsigned short residents;
    enum gender_t gender;
};

struct dorm_t create_dorm(const char *name, unsigned short capacity, enum gender_t gender);
void print_dorm_detail(struct dorm_t *dorms, int count);
void print_dorm(struct dorm_t *dorms, int count);
void assign_student(struct student_t *student, struct dorm_t *dorm);

#endif
