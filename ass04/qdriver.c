#include <stdio.h>
#include "q.h"

int main(void){
    
    int value;
    while (1 == scanf("%d", &value)) {
        if (value <= 0 || value >= 4000){
            continue;
        }

        printf("%d: ", value);
        decimal_to_roman(value);
        
        
    }

    
    return 0;
}