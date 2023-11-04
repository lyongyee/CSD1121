/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        9
@date       3/11/2023
@brief      This file contains the declarations of the following functions

            encrypt
            decrypt

            The definitions of these functions can be found in q.c
*/


typedef int WordCount;
typedef unsigned char WordLength;
typedef int ErrorCode;

struct DictionaryInfo
{
    // Length of the shortest word
    WordLength shortest;
    // Length of the longest word
    WordLength longest;
    // Number of words in the dictionary
    WordCount count;
};
typedef struct DictionaryInfo DictionaryInfo;

enum ErrorCode
{
    FILE_OK = -1, // The file was opened successfully.
    FILE_ERR_OPEN = -2, // The file was not opened.
    WORD_OK = -3, // The word was found in the dictionary.
    WORD_BAD = -4 // The word was not found in the dictionary.
};
enum
{
    LONGEST_WORD = 50
};
char* str_to_upper(char* string);
WordCount words_starting_with(const char* dictionary, char letter);
ErrorCode spell_check(const char* dictionary, const char* word);
ErrorCode word_lengths(const char* dictionary, WordCount lengths[], WordLength count);
ErrorCode info(const char* dictionary, DictionaryInfo* info);