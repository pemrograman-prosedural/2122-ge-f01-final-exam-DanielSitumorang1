// 12S23028 - Daniel Situmorang
// 12S23007 - Joy Valeda Silalahi

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv){
    struct student_t *students = malloc(200 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(200 * sizeof(struct dorm_t));
    char data[200];
    int student_count = 0, dorm_count = 0;

    while (1) {
        fflush(stdin);
        if (fgets(data, sizeof(data), stdin) == NULL) {
            break;
        }
        
        data[strcspn(data, "\n")] = '\0';

        if (strcmp(data, "---") == 0) {
            break;
        }

        if (strncmp(data, "student-add#", 12) == 0) {
            char *token = strtok(data, "#");
            token = strtok(NULL, "#");
            char nim[12];
            strcpy(nim, token);
            token = strtok(NULL, "#");
            char name[40];
            strcpy(name, token);
            token = strtok(NULL, "#");
            char year[5];
            strcpy(year, token);
            token = strtok(NULL, "#");
            enum gender_t gender = (strcmp(token, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;

            students[student_count++] = create_student(nim, name, year, gender);
        } else if (strncmp(data, "dorm-add#", 9) == 0) {
            char *token = strtok(data, "#");
            token = strtok(NULL, "#");
            char dname[60];
            strcpy(dname, token);
            token = strtok(NULL, "#");
            unsigned short capacity = (unsigned short)atoi(token);
            token = strtok(NULL, "#");
            enum gender_t gender = (strcmp(token, "male") == 0) ? GENDER_MALE : GENDER_FEMALE;

            dorms[dorm_count++] = create_dorm(dname, capacity, gender);
        } else if (strncmp(data, "assign-student#", 15) == 0) {
            char *token = strtok(data, "#");
            token = strtok(NULL, "#");
            char nim[12];
            strcpy(nim, token);
            token = strtok(NULL, "#");
            char dname[60];
            strcpy(dname, token);

            int student_index = -1, dorm_index = -1;
            for (int i = 0; i < student_count; ++i) {
                if (strcmp(students[i].nim, nim) == 0) {
                    student_index = i;
                    break;
                }
            }
            for (int i = 0; i < dorm_count; ++i) {
                if (strcmp(dorms[i].name, dname) == 0) {
                    dorm_index = i;
                    break;
                }
            }
            if (student_index != -1 && dorm_index != -1) {
                assign_student(&students[student_index], &dorms[dorm_index]);
            }
        } else if (strncmp(data, "student-leave#", 14) == 0) {
            char *token = strtok(data, "#");
            token = strtok(NULL, "#");
            char nim[12];
            strcpy(nim, token);

            for (int i = 0; i < student_count; ++i) {
                if (strcmp(students[i].nim, nim) == 0) {
                    students[i].status = LEFT;
                    strcpy(students[i].dorm_name, "left");
                    break;
                }
            }
        } else if (strcmp(data, "student-print-all-detail") == 0) {
            print_student_detail(students, student_count);
        } else if (strcmp(data, "student-print-all") == 0) {
            print_student(students, student_count);
        }
    }

    free(students);
    free(dorms);
    return 0;
}
