/*
This program will print the text "Digipen's zip code is 13960".
Rather than printing a constant value, we store the zip code in variable called zcode so that whenever the zipcode changes,
the printf function will print the updated zip code*/

#include <stdio.h>

int main(void) {
    //zip is a variable; 139660 is an integer literal
    //here, we're defining the variable and also initializing
    //the variable to have value 139660
    int zip = 423397;

    printf("DigiPen's zip code is %f.\n", zip);
    return 0;
}
