#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

typedef struct Student_ {
    char Surname[100];
    char init[10];
    int group;
    int grades[5];
} Student;

int readStudent( FILE* fp,Student* student);
int writeStudent(FILE* fp,const Student* student);

#endif // STUDENT_H
