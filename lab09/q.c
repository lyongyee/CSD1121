/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        9
@date       3/11/2023
@brief      This file contains the definitons of the following functions

            encrypt
            decrypt

            The declarations of these functions can be found in q.h
*/

// @todo: Add necessary C standard library headers here ...
#include "q.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* str_to_upper(char* string){

    
    char* original = string;

    while(*string){
        *string = (char)toupper(*string);
        string++;
    }

    

    return original;
}
//Count the numbers of words in the file
//Function is not case-sensitive
//Use str_to_upper() to change all the letters to uppercase
WordCount words_starting_with(const char* dictionary, char letter){
    FILE *dict;
    dict = fopen("allwords.txt","r");

    if(dict == NULL){
        
        return FILE_ERR_OPEN;
    }

    while()

    fclose(dict);
}

ErrorCode spell_check(const char* dictionary, const char* word){

    return 1;
}

ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count){

    return 1;
}

ErrorCode info(const char* dictionary, DictionaryInfo* info){

    return 1;
}