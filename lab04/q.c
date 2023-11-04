// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file       q.c
@author     Lee Yong Yee (l.yongyee)
@course     CSD1121
@section    Section B
@tutorial   Lab04
@date       22/9/2023
@brief      This file contains the definitions of functions print_line , break_down whose declarations can be located in the q.h file 
*/

#include "q.h"





/*The print_line function which will be called by break_down is responsible for showing the correct output of each line using a printf statement. It takes in
  3 parameters, int index, int rest and int denomination
  
  The int index will represent the number of the row, the int rest will be used to help us to get our definition of the int count that we have defined to
  represent the number of bills/coins of that denomination thus count is equal to rest divided by denomination. The int denomination will need to be converted
  into a float for it to show correctly in the printf statement, thus we take denomination divided by 100.0 so that it fits the format specifier for float
 */
void print_line(int index, int rest, int denomination){

    
    int count  =  rest/denomination;
     
    printf("|%3d |%13.2f |%6d |\n", index, denomination/100.0, count );
    

}

/*The break_down function is responsible for outputting the borders of the table, the headers of the table, all the lines of the table from 1-11 and the footer of the table
  
  We use printf statements to output the header, the borders and the footer of the table


  To print the lines of the table, we call the print_line function using a for loop where int i = 1 and is less than 12 and is always incrementing. each print_line
  function that is called by the for loop it will also update the value for cents to ensure that the count is correct for each denomination 
 */
void break_down(int cents){

    
    printf("+----+--------------+-------+\n");
    printf("| #  | Denomination |  Count|\n");
    printf("+----+--------------+-------+\n");
    
    int denominations[]={10000, 5000, 1000, 500, 200, 100, 50, 20, 10 , 5, 1};
    
    int i;
     for(i=1; i < 12; ++i){
        print_line(i,cents,denominations[i-1]);
        cents = cents%denominations[i-1];
    }

    
    printf("+----+--------------+-------+\n");
}

/* The go function is responsible for check whether the input given is in the valid format of dollars and cents. 

    The first check is checking that there's an input for dollars. It uses a scanf function to check whether
    an integer has been inputted for dollars, if there's no input for dollars it prints an error message

    The second check is checking that there is a period after dollars, this is done by using the getc function to get the
    standard input from the stream, if the character inputted is not a period then a error message will be printed out

    The third check is checking if there are exactly two digits for the cents values and whether they are between the range of 0 to 99

    All these checks are encased in a while loop with the loop programmed to break when the error message is printed
*/


void go(void){

    printf("Please enter total value:\n");
    
 
    
    while (1) 
    { 
        int dollars, cent, decimalPoint, totalValueinCents, cent1, cent2; 
 
        if (scanf("%d", &dollars) != 1)  
        { 
            printf("You did not type in the correct format in terms of dollars and cents.\n"); 
            break; 
        } 
 
        decimalPoint = getc(stdin); 
 
        if (decimalPoint != '.') 
        { 
            printf("You did not type in the correct format in terms of dollars and cents.\n"); 
            break; 
        } 
 
        cent1 = getc(stdin); 
        cent2 = getc(stdin); 
 
        if ((cent1 < '0') || (cent1 > '9') || (cent2 < '0') || (cent2 > '9')) 
        { 
            printf("You did not type in the correct format in terms of dollars and cents.\n"); 
            break; 
        } 
 
        ungetc(cent2, stdin); 
        ungetc(cent1, stdin); 
 
        scanf("%d", &cent); 
 
        if (cent >= 100) 
        { 
            printf("You did not type in the correct format in terms of dollars and cents.\n"); 
            break; 
        } 
         
        else 
        { 
            totalValueinCents = (dollars * 100) + cent; 
            break_down(totalValueinCents); 
        } 
        printf("Please enter total value:\n"); 
    } 
    
    
    

}
