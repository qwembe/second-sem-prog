#include "student.h"

int readStudent(FILE *fp, Student *student){
    if(fscanf(fp,"%s %s %d %d %d %d %d %d",student->Surname,student->init,&student->group,&student->grades[0],&student->grades[1],&student->grades[2],&student->grades[3],&student->grades[4]) == 8)
        return 0;
    else
        return -1;
}

int writeStudent(FILE *fp, const Student *student){
    fprintf(fp,"%10s %5s %d %d %d %d %d %d\n",student->Surname,student->init,student->group,student->grades[0],student->grades[1],student->grades[2],student->grades[3],student->grades[4]);
    return 0;
}
