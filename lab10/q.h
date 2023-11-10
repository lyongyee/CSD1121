/*!
@file       q.h
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
#include <stdio.h>
#ifdef USE_STRING
#include <string.h>
#define STRLEN strlen
#define STRCPY strcpy
#define STRCAT strcat
#define STRCMP strcmp
#define STRSTR strstr
#else
#include "my_string.h"

#define STRLEN my_strlen
#define STRCPY my_strcpy
#define STRCAT my_strcat
#define STRCMP my_strcmp
#define STRSTR my_strstr

#endif

void* debug_malloc(size_t size);
void debug_free(void* ptr);

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count);
void compare_string(const char* lhs, const char* rhs);
void describe_string(const char* text);
void find_string(const char* string, const char* substring);
