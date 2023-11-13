/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        10
@date       10/11/2023
@brief      This file contains the definitions of the following functions

            build_path
            compare_string
            describe_string
            find_string

            The declarations of these functions can be found in q.h
*/


#include "q.h"

char filePath[256];

/*
 * @brief   Builds a file path by concatenating a parent path, separator, and an array of folders.
 *
 * @param   parent      The parent path.
 * @param   separator   The separator to be used between the parent path and folders.
 * @param   folders     An array of folder names to be appended to the parent path.
 * @param   count       The number of folders in the 'folders' array.
 *
 * @return  A dynamically allocated string representing the constructed file path.
 *          The caller is responsible for freeing the allocated memory.
 *          Returns NULL if memory allocation fails.
 */

const char* build_path(const char* parent, const char* separator, const char* const folders[], size_t count){
    
    // debug_malloc(count);
    size_t total_length = STRLEN(parent);
    for(size_t counter = 0; counter < count; counter++){
        total_length += STRLEN(separator);
        total_length += STRLEN(folders[counter]);
    }
    char* result = (char*)debug_malloc(total_length+1);
    if (result) {
        // Copy the parent path to the result
        STRCPY(result, parent);

        // Iterate through the folders and concatenate them to the path using the separator
        for (size_t i = 0; i < count; ++i) {
            STRCAT(result, folders[i]);
            STRCAT(result, separator);
            
        }

        // Return the constructed path
        return result;
    }

    // Return NULL if memory allocation failed
    return NULL;
    
    
}

/*
 * @brief   Compares two strings lexicographically and prints a message indicating their relationship.
 *
 * @param   lhs     The left-hand side string for comparison.
 * @param   rhs     The right-hand side string for comparison.
 *
 * @return  None.
 *          Prints to the console whether the left string is less than, equal to, or greater than the right string.
 */

void compare_string(const char* lhs, const char* rhs){

    if(STRCMP(lhs, rhs) > 0){
        printf("Right string goes first.\n");
    }else if(STRCMP(lhs, rhs) < 0){
        printf("Left string goes first.\n");
    }else if(STRCMP(lhs,rhs) == 0){
        printf("Both strings are equal.\n");
    }
    

}

/*
 * @brief   Prints the length of a given string.
 *
 * @param   text    The string to be described.
 *
 * @return  None.
 *          Prints to the console the length of the given string.
 */
void describe_string(const char* text){

    printf("The length of the path " "\"%s\"" " is %zu.\n",text,STRLEN(text));
    

}

/*
 * @brief   Searches for a substring in a given string and prints the result.
 *
 * @param   string      The string to be searched.
 * @param   substring   The substring to search for in the main string.
 *
 * @return  None.
 *          Prints to the console whether the substring is found in the main string,
 *          and if found, the position of the substring in the main string.
 */

void find_string(const char* string, const char* substring){
    
    printf("Searching for a string:\n" "	Text:     %s\n",string);
    printf("	Sub-text: %s\n", substring);

    if(STRSTR(string,substring)){
        long int position = STRSTR(string,substring) - string;
        
        printf("	Result:   found %zu characters at a position %ld.\n",STRLEN(substring), position);
    }else{
        printf("	Result:   not found\n");
    }
    
}