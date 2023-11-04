/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 6
@date       22/10/2023
@brief      This file contains the declarations of the following functions

            reverse_array
            add_arrays
            scalar_multiply
            dot_product
            cross_product
            length

            The definitions of these functions can be found in q.h
*/

#include <math.h> //for sqrt() & pow()


void reverse_array(int a[], int size);
void add_arrays(int const a[], int const b[], int c[], int size);
void scalar_multiply(int a[], int size, int multiplier);
int dot_product(int const a[], int const b[], int size);
void cross_product(int const[], int const b[], int c[]);
double length(int const a[], int size);