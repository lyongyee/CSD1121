/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        7
@date       20/10/2023
@brief      This file contains the declarations of the following functions
            read_total_count
            read_3_numbers
            swap
            sort_3_numbers
            maintain_3_largest

            The definitions of these functions can be found in q.c
*/


#include <stdio.h> //for printf and scanf
#include <stdlib.h> //for exit()

size_t read_total_count(void);
void read_3_numbers(int *first, int *second, int *third);
void swap(int *lhs, int *rhs);
void sort_3_numbers(int *first, int *second, int *third);
void maintain_3_largest(int number, int *first, int *second, int *third);