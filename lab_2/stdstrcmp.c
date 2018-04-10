#include "stdstrcmp.h"

int stdstrcmp(const char* needle,const char* haystack){

    int n = strlen(needle);
    int h = strlen(haystack);
    int i = 0;
    int j = 0;

    for(i = 0; i < h - n + 1  ; i++){
        j = 0;
        while(j < n+1){

            if(needle[j] != haystack[i+j]) break;

            if(needle[j] == haystack[i+j] && j != n-1) {j++;continue;}

            if(needle[j] == haystack[i+j]) return i;
        }
    }

    return -1;

}
