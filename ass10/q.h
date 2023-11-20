/*!
@file       q.h
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 10
@date       16/11/2023
@brief      This file contains the declarations of the following functions

            read_data
            max
            min
            average
            variance
            std_dev
            median
            selection_sort
            ltr_grade_pctg

            The definitions of these functions can be found in q.c
*/



#ifndef Q_H
#define Q_H


enum {
    A_GRADE,
    B_GRADE,
    C_GRADE,
    D_GRADE,
    F_GRADE,
    TOT_GRADE  // Total number of letter grades
};


double* read_data(char const *file_name, int *ptr_cnt); //declaration of read_data
double max(double const *begin, double const *end); //declaration of max
double min(double const *begin, double const *end); //declaration of min
double average(double const *begin, double const *end); //declaration of average
double variance(double const *begin, double const *end); //declaration of variance
double std_dev(double const *begin, double const *end); //declaration of std_dev
double median(double *base, int size); //declaration of median
void selection_sort(double *base, int size); //declaration of selection_sort
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades); //declaration of ltr_grade_pctg


#endif // #ifndef Q_H
