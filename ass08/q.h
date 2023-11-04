/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 8
@date       2/11/2023
@brief      This file contains the declarations of the following functions

            encrypt
            decrypt

            The definitions of these functions can be found in q.c
*/
#ifndef Q_H
#define Q_H

// TODO: Include only those C standard library headers that declare/define names used in functions declared below
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#define FILE
// TODO: A function documentation block provides information that is crucial
// for clients to correctly use the function. Provide a documention block
// for each declared function that contains the following information:
// What does the function do?
// What are the (types) of the parameters?
// What is the (type) of value returned by function?
// Is there any particular input that will break the function?
typedef struct Tsunami
{
    int day;
    int month;
    int year;
    double max_wave_height;
    int fatalities;
    char location[256];
    

}Tsunami;

// TODO: Now, declare the necessary function.
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt);

void print_info(struct Tsunami const *arr, int size, FILE* out_stm);

double get_max_height(struct Tsunami const *arr, int size);

double get_average_height(struct Tsunami const *arr, int size);

void print_height(struct Tsunami const *arr, int size, double height, FILE* out_stm);



#endif
