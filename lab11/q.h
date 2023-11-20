/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        11
@date       17/11/2023
@brief      This file contains the declaration of the print_data function and the struct Datum. The definition of the print_data function can be found in q.c
*/

#include <stdio.h>

struct Datum
{
    char upper;
    char lower;
    unsigned short int value;
};

typedef struct Datum DATUM;
typedef DATUM DATA[2];

void print_data(const void* ptr, size_t size, size_t span);