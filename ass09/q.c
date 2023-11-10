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
    int counter = 0;
    while(begin + counter < end){
        
        if(*begin + counter == val){
            
            return begin + counter;
            
        }
        counter++;
    }

    return NULL;
    
}

char const* find_any(char const *begin, char const *end, char const *vals, int len){
   int counter = 0;
    
    while(counter < len){
        
    if(*(find(begin,end,*(vals+counter))) == *(vals+counter)){
    return begin+counter;
    }
    counter ++;
    }
    return NULL;
}

// int count(char const *begin, char const *end, char val){
//     return 1;
// }

// int count_any(char const *begin, char const *end, char const *vals, int len){
//     return 1;
// }

// int compare(char const *begin1, char const *begin2, int len){
//     return 1;
// }


// void exchange(char *begin1, char *begin2, int len){
//     return 1;
// }

// void copy(char *dst, char *src, int len){
//     return 1;
// }