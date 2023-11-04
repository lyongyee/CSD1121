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