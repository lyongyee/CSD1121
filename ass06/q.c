/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 6
@date       22/10/2023
@brief      This file contains the definitions of the following functions

            reverse_array
            add_arrays
            scalar_multiply
            dot_product
            cross_product
            length

            The declarations of these functions can be found in q.h
*/

#include "q.h"

/*
    The function reverse_array, takes in any array

*/
void reverse_array(int a[], int size){
   
    
    int i = 0;
    int temp = 0;
    int y = size-1;
    while(i<y){
         temp = a[i];
         a[i] = a[y];
         a[y] = temp;
        i++;
        y--;   
    }


    
}

void add_arrays(int const a[], int const b[], int c[], int size){
    for(int i =  0; i < size; i++ ){
        c[i] = a[i] + b[i];
    }


}

void scalar_multiply(int a[], int size, int multiplier){
    for(int i =  0; i < size; i++ ){
        a[i] *= multiplier;
    }

    
}

int dot_product(int const a[], int const b[], int size){
    int productOfArrays = 0;
    int dotProductSum = 0;

    for(int i = 0; i < size; i++){
        productOfArrays = a[i]*b[i];
        dotProductSum += productOfArrays; 
    }
    return dotProductSum;
}

void cross_product(int const a[], int const b[], int c[]){
   
        
        c[0] = (a[1] * b[2]) - (a[2] * b[1]);
        c[1] = -(a[0] * b[2] - a[2] * b[0]);
        c[2] = a[0] * b[1] - a[1] * b[0];    

        
}


double length(int const a[], int size){
    double sumOfProducts = 0;
    double length = 0;
    for(int i = 0; i < size; i++){
        sumOfProducts += pow(a[i],2);
    }

    length = sqrt(sumOfProducts);

    return length;
}
