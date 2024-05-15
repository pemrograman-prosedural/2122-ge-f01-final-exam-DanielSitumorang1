#ifndef STUDENT_H
#define STUDENT_H

enum gender_t {
    GENDER_MALE,
    GENDER_FEMALE
};

enum status_t {
    NOT_ASSIGNED,
    UNASSIGNED,
    ASSIGNED,
    LEFT
};

struct student_t {
    char nim[100];
    char name[100];
    char year[25];
    enum gender_t gender;
    enum status_t status;
    char dorm_name[60];
};

struct student_t create_student(const char *nim, const char *name, const char *year, enum gender_t gender);
void print_student_detail(struct student_t *students, int count);
void print_student(struct student_t *students, int count);

#endif
