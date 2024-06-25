#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
void printStringInfo(char *str) {
    size_t size = strlen(str);
    printf("\nInput: %s\n\n", str);

    printf("Human:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%c\t", str[i]);
    }

    printf("\nDecimal:\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", str[i]);
    }

    printf("\nBinary:\t\t");
    for (int i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (str[i] >> j) & 1);
        }
        printf(" ");
    }
    
    printf("\nHexadecimal:\t");
    for (int i = 0; i < size; i++) {
        printf("%02X\t", str[i]);
    }

    printf("\n\n");

}

int main() {
    // Initialize string(s)
    char *ex1 = "Name 1!";
    char *ex2 = "hello";
    char *ex3 = "how are you";
    char *ex4 = "exampleee";
    char *ex5 = "lets try this!";
    // Call  print function
    printStringInfo(ex1);
    printStringInfo(ex2);
    printStringInfo(ex3);
    printStringInfo(ex4);
    printStringInfo(ex5);

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