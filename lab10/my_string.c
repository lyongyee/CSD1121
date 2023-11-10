/*!
@file       my_string.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        10
@date       10/11/2023
@brief      This file contains the declarations of the following functions

            encrypt
            decrypt

            The definitions of these functions can be found in q.c
*/

// @todo: Add necessary C standard library headers here ...
#include "my_string.h"
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in my_string.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition(s) of function(s) that
// match the declaration(s) in my_string.h ...

// For each function -

// Add documentation [for yourself and not for grading] for the function ...

// @todo: Provide the definition of the function(s) that
// match(es) the declaration(s) in my_string.h ...
size_t my_strlen(const char* str){

}

char* my_strcpy(char* dest, const char* src){
    
    return *dest = *src;

}

char* my_strcat(char* dest, const char* src){
    int counter = 0;
    
    while(*(src+counter) != '\0'){
        if(*(dest+counter) == '\0'){
            *(dest+counter) = *(src+counter);
            *(dest+counter+1) = '\0';
        }
        counter++;
    }

    return dest;
}

int my_strcmp(const char* lhs, const char* rhs){

}

char* my_strstr(const char* str, const char* substr){

}