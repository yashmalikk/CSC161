
/*
* A program to count Bigrams in a string.
* Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
* Date: Feb. 19th, 2024
*/

#include <stdio.h>
#include <string.h>
int main(){
    char input[1000];                        /* Variable that will store user input*/
    int bgramcount[256][256]={0};            /*2D matrix to store bigram and count*/
    char common[3];                         /*Variable that will have the most common bigram*/
    int bgramcounter[256][256];             /*another matrix to store bigram and count*/

    printf("Enter a string: ");
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != -1 && i < 1000 - 1)  /*runs until newline charater or max character limit is reached*/
    {
        input[i++] = c;
    }
    input[i] = '\0';        /*adds \0 to the end of array, making it a string*/
    if (strlen(input)>1){               /*if-else block to only run if input has atleast one bigram*/
        for (int i = 0; i < strlen(input) - 1; i++)             /*adds all bgram combinations to bgramcounter*/
        {
            int firstChar = (char)input[i];
            int secondChar = (char)input[i + 1];
            bgramcounter[firstChar][secondChar]++;
        }
        int maxCount = 0;                       /*variable that will have the count of most occuring bgram*/
        char mostCommon[3] = {0};               
        for (int i = 0; i < 256; i++) {                 /*both for loops to run together so each bgram is fetched only once*/
            for (int j = 0; j < 256; j++) {
                if (bgramcounter[i][j] > maxCount) {            /*if the count of one bgram is more than the previous highest, replaces the most occuring bgram stored*/
                    maxCount = bgramcounter[i][j];
                    mostCommon[0] = (char)i;
                    mostCommon[1] = (char)j;
                }
            }
        }
        strcpy(common, mostCommon);
        printf("Bigram counts:\n");
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < 256; j++) {             /*cycles and prints all bgram combinations*/
                if (bgramcounter[i][j] > 0) {           
                    printf("%c%c: %d\n", (char)i, (char)j, bgramcounter[i][j]);
                }
            }
        }
    printf("Most common bigram: '%s' \n", mostCommon);          /*prints only most occuring bgram*/
}
else{
    printf("The input did not contain any bigrams.");
}
    return 0;
}
