// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file       q.h
@author     Lee Yong Yee (l.yongyee)
@course     CSD1121
@section    Section B
@tutorial   Lab03
@date       15/9/2023
@brief      This file contains the declarations of functions tile and dispense_change whose definitons can be located in the q.c file 
*/


#include <stdio.h>

//Declaration of function tile from file q.c, where tile is not meant to return a value but takes in 2 variables of type double
void tile(double wall_length, double tile_width);

//Declaration of function dispense_change from file q.c where dispense_change is not meant to return a value
void dispense_change(void);