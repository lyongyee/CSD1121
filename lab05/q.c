/*!
@file       q.c
@author     Lee Yong Yee (l.yongyee)
@course     CSD1121
@section    Section B
@tutorial   Lab05
@date       29/9/2023
@brief      This file contains the definitions of functions cost and rev whose declarations can be located in the q.h file 
*/

#include "q.h" //Links to q.h file


/* The function cost determines the cost of an automobile insurance premium by taking into
   consideration the age of the driver and the number of accidents that the driver has had.



   The conditions for the insurance are as follows:
   - To be eligible for the insurance you have to be more than 16 years of age.
   - There is a surcharge for $50 if the driver under 25 years of age and an additional surchage based the number of accidents
   they had

   For us to calculate the cost and the eligibility of the driver, we must read the driver's age and accident record from the input provided where the first
   number age of the driver and the number that follows after the comma is the number of accidents. We will store the 

   The first check that we will run is checking if the driver's age is more or equal to 16 years old, if the condition returns false, we will printf the following
   statement

   age = (inputted age that is less than 16 years old), accidents  = (inputted number of accidents), no insurance coverage!

   If the condition for the first check returns true, we will then move on to the 2nd check, which is checking if the driver's age is more than 25 or less than 25. If the driver's age
   is more than 25, there will be no surcharge based on his age and the current value of his insurance will be just 500. If the driver's age is less than 25, then we will a surchage of 50
   to his based on his age and the current value of his insurance as of now will be 550.

   The check after that will be checking the number of accidents the driver has had. If the driver has had more than 5 accidents, the driver will not have any insurance coverage. If the driver
   has had less than 5 accidents, we will then use a switch case to calculate how much the surcharge will be based on the number of accidents the driver has had.

   One these 3 checks have concluded, we will printf the following statement

   age = (inputted age that is less than 16 years old), accidents  = (inputted number of accidents), insurance cost = (final calculation based on the base cost and the surcharge)


*/
void cost(void){

// int ageOfDriver;
// int numOfAccidents;
// int insuranceCost;


// scanf("%d,%d", &ageOfDriver,&numOfAccidents);

// if(ageOfDriver >= 16){

//     if(ageOfDriver >= 25){
//         insuranceCost = 500;
//     }else if(ageOfDriver < 25){
//         insuranceCost = 550; 
//     }

//     if(numOfAccidents < 5){
//     switch(numOfAccidents){
//         case 1:
//         insuranceCost += 100;
//         break;
//         case 2:
//         insuranceCost += 100;
//         break;
//         case 3:
//         insuranceCost += 225;
        
//         break;
//         case 4:
//         insuranceCost += 225;
        
//         break;
//     }
//     printf("age = %d, number of accidents = %d, insurance cost = %d\n", ageOfDriver, numOfAccidents, insuranceCost);

//     } else{
        
//         printf("age = %d, number of accidents = %d, no insurance coverage!\n", ageOfDriver, numOfAccidents);

//     }
    
    
   

// }else {
//     printf("age = %d, number of accidents = %d, no insurance coverage!\n", ageOfDriver, numOfAccidents);
    
// }




}

/* The rev function output the reverse of the input given. To do this we will use a while loop that will run if the number does not equal to zero,


*/
void rev(void){

    int inputGiven;
    int reversedNumber = 0;
    int remainder;
    int width = 0;

    scanf("%d", &inputGiven);

    

    while (inputGiven != 0 ){
        remainder = inputGiven % 10;
        reversedNumber  = reversedNumber * 10 + remainder; 
        inputGiven /= 10;
        width++;
    }

    
    printf("%0*d\n",width, reversedNumber);

}