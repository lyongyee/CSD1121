/*!
@file       q.c
@author     Lee Yong Yee (l.yongyee)
@course     CSD1121
@section    Section B
@tutorial   Lab03
@date       15/9/2023
@brief      This file contains the definitions of functions tile and dispense_change whose declarations can be found in q.h 
*/

#include "q.h"


/*
The tile function defined below is not meant to return a value, hence the void, it outputs a print statement of the Wall length, Tile width, Number of tiles and Gap at each end. 

It first prints out the Wall length and the Tile width using the values given in qdriver.c for the type double of wall_length and tile_width respectively.
Before it can print out the next statement, the calculations for how many pairs of tiles excluding the first tile is needed for the wall length,
thus we define int number_of_pairs as the result of wall_length - tile_width divided by the result of tile_width multiplied by 2. Then to get the final number of tiles
we take the previous int number_of_pairs multiplied by 2 + 1 to define our int number_of_tiles. We are then able to print the "Number of tiles" statement with the
int number_of_tiles. Finally before we print out the final statement, we must calculate the gap at each end, which is defined by double gap which is the result of
wall_length - number_of_tiles multiplied by tile_width, which is then divided by 2. Once we have the result of that we are able to print it with the "Gap at each end" statement
*/
void tile (double wall_length, double tile_width){

    printf("Wall length: %.2f | Tile width: %.2f\n",wall_length,tile_width);
    int number_of_pairs = (wall_length-tile_width)/(2*tile_width);
    int number_of_tiles = 1 + (2*number_of_pairs);
    printf("Number of tiles: %d\n", number_of_tiles);
    double gap = (wall_length - number_of_tiles * tile_width)/2;
    printf("Gap at each end: %.2f\n", gap);
}

/*
The dispense_change function defined below is not meant to return a value, hence the void. This function outputs the number of coins that add up to your change
based on the purchase price of your item and the money given 


For this function we need to define int dollars, cents and money_given so that we are able to tag it to the inputs read by the scanf statement.
To calculate the purchase price of the item we have to take dollars and mulitply it by 100 to convert it into the same form as cents. We can then define the
int purchase_price from the sum of the new dollars and cents. We need to also make sure the vlaue for money_given is in cents form so we multiply it by 100 as well
The int change can then be defined by the result of the money_given's value subtracteed by the purchase_price. From here is where we calculate how many coins of each type
will need to be given based on the change. For the calculation its is done in a way where the result will always be the largest possible coin denomination, so it will calculate
the maximum amount of loonies that need to be given, if the remainder of the change cannot be given in loonies it will then move on to calculate the maximum amount of half-loonies
needed to be given and so on.

*/


void dispense_change(void){
    
    int dollars,cents,money_given;
    scanf("%d.%d %d", &dollars,&cents, &money_given);
    int purchase_price = dollars*100 + cents;
    money_given = money_given*100;
    int change = (money_given - purchase_price);
    int loonies = change/100;
    int half_loonies = (change - (loonies*100))/50;
    int quarters = (change -(loonies*100) - (half_loonies*50))/25;
    int dimes = (change -(loonies*100) - (half_loonies*50) - (quarters*25))/10;
    int nickels = (change -(loonies*100) - (half_loonies*50) - (quarters*25) - (dimes*10))/5;
    int pennies = (change -(loonies*100) - (half_loonies*50) - (quarters*25) - (dimes*10) - (nickels*5))/1;
    printf("%d loonies + %d half-loonies + %d quarters + %d dimes + %d nickels + %d pennies\n", loonies, half_loonies, quarters, dimes, nickels, pennies);

}
