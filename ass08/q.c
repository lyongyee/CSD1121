/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 8
@date       2/11/2023
@brief      This file contains the definitions of the following functions

            encrypt
            decrypt

            The declarations of these functions can be found in q.c
*/

// TODO: Include all necessary C standard library headers 
#include "q.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// TODO: Definitions of functions declared in q.h go here ...
int read_data(char const *file_name, struct Tsunami *arr, int max_cnt){
    int i = 0;
    FILE *read = fopen(file_name, "r");
    if(read == NULL){
        perror("Unable to open file");
        return -1;
    }

    while(i< max_cnt && fscanf(read, "%d %d %d %d %5lf %255[^\n]\n", &arr[i].day, &arr[i].month, &arr[i].year, &arr[i].fatalities, &arr[i].max_wave_height, arr[i].location) == 6){
       
    
        i++;
    }

    fclose(read);
    return i;
}

void print_info(struct Tsunami const *arr, int size, FILE *out_stm){

   
    for(int i = 0; i<size; i++){
        fprintf(out_stm,"%02d %02d %04d %6d %5.2lf %s\n", arr[i].day, arr[i].month, arr[i].year, arr[i].fatalities, arr[i].max_wave_height, arr[i].location);
    }

   
}

double get_max_height(struct Tsunami const *arr, int size){
    double maxHeight = 0;
    int count = 0;
    while(count < size){
        if(arr[count].max_wave_height > maxHeight){
            maxHeight = arr[count].max_wave_height;
        }
        count++;
    }

    return maxHeight;
}

double get_average_height(struct Tsunami const *arr, int size){
    double sumOfHeights = 0;
    for(int i = 0; i < size; i++){
        sumOfHeights += arr[i].max_wave_height;
    }

    return (sumOfHeights/size);

}

void print_height(struct Tsunami const *arr, int size, double height, FILE *out_stm){



    for(int i = 0; i < size; i++){
        if(arr[i].max_wave_height > height){
            fprintf(out_stm,"%5.2lf %s\n", arr[i].max_wave_height, arr[i].location);
        }
    }

   
}