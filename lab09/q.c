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


/*
    The function str_to_upper takes a string as input and transforms all lowercase letters within the string into uppercase, subsequently returning a pointer to the initial character of the string. 
    Notably, this operation occurs in-place, meaning that the function modifies the original array provided as a function parameter without creating a new array. 
    As a result, the returned object is identical to the original input, preserving the same value.
*/
char* str_to_upper(char* string){

    
    char* original = string;

    while(*string){
        *string = (char)toupper(*string);
        string++;
    }

    

    return original;
}

/*
    The function words_starting_with, when provided with the file name of a dictionary text file, 
    calculates the quantity of words commencing with a specified letter. If the file cannot be opened, it returns FILE_ERR_OPEN; otherwise, it yields the count of words that meet the criteria. 
    Importantly, this function performs character comparisons in a case-insensitive manner, which is achieved by converting both operands of the comparison to uppercase using the str_to_upper() function. 
    
*/
WordCount words_starting_with(const char* dictionary, char letter){
    FILE *dict;
    char word[20];
    int wordCount = 0;
    dict = fopen(dictionary,"r");

    if(dict == NULL){
        
        return FILE_ERR_OPEN;
    }

    

    while((fgets(word, 20,dict) != NULL )){
    
    str_to_upper(word);
    str_to_upper(&letter);
        if(word[0] == letter){
            
            wordCount++;
            
        
        } 
    }

    fclose(dict);

    return wordCount;
}

/*
    The function spell_check when provided with the filename of a dictionary text file and a specific word, conducts a lookup operation for the word within the dictionary. 
    The function provides three possible outcomes: FILE_ERR_OPEN is returned if the file cannot be opened, indicating an issue with accessing the dictionary. If the word is not found within the dictionary, it returns WORD_BAD. 
    On the other hand, if the word is successfully located within the dictionary, it returns WORD_OK. 

*/

ErrorCode spell_check(const char* dictionary, const char* word){
    FILE *dict;
    dict = fopen(dictionary,"r");
    char dictWord[20];
    char upperWord[20];
    

    if(dict == NULL){
        
        return FILE_ERR_OPEN;
    }

    strcpy(upperWord,word);

    str_to_upper(upperWord);

    while(fscanf(dict, "%s",dictWord) != EOF ){
    
    str_to_upper(dictWord);

    if(strcmp(dictWord, upperWord) == 0){
            fclose(dict);
            return WORD_OK;
            
        
        }

    }


    fclose(dict);
    return WORD_BAD;
}

/*
    The function word_lengths when provided with the filename of a dictionary text file, is designed to determine the count of words falling within a specific range of lengths, 
    from 1 to a user-defined upper limit (inclusive). It stores the results in an array called "lengths," positioning the count for each word length at the corresponding index within the array. 
    In the event that the file cannot be opened, the function returns FILE_ERR_OPEN to signal an issue with file access. Otherwise, if the operation is successful and the words are counted as specified, it returns FILE_OK, 
    indicating the successful execution of the function.

*/
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count){
    FILE *dict;
    dict = fopen(dictionary,"r");
    char dictWord[20];
    size_t wordLength;

    if(dict == NULL){
        
        return FILE_ERR_OPEN;
    }

    while(fscanf(dict, "%s",dictWord) != EOF){
       
       wordLength = strlen(dictWord);

       if(wordLength >= 1 && wordLength <= count){
            lengths[wordLength]++;
       }

    }


    fclose(dict);
    return FILE_OK;
}

/*
    The function info when provided with the filename of a dictionary text file, is designed to retrieve and provide a description of the dictionary's content. 
    This description includes information about the length of the shortest and longest words within the dictionary, as well as the total count of words it contains. 
    This information is structured and returned using the DictionaryInfo structure. In cases where the file cannot be opened, the function returns FILE_ERR_OPEN, indicating a problem with accessing the file. 
    However, if the function successfully obtains and compiles the required information, it returns FILE_OK, signifying a successful execution.

*/

ErrorCode info(const char* dictionary, DictionaryInfo* info){
    FILE *dict;
    dict = fopen(dictionary,"r");
    char dictWord[20];
    size_t wordLength;
    info->shortest = 4; 
    info->longest = 0;
    info->count = 0;


    if(dict == NULL){
        
        return FILE_ERR_OPEN;
    }

    while(fscanf(dict, "%s",dictWord) != EOF){
       
       wordLength = strlen(dictWord);

       
       if(wordLength > info->longest){
            info->longest = (WordLength)wordLength;
            
            
           
       }
       if(wordLength < info->shortest){
            
            info->shortest = (WordLength)wordLength;
            
        }

       info->count += 1;

    }
    fclose(dict);
    return FILE_OK;
}