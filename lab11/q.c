/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@lab        11
@date       17/11/2023
@brief      This file contains the definitions of the print_data function. The declarations of this function can be found in q.h
*/

#include "q.h"



/*
 * @brief Prints formatted data from a memory block.
 *
 * This function takes a pointer to a memory block, the size of the block,
 * and a span value to control the number of elements per line in the output.
 * It prints the hexadecimal and ASCII representations of the data in a
 * formatted manner.
 *
 * @param ptr Pointer to the memory block to be printed.
 * @param size Size of the memory block in bytes.
 * @param span Number of elements to be displayed per line.
 *
 * The function prints the hexadecimal representation of the data, followed by
 * the ASCII representation. The output is formatted with the specified number
 * of elements per line, making it easier to read and understand.
 * 
 * The output format is as follows:
 * ```
 * Hex1 Hex2 Hex3 Hex4   |   ASCII1 ASCII2 ASCII3 ASCII4
 * Hex5 Hex6 Hex7 Hex8   |   ASCII5 ASCII6 ASCII7 ASCII8
 * ...
 * ```
 * 
 * The function handles newline characters appropriately to ensure a clear
 * separation between lines.
 */
void print_data(const void* ptr, size_t size, size_t span){

    
        const unsigned char* character = ptr;
        
        
       for(size_t all_counter = 0; all_counter < size/span; all_counter++){

        

        for (size_t counter = 0; counter < span; counter++){
            
            
            
            printf("%02x",character[counter + (all_counter *span)]);

            if((counter+1)%span == 0 && (counter+1) < size){
                printf("   |   ");
            }else if((counter+1)%4 ==0 && (counter+1) < size){
                printf("   ");
            }else{
                printf(" ");
            }
            
            
            
        }

        

        for (size_t counter = 0; counter < span; counter++){
            
            
            
            printf("%c",character[counter + (all_counter *span)]);
            if((counter+1)%span == 0 && (counter+1) < size){
                printf("\n");
            }else if((counter+1)%4 ==0 && (counter+1) < size){
                printf("   ");
            }else{
                printf(" ");
            }

            
        
        }

        }

}