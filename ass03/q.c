/*!
@file       qh.c 
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 3
@date       17/9/2023
@brief      This file contains the definitons of the temp_converter function that does the conversions for the Fahrenheit, Celsius and Kelvin temperature
            readings that need to be part of the output
*/

// This links the q.h to the q.c file so that the int main function in qdriver.c can run properly
#include "q.h"

/*The temp_converter functions handles the conversions of the temperature values. The value taken in qdriver.c for the temp_converter will be 
  defined as a type double variable that we will call fahrenheit_temp. 

  To convert the Fahrenheit temperature into Celsius, we will use the formula
  (fahrenheit_temp - 32)*5/9 and the result will be defined as our type double variable celsius_temp.

  To conver the Fahrenheit temperautre into Kelvin, we will use the formula
  (fahrenheit_temp + 459.67)*5/9 and the result will be defined as our type double variable kelvin_temp.

  Finally with all our variables defined, we can print out the output we need.

  The first printf statement prints the header for the 3 columns Fahrenheit, Celsius and Kelvin

  The second printf statement prints the separator that will be made out of dashes

  The third printf statement prints our 3 variables, farenheit_temp, celsius_temp and kelvin_temp

  Each variable is specified with %-15 so that the value is left-justified witin a 15-character wide space

  The %f is used to format fahrenheit_temp as a floating-point number with no decimal places while the %.2lf is used to
  format celsius_temp and kelvin_temp as double-precision floating-point numbers with two decimal places
*/
void temp_converter(double fahrenheit_temp){
    
    double celsius_temp = (fahrenheit_temp - 32)*5/9;
    double kelvin_temp = (fahrenheit_temp +459.67)*5/9;
    printf("Fahrenheit     Celsius        Kelvin         \n");
    printf("---------------------------------------------\n");
    printf("%-15.0f%-15.2lf%-15.2lf\n",fahrenheit_temp,celsius_temp,kelvin_temp); 

}