#include <stdio.h>
#include <string.h>
#include "student.h"

struct student_t create_student(const char *nim, const char *name, const char *year, enum gender_t gender) {
    struct student_t student;
    strcpy(student.nim, nim);
    strcpy(student.name, name);
    strcpy(student.year, year);
    student.gender = gender;
    return student;
}

void print_student_detail(struct student_t *students, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s|%s|%s|%s|%s\n",students[i].nim,students[i].name,students[i].year,(students[i].gender == GENDER_MALE) ? "male" : "female",
            (students[i].status == LEFT) ? "left" : students[i].dorm_name);
    }
}

void print_student(struct student_t *students, int count) {
    for (int i = 0; i < count; ++i) {
        printf("%s|%s|%s|%s\n",students[i].nim,students[i].name,students[i].year,(students[i].gender == GENDER_MALE) ? "male" : "female");
    }
}
