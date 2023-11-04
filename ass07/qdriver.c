/*!
@file       qdriver.c
@author     l.yongyee
@course     CSD1121
@section    Section B
@assignment 7
@date       27/10/2023
@brief      This file contains the definitions of the int main function

            The declarations of these functions can be found in q.h
*/

#include "q.h"			// encrypt and decrypt function declarations
// TODO2: Add necessary C standard library headers ...
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {

	
	char keyArray[256];
	char ch;
	int keyIndex = 0;
#ifdef ENCRYPT
	
	FILE *plainOpen, *plainOut, *keyOpen;
	
	plainOpen = fopen("plain.txt","r");
	keyOpen = fopen("key.txt","r");
	plainOut = fopen("cipher.txt","w");
	

	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt
	
	
	if (plainOpen == NULL || keyOpen == NULL || plainOut == NULL){
		perror("Unable to open files");
		return 1;
	}

	if (fgets(keyArray, sizeof(keyArray), keyOpen) == NULL) {
    perror("Failed to read the keyword from key.txt");
    
    return 1;
	}

	
	while ((ch=(char)fgetc(plainOpen)) !=EOF){
		int keyArrayLen = (int)strlen(keyArray);
		keyIndex = (keyIndex) % (keyArrayLen-1);
		encrypt(&ch, keyArray[keyIndex]);
		fputc(ch,plainOut);
		++keyIndex;
		
	}

	fclose(plainOpen);
	fclose(keyOpen);
	fclose(plainOut);
	
#else

	
	FILE *plainOut, *keyOpen,*outPlain;
	int wordCount = 0;
	int inWord = 0;
	
	keyOpen = fopen("key.txt","r");
	plainOut = fopen("cipher.txt","r");
	outPlain = fopen("out-plain.txt","w");

	

	// TODO4: read characters from input file cipher.txt and write the
	// corresponding decrypted characters to output file out-plain.txt
	// using the keyword in file key.txt
	if (outPlain == NULL || keyOpen == NULL || plainOut == NULL){
    perror("Unable to open files");
    return 1;
	}

	if (fgets(keyArray, sizeof(keyArray), keyOpen) == NULL) {
		perror("Failed to read the keyword from key.txt");
		return 1;
	}

	keyIndex = 0;
	while ((ch = (char)fgetc(plainOut)) != EOF) {
		int keyArrayLen = (int)strlen(keyArray);
		keyIndex = keyIndex % (keyArrayLen - 1);
		decrypt(&ch, keyArray[keyIndex]);
		fputc(ch, outPlain);
		++keyIndex;

		  // 1 when in a word, 0 when not in a word

		if (isalnum((int)ch)) {
			
				inWord = 1;
				
			
		} else if(isspace((int)ch)){
			if(inWord == 1){
				inWord = 0;
				wordCount++;
			}
		} 

		
	}

	
	fprintf(stderr, "Words: %d\n", wordCount);

	fclose(keyOpen);
	fclose(plainOut);
	fclose(outPlain);

#endif

	return 0;
}
