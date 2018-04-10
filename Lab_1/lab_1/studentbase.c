#include "studentbase.h"
#include <stdlib.h>

int init(StudentBase *base, size_t capacity){
    base->base_ = (Student*)malloc(sizeof(Student) * capacity);
    if(base == NULL)
        return -1;
    base->size_ = 0;
    base->capacity_ = capacity;
    return 0;
}

int addStudent(StudentBase *base, const Student *student){
    if(base->size_ >= base->capacity_)
        return -1;
    base->base_[base->size_] = *student;
    base->size_ += 1;
    return 0;
}

int writeBase(FILE *fp, const StudentBase *base){
    size_t i;
    for (i = 0; i < base->size_; ++i) {
        writeStudent(fp,&base->base_[i]);
    }
    return 0;
}

int readBase(FILE *fp,StudentBase *base){
    Student student;
    init(base,100);
    while(readStudent(fp,&student) == 0){
        if(addStudent(base,&student) != 0){
            printf("Error: error while reading data!\n");
            return -1;}
    }
    return 0;
}
