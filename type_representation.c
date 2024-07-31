#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLine() {
    printf("\n");
    for (int i = 0; i < 100; i++) { printf("-"); }
    printf("\n\n");
}

// Function to print binary representation of a value
void printBinary(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char*)ptr;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (byte[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

// Function to print hexadecimal representation of a value
void printHex(void *ptr, size_t size) {
    unsigned char *byte = (unsigned char*)ptr;
    for (int i = size - 1; i >= 0; i--) {
        printf("%02X ", byte[i]);
    }
    printf("\n");
}

// Function to print binary and hexadecimal forms of a primitive type
void printBinaryAndHex(void *value, size_t size) {
    printf("Binary: ");
    printBinary(value, size);

    printf("Hexadecimal: ");
    printHex(value, size);
}

// Function to print binary representation of a string
void printStringRepresentations(char *str) {
    size_t size = strlen(str);

    printf("\n\t\t");
    for (int i = 0; i < size; i++) { printf("%c\t\t", str[i]); }

    printf("\nDecimal:\t");
    for (int i = 0; i < size; i++) { printf("%d\t\t", str[i]); }

    printf("\nBinary:\t\t");
    for (int i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) { printf("%d", (str[i] >> j) & 1); }
        printf("\t");
    }
    
    printf("\nHexadecimal:\t");
    for (int i = 0; i < size; i++) { printf("%02X\t\t", str[i]); }
}

void requestAndPrintWordInfo() {
    char word[30];
    printf("Enter your word: \n");
    scanf("%s", word);
}

void printInfoForever() {
    char word[30];
    printf("\n\nEnter a word to see it's binary, hexadecimal, and more representations! (enter q or ctrl+C to quit)\n");
    printLine();
    printf("\n");
    while (1) {
        printf("Your word: ");
        scanf("%s", word);
        if (strcmp(word, "q") == 0) { return; }
        else { printStringRepresentations(word); }
        printf("\n");
        printLine();
    }
}


int main() {
    
    printInfoForever();

    return 0;
}

    // int intValue = 42;
    // float floatValue = 3.14;
    // char charValue = 'A';
    // const char* string = "Programming Rocks!";
    // char ex = 'c';
    // printBinaryAndHex(&ex, sizeof(char));

    // printBinaryAndHex(ex2, strlen(ex2)*sizeof(char));
    // printf("Integer: %d\n", intValue);
    // printBinaryAndHex(&intValue, sizeof(int));
    // printf("\nFloat: \n");
    // printBinaryAndHex(&floatValue, sizeof(float));
    // printf("\nCharacter: %c\n", charValue);
    // printBinaryAndHex(&charValue, sizeof(char));
    // printf("\nString: %s\n", &string);
    // puts(string);
    // printBinaryString(&string);
    // printBinaryAndHex(&string, sizeof(string));
    // short x = - 0x40;
    // printf("\n short x: - 0x40 \n");
    // printBinaryAndHex(&x, sizeof(short));
    // short y = ~ 0x40;
    // printf("\n short y: ~ 0x40 \n");
    // printBinaryAndHex(&y, sizeof(short));