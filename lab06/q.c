// @todo: Add a file documentation header as explained in the specs ...

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily meant for your clients.
// The documentation header here is primarily for use by you [and other on your team] solely t
// aid maintenance and debugging tasks ...

// @todo: If necessary, include q.h here ...
#include "q.h"
// @todo: Add necessary C standard library headers here ...

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...
int max_index(double const arr[], int size){

    double max_value = arr[0];
    int i;
    int max_element;
    for(i = 1; i < size; ++i){
        if(arr[i] > max_value){
            max_value = arr[i];
            max_element = i;
        }
        
        
    }
    return max_element;
}

int min_index(double const arr[], int size){
    double min_value = arr[0];
    int i;
    int min_element;
    for(i = 1; i < size; ++i){
        if(arr[i] < min_value){
            min_value = arr[i];
            min_element = i;
        }
    }
    return min_element;
}

double mean(double const arr[], int n){
    double sum = 0.0;
    double mean = 0.0;
    int i = 0;
    while (i<n){
        sum+= arr[i++];
    }
    mean = sum/n;

    return mean;
}

double variance(double const arr[], int size){
    double variance = 0.0;
    double difference = 0.0;
    double sumOfDifference = 0.0;
    double avg = mean(arr,size);
    if(size >= 2){
    int i;
    for( i = 0; i<size;++i){
        difference  = arr[i] - avg;
        sumOfDifference += pow(difference,2);
    }
    }
    variance = sumOfDifference/(size-1);
    return variance;
}

double std_dev(double const arr[],int size){
    double standard_deviation = 0.0;
    
    if(size >= 2){
    standard_deviation = sqrt(variance(arr,size));
    
    }

    return standard_deviation;
}

int read_data(double array[], int max_array_size){
    int i = 0;
    double num;
    while((scanf("%lf",&num) !=EOF) && i < max_array_size){
        array[i++] = num;
    }

    return i;


}