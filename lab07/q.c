/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        7
@date       20/10/2023
@brief      This file contains the definitions of the following functions
            read_total_count
            read_3_numbers
            swap
            sort_3_numbers
            maintain_3_largest

            The declarations of these functions can be found in q.h
*/

#include "q.h"

/*
    the function read_total_count reads the integer input using a scanf statement and checks that if the value is less than 3 using an if else statement.
    If the value is less than 3, a printf statement saying "There is no third largest number" will be printed out and the program will exit. If the value is not less
    than 3 the function will return the integer converted to (size_t);
*/
size_t read_total_count(void){
    
    int count = 0;
    printf("Please enter the number of integers: ");
    scanf("%d", &count);
    if(count < 3){
        printf("There is no third largest number.\n");
        exit(0);
    }
    return (size_t) count;
    
}

/*
    the function read_3_numbers reads 3 integer inputs and stores them into the variables first, second and third
*/

void read_3_numbers(int *first, int *second, int *third){

    scanf("%d %d %d",first, second, third);
}

/*
    the function swap swaps the value of two variables. To do this it takes in two int pointer parameters, lhs and rhs. Then using a variable of int newRHS that will be intialised with the value of lhs,
    we will then do the swapping where we will replace the value of lhs with the value of rhs and the value of rhs with newRHS
*/
void swap(int *lhs, int *rhs){
    int newRHS = *lhs;

    *lhs = *rhs;
    *rhs = newRHS;
    
}

/*
    The function sort_3_numbers sorts its parameters in descending order.
    It ensures that the integer values pointed to by the input parameters, first, second, and third,
    are arranged in decreasing order after the function returns.
*/

void sort_3_numbers(int *first, int *second, int *third){
    if(*first < *second){
        swap(first,second);
        
    }
    if(*second < *third){
        swap(second,third);
        if(*first < *second){
            swap(first,second);
        }
        
        
    }
    
}

/*
    The function maintain_3_largest maintains the three largest values in sorted order.
    It compares the provided 'number' with the integer values pointed to by 'first', 'second', and 'third'.
    If 'number' is larger than any of these values, it updates the values while maintaining their sorted order.

*/

void maintain_3_largest(int number, int *first, int *second, int *third){

    sort_3_numbers(first,second,third);

    if(number > *first){
        swap(first,second);
        swap(first,third);
        *first = number;
        
    }else if(number < *first && number > *second){
        swap(second,third);
        *second = number;
        swap(first,second);
        
        
    }
    
}