#include "q.h"

void initialize(int latin_freq[], int size, int *ctrl_cnt, int *non_latin_cnt){
    for(int i = 0; i<size; i++){
        latin_freq[i] = 0;
    }
    *ctrl_cnt = 0;
    *non_latin_cnt = 0;
}

void wc(FILE *ifs, int latin_freq[], int *ctrl_cnt, int *non_latin_cnt){
    //to use fgetc
    //if a character is a latin character, the corresponding element in latin_freq must be incremented
    //size of latin_freq is at least 26
    //if the character is a control character e.g. \a,\b, ctrl_cnt must be incremented
    int ch;
    while((ch = fgetc(ifs)) != EOF){
        
            switch(ch){
                case 'a':
                case 'A':
                latin_freq[0]++;
                break;
                case 'b':
                case 'B':
                latin_freq[1]++;
                break;
                case 'c':
                case 'C':
                latin_freq[2]++;
                break;
                case 'd':
                case 'D':
                latin_freq[3]++;
                break;
                case 'e':
                case 'E':
                latin_freq[4]++;
                break;
                case 'f':
                case 'F':
                latin_freq[5]++;
                break;
                case 'g':
                case 'G':
                latin_freq[6]++;
                break;
                case 'h':
                case 'H':
                latin_freq[7]++;
                break;
                case 'i':
                case 'I':
                latin_freq[8]++;
                break;
                case 'j':
                case 'J':
                latin_freq[9]++;
                break;
                case 'k':
                case 'K':
                latin_freq[10]++;
                break;
                case 'l':
                case 'L':
                latin_freq[11]++;
                break;
                case 'm':
                case 'M':
                latin_freq[12]++;
                break;
                case 'n':
                case 'N':
                latin_freq[13]++;
                break;
                case 'o':
                case 'O':
                latin_freq[14]++;
                break;
                case 'p':
                case 'P':
                latin_freq[15]++;
                break;
                case 'q':
                case 'Q':
                latin_freq[16]++;
                break;
                case 'r':
                case 'R':
                latin_freq[17]++;
                break;
                case 's':
                case 'S':
                latin_freq[18]++;
                break;
                case 't':
                case 'T':
                latin_freq[19]++;
                break;
                case 'u':
                case 'U':
                latin_freq[20]++;
                break;
                case 'v':
                case 'V':
                latin_freq[21]++;
                break;
                case 'w':
                case 'W':
                latin_freq[22]++;
                break;
                case 'x':
                case 'X':
                latin_freq[23]++;
                break;
                case 'y':
                case 'Y':
                latin_freq[24]++;
                break;
                case 'z':
                case 'Z':
                latin_freq[25]++;
                break;
                case '\a':
                case '\f':
                case '\b':
                case '\n':
                case '\r':
                case '\t':
                case '\v':
                *ctrl_cnt += 1;
                break;
                default:
                *non_latin_cnt += 1;
                

            }
        
    }
}

void print_freqs(int const latin_freq[], int size, int const *ctrl_cnt, int const *non_latin_cnt){
    int latin_cnt = 0;

    for(int i =0; i<size; i++){
        latin_cnt += latin_freq[i];
    }
    

    for(char c = 'a'; c <= 'z'; c++){
        
        if(c == 'z'){
            fprintf(stdout,"%c\n", c);
        }
        else{
            fprintf(stdout,"%c         ", c);
        }
        
        
    }
    for(int p = 0; p<size; p++){
        fprintf(stdout,"%-10d", latin_freq[p]);
    }
    

fprintf(stdout,"\n");
fprintf(stdout,"\n");

fprintf(stdout,"Latin Letters     :%8d\n",latin_cnt);
fprintf(stdout,"Non-Latin Letters :%8d\n", *non_latin_cnt);
fprintf(stdout,"Control Letters   :%8d\n",*ctrl_cnt);

}


