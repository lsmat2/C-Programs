#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Hash Function Implementation (string --> int) */

unsigned int hashFunction(const char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++)) { /* while [current character (c) != end of string (\0)] ...then increments str pointer */
        hash = ((hash << 5) + hash) + c; 
        // hash * 33 + c       (known as djb2 hash)
        // int hash initialized to equal arbitrary prime number: 5381
        // for each char in str, hash is shifted left by 5 bits, then 'adds' current character integer value
    }

    return hash;
}



int main() {

    // Test that hashes are different for different strings
    char *str = "🍄";
    unsigned hash = hashFunction(str);
    printf("string: %s, hash: %d\n", str, hash);

    char *str2 = "HAHAHAHA testing lets see how this works!";
    unsigned hash2 = hashFunction(str2);
    printf("string: %s, hash: %d\n", str2, hash2);

    char *str3 = "🐳";
    unsigned hash3 = hashFunction(str3);
    printf("string: %s, hash: %d\n", str3, hash3);

    char *str4 = "🐙";
    unsigned hash4 = hashFunction(str4);
    printf("string: %s, hash: %d\n", str4, hash4);
    
    char *str5 = "🎱";
    unsigned hash5 = hashFunction(str5);
    printf("string: %s, hash: %d\n", str5, hash5);

    return 0;
}