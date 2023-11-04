// @todo: Add a file-level documentation header as explained in Lab 2 specs ...

// @todo: Provide function-level documentation header as explained in the specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve problems related to computing summary statistics.
// In a commercial environment, the source file q.c containing definitions of
// functions that compute summary statistics is your intellectual property and should
// therefore be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the functions related to computing
// summary statistics only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...
#include <stdio.h>
#include <math.h>

int max_index(double const arr[], int size);
int min_index(double const arr[], int size);
double mean(double const arr[], int n);
double variance(double const[], int size);
double std_dev(double const[],int size);
int read_data(double array[], int max_array_size);
#define MAX_STUDENT_COUNT 1000