/*!
@file       q.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 7
@date       27/10/2023
@brief      This file contains the definitions of the following functions

            encrypt
            decrypt

            The declarations of these functions can be found in q.h
*/

#include "q.h" // included because q.c requires access to ASCII_COUNT

// TODO2: include other C standard library headers. for reasons 
// explained in previous assignments/labs, think carefully about 
// the need to add an include file before you do so ...

// TODO3: define functions encrypt and decrpyt ...


void encrypt(char *letter, char key_text){

    int asciiCipher;  
    

    if((*letter + key_text) > ASCII_COUNT){
        
        asciiCipher = *letter + key_text - ASCII_COUNT;
        
    }else{
        
        asciiCipher = *letter + key_text;    
        
    }   
        
    *letter = (char)asciiCipher;

}

void decrypt(char *letter, char key_text){

    int asciiPlain;
    
    if((*letter - key_text) < 0){
        
        asciiPlain = *letter - key_text + ASCII_COUNT;
        

    }else{
        
        asciiPlain = *letter - key_text;
        
    }
    

    *letter = (char)asciiPlain;;
}