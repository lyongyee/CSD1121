#include <stdio.h> 

int main(void) {
    printf("Enter a price in dollars and cents & money given:  "); 
    int dollars, cents, money_given; 
    scanf("%d.%d %d", &dollars, &cents, &money_given); 
    printf("Price read by scanf: %d.%d %d\n", dollars, cents, money_given); 
    return 0; 
    }