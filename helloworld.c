#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void unknown(char *A)
{
    if (A == NULL || A[0] == 0) {
        return;
    }

    for (int i = 1; A[i] != 0; i++)
    {
        A[i] = A[i - 1];
    }
}

void analyze(char *s) {
    printf("In terms of num OF BYTES\n");
    int numElements = sizeof(s) / sizeof(s[0]);
    printf("Num bytes: %d \n", numElements);
    printf("Sizeof(s): %lu \n", sizeof(s));
    printf("Sizeof(s[0]): %lu \n", sizeof(s[0]));
}

void sizeOfPrimitives() {
    printf("Size of short: %zu\n", sizeof(short));
    printf("Size of int: %zu\n", sizeof(int));
    printf("Size of long: %zu\n", sizeof(long));
    printf("Size of long long: %zu\n", sizeof(long long));
    printf("Size of size_t: %zu\n", sizeof(size_t));
    printf("Size of void*: %zu\n", sizeof(void*));
    printf("Size of float: %zu\n", sizeof(float));
    printf("Size of double: %zu\n", sizeof(double));
}

void scratch() {
    char s2[8] = "CS@UIUC"; // Initialize a char array on the stack using a string literal

    char s3[8] = {'C','S','@','U','I','U','C','\0'}; // Initialize a char array on the stack using an array literal 

    char* s4 = malloc(8); // Dynamically allocate memory for a string then write a string literal to that memory
    strcpy(s4, "CS@UIUC");

    char* s5 = strdup("CS@UIUC"); // Same as using malloc and strcpy

    char* s = "CS@UIUC"; // Set a char pointer to point to string literal in read-only memory
    // REPRESENTATION:  0 1 2 3 4 5 6 7         NULL byte /0 is stored 'first'
    //                  C S @ U I U C /0        LITTLE-ENDIAN (STARTS AT END, READS FROM RIGHT TO LEFT BUT CONSTRUCTS IN THAT ORDER SO 'APPEARS' LEFT TO RIGHT)






    /*      STRING COMPARISONS

    int strcmp(const char *s1, const char *s2);
    int strncmp(const char *s1, const char *s2, size_t n);      -->     Given s1, s2 and some INTEGER n, strncmp will compare the first n bytes of each string.
    GUIDE:
    * 0 if s1 and s2 are the same, 
    * 1 if s1 is greater than s2
    * -1 if s2 is greater than s1. 
    Computing which string is "greater" is done by comparing the ASCII codepoints of the characters in the string one by one, 
    so strcmp can be used as a case-sensitive lexicographic comparison
    */
    int c1 = strcmp("A", "A");
    int c2 = strcmp("AB", "BA");
    int c3 = strcmp("BA", "AB");
    printf("%d\n", c1); // 0
    printf("%d\n", c2); // 1
    printf("%d\n", c3); // -1



    /*      PRINTF SPECIFIERS    "printf("%x", char)"
    
    %c	                Character
    %d	                Signed integer
    %e or %E	        Scientific notation of floats
    %f                  Float values
    %g or %G    	    Similar as %e or %E
    %hi	                Signed integer (short)
    %hu	                Unsigned Integer (short)
    %i	                Unsigned integer
    %l, %ld or %li	    Long
    %lf	                Double
    %Lf	                Long double
    %lu	                Unsigned int or unsigned long
    %lli or %lld	    Long long
    %llu	            Unsigned long long
    %o	                Octal representation
    %p	                Pointer
    %s	                String
    %u	                Unsigned int
    %x or %X	        Hexadecimal representation
    %n	                Prints nothing
    %%	                Prints % character
    */




    /*      STRING LENGTH

    int strlen(const char *s);
    NOTE: strlen will count the number of characters in s until it reaches the NULL byte. Put more simply, it will return the LENGTH of any string.
    */




    /*       STRING CONCATENATION

    char *strcat(char *dest, const char *src);          --->        "dest""src"
    char *strncat(char *dest, const char *src, size_t n);           --->        strncat performs about the same function, but only concatenates the first n bytes of src onto dest.
    
    Given two strings src and dest, 
    strcat will concatenate src onto dest. 
    strcat will also handle null bytes, 
    NOTE: REMOVING the null byte of dest and ADDING a null byte to the end of the concatenated string.
    */
    char c[24] = "I love ";
    strcat(c, "systems!\n");
    printf("%s", c);    // "I love systems!"




    /*      STRING COPY

    char *strcpy(char *dest, const char *src);
    - Given two character arrays dest and src,  strcpy will copy the contents of src into dest character by character (left to right), stopping when it reaches a null byte 
    NOTE: strcpy will also insert a terminating null byte.

    char *strncpy(char *dest, const char *src, size_t n);
    - strcpy but will stop copying from src into dest when EITHER:  it has copied n characters or when it reaches a null byte, depending on which comes first. 
    - CAREFUL: if strncpy does not reach the null byte before copying n characters, it will NOT insert the null byte into the character array it is copying into.
    

    char *strdup(const char *s);
    - NOTE: By contrast, strdup will create a duplicate of some string s, 
    allocate memory for that duplicate, 
    and return a pointer pointing to the first character of the duplicate. 
    - NOTE: In practice, using strdup is equivalent to malloc'ing the required amount of memory for a string 
    and then copying that string using strcpy. 
    As with anything that is malloc'ed, the duplicated string should be deallocated with free to avoid memory leaks.
    */
}






int main() {


    // printf("%d", strlen("ABCDEFG"));

    // char s[20];
    // strcpy(s, "CS340");
    // unknown(s);
    // printf("%s", s);

    int ch;

    for( ch = 33 ; ch <= 126; ch++ ) {
        printf("ASCII value = %d, Hex value = %x, Character = %c\n", ch, ch, ch);
    }

    scratch();
    char* p = "helloWORLD!!";
    analyze(p);
    sizeOfPrimitives();

    return 0;
}