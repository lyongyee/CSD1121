/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 9
@date       09/11/2023
@brief      This file contains the declarations of the following functions

            encrypt
            decrypt

            The definitions of these functions can be found in q.c
*/

// NOTE 2: Even if you don't need the NULL, don't remove this macro ...
#define NULL ((void*)0)
#include "q.h"

// NOTE 3: When uploading this file for grading, make sure to remove all
// standard library includes from this file.
// The auto-grader will not accept your submission if the file contains
// include directives.

// NOTE 4: When uploading this file for grading, make sure to remove
// all references to the subscript operator or the [ or ] symbols from your code. 
// It is important that even your comments should not include these symbols.

// TODO: Definitions of functions declared in q.h go here ...
char const* find(char const *begin, char const *end, char val){
    
    while(begin < end){
        
        if(*begin == val){
            
            return begin;
            
        }
        ++begin;
    }

    return NULL;
    
}

char const* find_any(char const *begin, char const *end, char const *vals, int len){
   int counter = 0;
   
    while(counter++ < len){

        
        if(find(begin,end,*(++vals)) != NULL){
        return find(begin,end,*(vals));
        }
    
    }
    return NULL;
}

int count(char const *begin, char const *end, char val){
    int counter = 0;
    while(begin < end){
        if(*begin++ == val){
            ++counter;
        }
    }
      

    return counter;
}

int count_any(char const *begin, char const *end, char const *vals, int len){
    int counter = 0;
    int totalCount = 0;
    while(counter++ < len){
        totalCount += count(begin,end,*(vals++));

    }
    
    return totalCount;

}

int compare(char const *begin1, char const *begin2, int len){
    int counter = 0;
    int result;
    while(counter < len){
        if(*(begin1+counter) == *(begin2+counter)){
            result = 0;
        }else if(*(begin1+counter) < *(begin2+counter)){
            result = -1;
        }else if(*(begin1+counter) > *(begin2+counter)){
            result = 1;
        }
        counter++;
    }

    return result;
}


void exchange(char *begin1, char *begin2, int len){
    char temp;
    
    for(int counter = 0; counter < len; counter++){
        
        temp = *(begin1 + counter);
        *(begin1+counter) = *(begin2+counter);
        *(begin2+counter) = temp;
        
 
    }
}

void copy(char *dst, char *src, int len){
    
    if(dst <= src || dst >= (src + len)){
        for(int counter = 0; counter<len; counter++){
        *(dst+counter) = *(src+counter);
    }
    }else{
        for(int counter = len-1; counter >= 0; counter--){
        *(dst+counter) = *(src+counter);
    }
    }
    
}