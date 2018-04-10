#ifndef STUDENTBASE_H
#define STUDENTBASE_H

#include "student.h"
#include<stdio.h>

typedef struct StudentBase_ {
    Student* base_;
    size_t size_;
    size_t capacity_;
} StudentBase;

int init(StudentBase *base,size_t capacity);
int addStudent(StudentBase *base,const Student *student);
int writeBase(FILE *fp,const StudentBase *base);
int readBase(FILE *fp,StudentBase *base);

#endif // STUDENTBASE_H
