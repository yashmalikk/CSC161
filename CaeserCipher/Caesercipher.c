/*
* A program to encrypt/decrypt a string.
* Author: Yash Malik
* Class: CSC161 w/ Prof. Jimenez 
* Date: Mar. 5th, 2024
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100


            // Function to perform Caesar Cipher encryption for a given shift
void encrypt(char *input, int shift){
    int i = 0;
    while (input[i]) {                                          // algorithm to encode
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = 'a' + (input[i] - 'a' + shift) % 26;
        }
        i++;
    }
}


            // Function to perform Caesar Cipher decryption for a given shift
void decrypt(char *input, int shift){
    int i = 0;
    while (input[i]) {              //algorithm to decode
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = 'a' + (input[i] - 'a' - shift + 26) % 26;
        }
        i++;
    }
}


            // Function to print all possible Caesar Cipher shifts
void printAllShifts(char *input, char option) {
    for (int shift = 0; shift < 26; shift++){               // for loop to print all shifts
        char result[MAX_LENGTH + 1];
        strcpy(result, input);
        if (option == 'e') {
            encrypt(result, shift);
        } else if (option == 'd') {
            decrypt(result, shift);
        }
        printf("n = %d: %s\n", shift, result);
    }
}


int main() {
    char input[MAX_LENGTH + 1];
    char option;
    printf("This program encrypts and decrypts messages using the Caesar Cipher.\n");
    printf("Enter 'e' to encode or 'd' to decode: ");
    scanf(" %c", &option);

    if (option == 'e'){
        printf("Enter the string to encode: ", MAX_LENGTH);
        scanf("%100s", input);

        printAllShifts(input, 'e');
    } 

    else if (option == 'd'){
        printf("Enter the string to decode: ", MAX_LENGTH);
        scanf("%100s", input);
        printAllShifts(input, 'd');
    } 

    else{
        printf("Valid options are 'e' to encode or 'd' to decode.\n");
    }

    return 0;
}
