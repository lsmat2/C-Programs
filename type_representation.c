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
    printf("Input: %s\n", str);
    size_t size = strlen(str);
    printf("Binary: ");
    for (int i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (str[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\nHexadecimal: ");
    for (int i = 0; i < size; i++) {
        printf("%02X ", str[i]);
    }
    printf("\n");

}

int main() {
    // Test the function with different types
    // int intValue = 42;
    // float floatValue = 3.14;
    // char charValue = 'A';
    // const char* string = "Programming Rocks!";
    // char ex = 'c';
    // printBinaryAndHex(&ex, sizeof(char));

    // printBinaryAndHex(ex2, strlen(ex2)*sizeof(char));
    char *example = "Example!";
    printStringInfo(example);

    char *example2 = "yayayay!";
    printStringInfo(example2);
    
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

    return 0;
}