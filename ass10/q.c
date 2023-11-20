/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 10
@date       16/11/2023
@brief      This file contains the definitions of the following functions

            read_data
            max
            min
            average
            variance
            std_dev
            median
            selection_sort
            ltr_grade_pctg

            The declarations of these functions can be found in q.h
*/

#include "q.h" // we're including q.h here because we want to apply the DRY principle [see specs for additional info]
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double number;

/*
Parameters:
- file_name: A string containing the name of the file to be read.
- ptr_cnt: A pointer to an integer where the count of read values will be stored.

Returns:
- On success, returns a pointer to an array of double values read from the file.
- On failure, returns NULL.

Description:
The function read_data reads double values from a file specified by file_name. It dynamically allocates memory for an array to store the values, updates the count of read values using ptr_cnt, 
and returns a pointer to the allocated array. If an error occurs during file operations or memory allocation, the function returns NULL.

*/
double* read_data(char const *file_name, int *ptr_cnt){
    FILE* in = fopen(file_name, "r");
    if (in == NULL) {
            fprintf(stderr, "Error opening file: %s\n", file_name);
            return NULL;
        }
    int count = 0;
    while(fscanf(in, "%lf", &number) == 1){
        count++;
    }

    fseek(in, 0, SEEK_SET);

    double* values = (double*)malloc(count * sizeof(double));
    if(values == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        fclose(in);
        return NULL;
    }

    for(int i = 0; i < count; i++){
        if(fscanf(in, "%lf", &values[i]) != 1){
          fprintf(stderr, "Error reading value from file\n");
            free(values);  // Free allocated memory before returning NULL
            fclose(in);
            return NULL;  
        }
    }

    fclose(in);

    *ptr_cnt = count;

    return values;


}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.

Returns:
- The maximum value in the specified range.

Description:
This function max finds and returns the maximum value within the specified range [begin, end).

*/


double max(double const *begin, double const *end){
    double currentMax = 0;
    for(int counter = 0 ; begin + counter < end ; counter++){
        
        if(currentMax < *(begin + counter)){
            currentMax = *(begin + counter);
        }

    }

    return currentMax;
}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.

Returns:
- The minimum value in the specified range.

Description:
This function min finds and returns the maximum value within the specified range [begin, end).

*/

double min(double const *begin, double const *end){
    double currentMin = *begin;
    for(int counter = 0 ; begin + counter < end ; counter++){
        
        if(currentMin > *(begin + counter)){
            currentMin = *(begin + counter);
        }

    }

    return currentMin;
}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.

Returns:
- The average (mean) value of the elements in the specified range.

Description:
This function average calculates and returns the average (mean) of the double values within the specified range [begin, end).

*/

double average(double const *begin, double const *end){

    double sumOfGrades = 0.0;
    double numOfGrades = end - begin;
    for(int counter = 0; begin+counter < end; counter++){
        sumOfGrades += *(begin+counter);
    }

    return sumOfGrades/numOfGrades;
}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.

Returns:
- The variance of the double values within the specified range.

Description:
This function variance calculates and returns the variance of the double values within the specified range [begin, end).

*/

double variance(double const *begin, double const *end){
    double varianceofGrades = 0.0;
    double difference  = 0.0;
    double sumOfDifference = 0.0;
    double avg = average(begin, end);
    for(int counter = 0; begin + counter < end; counter++ ){
        difference = *(begin+counter) - avg;
        sumOfDifference += pow(difference,2);
    }
    varianceofGrades = sumOfDifference/((end-begin)-1);
    return varianceofGrades;

}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.

Returns:
- The variance of the double values within the specified range.

Description:
This function std_dev calculates and returns the standard deviation of the double values within the specified range [begin, end).

*/

double std_dev(double const *begin, double const *end){
    double standard_deviation = 0.0;

    standard_deviation = sqrt(variance(begin,end));

    return standard_deviation;

}

/*
Parameters:
- base: A pointer to the beginning of an array of double values.
- size: The number of elements in the array.

Returns:
- The median value of the array.

Description:
This function median calculates and returns the median value of the array using the selection sort algorithm.

*/

double median(double *base, int size){
    selection_sort(base,size);

    double median = 0.0;
    if(size%2 == 0){
        median = (*(base + (size/2)-1) + *(base + ((size/2))))/2;
    }else{
        median = *(base + (size/2));
    }

    return median;
}

/*
Parameters:
- lhs: A pointer to the beginning of an array of double values.
- rhs: A pointer to the end (exclusive) of the array.

Returns:
- swapped values of the left hand side and the right hand side

Description:
This function swap swaps the left hand value with the right hand value

*/

void swap(double *lhs, double *rhs){
    double temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}


/*
Parameters:
- base: A pointer to the beginning of an array of double values.
- size: The number of elements in the array.

Returns:
- This function does not return a value.

Description:
This function selection_sort performs an in-place selection sort on the array of double values in ascending order.

*/

void selection_sort(double *base, int size){
    int i, j;
    for (i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (base[j] < base[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&base[i], &base[minIndex]);
        }
    }
}

/*
Parameters:
- begin: A pointer to the beginning of an array of double values.
- end: A pointer to the end (exclusive) of the array.
- ltr_grades: A pointer to an array where the letter grade percentages will be stored.

Returns:
- This function does not return a value.

Description:
This function ltr_grade_pctg calculates and stores the letter grade percentages (A, B, C, D, F) based on the given numerical grades within the specified range [begin, end). 
The percentages are stored in the ltr_grades array, and the total number of grades is also calculated and stored in the TOT_GRADE index of the array.

*/

void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades){
    int counter = 0 ;
    int gradeA = 0, gradeB = 0 , gradeC = 0, gradeD = 0, gradeF = 0;
    while(begin+counter < end){
        if(*(begin+counter) > 90.00){
            gradeA += 1;
        }else if( *(begin+counter) < 90.00 && *(begin+counter) > 80.00){
            gradeB += 1;
        }else if(*(begin+counter) < 80.00 && *(begin+counter) > 70.00){
            gradeC += 1;
        }else if(*(begin+counter) < 70.00 && *(begin+counter) > 60.00){
            gradeD += 1;
        }else if(*(begin+counter) < 60.00){
            gradeF += 1;
        }
        
        counter++;
    }

    ltr_grades[TOT_GRADE] = gradeA + gradeB + gradeC + gradeD + gradeF;
    
    ltr_grades[A_GRADE] = (gradeA/ltr_grades[TOT_GRADE]) *100;
    ltr_grades[B_GRADE] = (gradeB/ltr_grades[TOT_GRADE]) *100;
    ltr_grades[C_GRADE] = (gradeC/ltr_grades[TOT_GRADE]) *100;
    ltr_grades[D_GRADE] = (gradeD/ltr_grades[TOT_GRADE]) *100;
    ltr_grades[F_GRADE] = (gradeF/ltr_grades[TOT_GRADE]) *100;
    

}