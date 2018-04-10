#include "kmp.h"
#include <string.h>

void pre_prefix(const char* needle,int* arr){

    int m = strlen(needle);int i = 0, j = -1; arr[0] = -1;
        while (i < m) {
            if (j >= 0 && needle[i] != needle[j]) j = arr[j]; //Why not?
            i++; j++;
            arr[i] = j;
        }

}

int strcmpkmp(const char* needle,const char* haystack){

    int n = strlen(needle);
    int prefix_arr[n];

    pre_prefix(needle,prefix_arr);

    int h = strlen(haystack);
    int j = 0;

    n -= 1;

    for(int i = 0; i < h; i++){

        while(haystack[i] != needle[j] && j > 0) j = prefix_arr[j];

        if(haystack[i] == needle[j] && j == n) return i-n;

        if(haystack[i] == needle[j]) j++;


    }
         return -1;

}
