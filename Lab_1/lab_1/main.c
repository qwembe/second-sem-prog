#include <stdio.h>
#include <stdlib.h>

#include "studentbase.h"

void menu();
void load(StudentBase* base);
void save(StudentBase* base);
void add( StudentBase* base);
void rem( StudentBase *base);
void showAll(const StudentBase *base);
void showAG( const StudentBase *base);
int cmp(const void *x1,const void *x2);

int main()
{
    StudentBase base;
    init(&base,100);

    int menu_option;
    while(1){
        qsort(base.base_,base.size_,sizeof(Student),cmp);
        menu();
        scanf("%i",&menu_option);
	fflush(stdin);

        switch (menu_option) {
        case 1:
            load(&base);
            break;
        case 2:
            save(&base);
            break;
        case 3:
            add( &base);
            break;
        case 4:
            showAll(&base);
            break;
        case 5:
            showAG(&base);
            break;
        case 6:
            rem(&base);
            break;
        case 7:
            free(base.base_);
            exit(EXIT_SUCCESS);
        default:
            printf("Error:Incorrect command\n");
        }

    }
    return 0;
}

int cmp(const void* x1,const void *x2){
    Student y1 = *(Student*)x1;
    Student y2 = *(Student*)x2;
    return y1.group - y2.group;
}

void menu(){
    printf("");
    printf("---------------------------------------------\n");
    printf("Lab1. Vaigachev A., 6382\n");
    printf("---------------------------------------------\n");
    printf("1. Load base from file\n");
    printf("2. Save base to file\n");
    printf("3. Add student\n");
    printf("4. Show all students\n");
    printf("5. Show students with average grades >= 4.0\n");
    printf("6. Remove student from all\n");
    printf("7. Exit\n");
    printf("---------------------------------------------\n");
    printf("\n\n");
}

void load(StudentBase* base){
    FILE* fp;
    fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("Error: File not find!\n");
        return;
    }
    if(readBase(fp,base) == -1){
        printf("Error: error while load base!\n");
    };
    fclose(fp);

}

void save(StudentBase* base){
    FILE* fp;
    fp = fopen("data.txt","w");
    if (fp == NULL){
        printf("Error:Cannot open file!\n");
        return;
    }
    writeBase(fp, base);
    fclose(fp);

}

void add(StudentBase* base){
    Student student;
    printf("Enter student data:");

    readStudent(stdin,&student);

    if(addStudent(base,&student) != 0){
        printf("Error: error while add student to base!\n");
        return;
    }
}

void showAll(const StudentBase* base){
    int flag = 0;


    for(size_t i = 0; i < base->size_; i++){
            if(flag == 0) printf("\n#   Surname  init group   grades\n");
            printf("%d",i+1);
            writeStudent(stdout,&base->base_[i]);
            flag = 1;
    }

    if(flag == 0) printf("-----------\nNo students\n-----------\n");
}

double alg(const int grades[5]);

void showAG(const StudentBase* base){
    int flag = 0;
    printf("\n#   Surname  init group   grades\n");
    size_t i;
    for(i = 0; i < base->size_; i++){
        if(alg(&base->base_[i].grades) >= 4.0){
            if(flag == 0) printf("\n    
           Surname  init group   grades\n");
            printf("%d",i+1);
            writeStudent(stdout,&base->base_[i]);
            flag = 1;
        }
    }

    if(flag == 0) printf("-----------\nNo students\n-----------\n");
}

double alg(const int grades[5]){
    return (grades[0]+grades[1]+grades[2]+grades[3]+grades[4]) / 4.0 ;
}

void rem( StudentBase *base){

    printf("Which number from all you want to remove: ");
    int i;

    printf("\n");
    if(base->size_ > 0 && scanf("%d",&i) == 1 && base->size_ >= i){
        base->base_[i-1] = base->base_[base->size_-1];
        base->size_ -= 1;
        return;
    }
    else{
        printf("Error: Nothing to delete!\n");
        return;
    }

}


