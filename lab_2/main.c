#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

/*
 * Лабораторная работа №2
 * Lab_2.c
 * kmp.c
 * stdstrcmp.c
 * Вайгачёв Андрей 6382
 * 19.03.2017
 *
 * Программа для нахождения вхождения подстроки в строку.
 * */

int main()
{
    char   needle[100000];
    char haystack[100000];
    const char test[5][11] = {"test2.txt","test5.txt","test9.txt","test10.txt","test11.txt"};
    const char answ[5][16] = {"test2_answ.txt","test5_answ.txt","test9_answ.txt","test10_answ.txt","test11_answ.txt"};
    int n = 0;
    int t = clock();


    printf("kmp here-->\n");
    for(int number = 0; number < 5; number++){

        printf("----------%s------------\n",test[number]);
        FILE* f_in  = fopen(test[number],"r");
        FILE* f_out = fopen(answ[number],"w");

        if(f_in == NULL || f_out == NULL){
            printf("Error: File not found!");
            break;
        }

        if(fscanf(f_in,"%d",&n) != 1){
            printf("Erorr: no digit in test");
            break;
             //exit(EXIT_FAILURE);
         }

        t = clock();
        for(int i = 0; i < n;i++){
            fscanf(f_in,"%s %s",haystack,needle);
            int kmp = strcmpkmp(needle,haystack);
            if(kmp != -1) fprintf(f_out,"YES\n");
                else fprintf(f_out,"NO\n");
        }
        t = clock() - t;

        printf("Time: %d\n",t);

    }



    printf("\n\n");




    printf("std here-->\n");
    for(int number = 0; number < 5; number++){

        printf("----------%s------------\n",test[number]);
        FILE* f_in  = fopen(test[number],"r");
        FILE* f_out = fopen(answ[number],"w");

        if(f_in == NULL || f_out == NULL){
            printf("Error: File not found!");
            break;
        }

        if(fscanf(f_in,"%d",&n) != 1){
            printf("Erorr: no digit in test");
            break;
             //exit(EXIT_FAILURE);
         }

        t = clock();
        for(int i = 0; i < n;i++){
            fscanf(f_in,"%s %s",haystack,needle);
            int kmp = stdstrcmp(needle,haystack);
            if(kmp != -1) fprintf(f_out,"YES\n");
                else fprintf(f_out,"NO\n");
        }
        t = clock() - t;

        printf("Time: %d\n",t);

    }


}


