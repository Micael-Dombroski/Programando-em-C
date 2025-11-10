#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // << 1 shifts bits one position to the left, 
    //equivalent to multiplying by 2 one time
    // >> 3 shifts bits three positions to the right, 
    //equivalent to dividing by 2 three times
    /* Examples:
        a = 10; 10 is 00001010
        b = a >> 1 the same as 0000101X -> 00000101

        Remember, this is just an example, the numbers are 
        represented with 4 bytes (32 bits) nowadays
    */
   // the '~' operator inverts all bits (bitwise NOT)
   /* Examples: 
        a = 10; 10 is 00001010
        b = ~a; so b is 11110101 so b is -11
        c = 2; 2 is 00000010
        d = ~c; so d is 11111101 so d is -3
   */

    int a, b;
    a = 1;
    b = a << 1;
    printf("a: %d\tb: %d\n", a, b);
    b = ~a;
    printf("a: %d\tb: %d\n", a, b);

    b = a << 2;
    printf("a: %d\tb: %d\n", a, b);

    b = a >> 1;
    printf("a: %d\tb: %d\n", a, b);

    a= 10;
    b = a >> 2;
    printf("a: %d\tb: %d\n", a, b);

    b = a << 4;
    printf("a: %d\tb: %d\n", a, b);
    return EXIT_SUCCESS;
}