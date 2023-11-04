/*!
@file       q.c
@author     Lee Yong Yee (l.yongyee)
@course     CSD1121
@section    Section B
@tutorial   Assignment02
@date       7/9/2023
@brief      This file contains functions draw_tree and draw_animal.

draw_tree creates a tree made out of asterisks(*) and hashes (#) using the printf function

draw_animal creates a cat with the text bubble "Hello Junior Coders!" using a mix of parentheses, slashes, back slashes and other characters

*/

#include <stdio.h> // for printf

/*!
@brief Prints out a tree using asterisks(*) and hashes (#)

This function is not meant to return a value, thus we use the void function. The function uses multiples lines of the printf function 
to form the structure of our asterisk and hash tree

@return void
*/

void draw_tree(void){

    printf("    *\n");
    printf("   ***\n");
    printf("  *****\n");
    printf(" *******\n");
    printf("*********\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");
    printf("    #\n");

}

/*!
@brief Prints out a tree using asterisks(*) and hashes (#)

This function is not meant to return a value, thus we use the void function. The function uses multiples lines of the printf function 
to form the structure of our cat and the speech bubble

@return void
*/

void draw_animal(void){

    printf("  /\\     /\\\n");
    printf(" /  \\___/  \\\n");
    printf("(           )    -------\n");
    printf("(   '   '   )   / Hello  \\\n");
    printf("(     _     )  <  Junior  |\n");
    printf("(           )   \\ Coder! /\n");
    printf(" |         |     -------\n");
    printf(" |    |    |\n");
    printf(" |    |    |\n");
    printf("(_____|_____)\n");

}

