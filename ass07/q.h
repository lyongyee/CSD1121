/*!
@file       qdriver.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 7
@date       27/10/2023
@brief      This file contains the declarations of the following functions

            encrypt
            decrypt

            The definitions of these functions can be found in q.c
*/
#ifndef Q_H
#define Q_H

// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt

// TODO3: declaration for function encrypt
void encrypt(char *letter, char key_text);

// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt

// TODO5: declaration for function decrypt
void decrypt(char *letter, char key_text);

#endif // Q_H
