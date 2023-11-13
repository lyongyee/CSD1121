/*!
@file       my_string.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        10
@date       10/11/2023
@brief      This file contains the declarations of the following functions

            my_strlen
            my_strcopy
            my_strcat
            my_strcmp
            my_strstr

            The definitions of these functions can be found in my_string.h
*/

// @todo: Add necessary C standard library headers here ...
#include "my_string.h"

/*
 * @brief   Calculates the length of a string.
 *
 * @param   str     A pointer to the null-terminated string.
 *
 * @return  The length of the string (excluding the null terminator).
 */
size_t my_strlen(const char* str){
    size_t i;
    for(i = 0; str[i] != '\0'; i++);
    return i;

}

/*
 * @brief   Copies the contents of one string to another.
 *
 * @param   dest    A pointer to the destination string where the content is to be copied.
 * @param   src     A pointer to the source string whose content is to be copied.
 *
 * @return  A pointer to the destination string (`dest`).
 */
char* my_strcpy(char* dest, const char* src){
    int i;
    for(i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;

}

/*
 * @brief   Concatenates two strings.
 *
 * @param   dest    A pointer to the destination string to which the source string is appended.
 * @param   src     A pointer to the source string that is to be appended to the destination string.
 *
 * @return  A pointer to the destination string (`dest`), now containing the concatenated result.
 */

char* my_strcat(char* dest, const char* src){
    int i = 0,j = 0;

    while(dest[i] != '\0'){
        i++;
    }
    while(src[j] != '\0'){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

/*
 * @brief   Compares two strings lexicographically.
 *
 * @param   lhs     A pointer to the first null-terminated string for comparison.
 * @param   rhs     A pointer to the second null-terminated string for comparison.
 *
 * @return  An integer less than, equal to, or greater than zero if `lhs` is found to be
 *          less than, equal to, or greater than `rhs`, respectively.
 */
int my_strcmp(const char* lhs, const char* rhs){
    return (int)(lhs - rhs);
}

/*
 * @brief   Locates the first occurrence of a substring in a string.
 *
 * @param   str     A pointer to the null-terminated string to be searched.
 * @param   substr  A pointer to the null-terminated substring to search for in `str`.
 *
 * @return  A pointer to the first occurrence of the substring in the string, or NULL if the
 *          substring is not found.
 */
char* my_strstr(const char* str, const char* substr){
    if (*substr == '\0') {  
        return (char*) str;
    }
 
    while (*str != '\0') {
        const char* string = str;
        const char* substring = substr;
 
        while (*substring != '\0' && *string == *substring) {  
            string++;
            substring++;
        }
 
        if (*substring == '\0') {  
            return (char*) str;
        }
 
        str++;  
    }
 
    return NULL;
}