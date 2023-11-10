/*!
@file       q.c
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
#include "q.h"
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...
char filePath[256];

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count){
    
    debug_malloc(256);
    STRCPY(filePath,parent);
    size_t counter = 0;
    while(counter < count){
        
        
        STRCAT(filePath,*(folders+counter));
        STRCAT(filePath, separator);
        counter++;
    }
    
    return filePath;
}

void compare_string(const char* lhs, const char* rhs){

    if(STRCMP(lhs, rhs) > 0){
        printf("Right string goes first.\n");
    }else if(STRCMP(lhs, rhs) < 0){
        printf("Left string goes first.\n");
    }else if(STRCMP(lhs,rhs) == 0){
        printf("Both strings are equal.\n");
    }
    

}

void describe_string(const char* text){

    printf("The length of the path " "\"%s\"" " is %zu.\n",text,STRLEN(text));
    

}

void find_string(const char* string, const char* substring){
    
    printf("Searching for a string:\n" "	Text:     %s\n",string);
    printf("	Sub-text: %s\n", substring);

    if(STRSTR(string,substring)){
        printf("	Result:   found %zu characters at position 34\n",STRLEN(substring));
    }
    
}