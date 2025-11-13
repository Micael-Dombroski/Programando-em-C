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
  // the bitwise AND (&) operator compares bits of 2 numbers bit by bit
  /* Examples:
    A B A & B
    0 0   0
    0 1   0
    1 0   0
    1 1   1 //it returns true only if both bits is 1
  */
  //the bitwise OR (|) operator compares bits of 2 numbers bit by bit
  /* Examples:
    A B A & B
    0 0   0
    0 1   1
    1 0   1
    1 1   1 
    //it returns 1 if at least one of the bits is 1
  */
  //the bitwise exclusive OR (^) operator compares bits of 2 numbers bit by bit
  /* Examples:
   A B A ^ B
   0 0   0
   0 1   1
   1 0   1
   1 1   0
   //it returns 1 only if exactly one of the bits is 1
  */
  /*Bit position	Binary value (1 << n)	Description
    bit0	        00000001	            least significant bit
    bit1	        00000010	            2nd bit from right
    bit2	        00000100	            3rd bit from right
    bit3	        00001000	            4th bit from right
    bit4	        00010000	            5th bit from right
    bit7	        10000000                most significant bit
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

    a = 30;
    b = 19;
    int c = a & b;
    printf("%d & %d = %d\n", a, b, c);
    c = a && b;
    printf("%d & %d = %d\n", a, b, c);
    b = 0;
    c = a && b;
    printf("%d & %d = %d\n", a, b, c);
    //you can use the bitwise AND(&) to check whether a specific bit is on or off
    //this is useful when you're working with microcontrollers
    a = 73; //0000.0000.01001001
    b = a & (1 << 3); //mask 0000.0000.0000.1000 (1 << 3), to verify the 3rd bit
    /* 1 << 3 is the same as
        0000.0000.0000.0001 is the 1 represented in binary
        with 1 << 3 move 1 three bits to the left
        0000.0000.0000.1000
        So when we use the bitwise AND operator, if bit3 in both 
        numbers is 1, the resul will contain the value corresponding
        to that bit position
    */
    //0000.0000.0100.1001
    //0000.0000.0000.1000
    //0000.0000.0100.T001 the bit3 from 73 is 1
    printf("a: %d\tb: %d\n", a, b);
    b = a & (1 << 4); //mask 00010000 (1 << 4), to verif the 4th bit
    //0000.0000.0100.1001
    //0000.0000.0001.0000
    //0000.0000.010F.1001 the bit4 from 73 is 0
    printf("a: %d\tb: %d\n", a, b);//bit4 is off

    //check if the number is odd or even using bitwise AND
    int n = 97; //0000.0000.0110.0001
    if(n & 1) { //0000.0000.0000.0001 - odd numbers always end with 1 in binary
        printf("Odd number\n");
        //this comparison is faster than n%2 != 0 'cause it checks
        //the last bit directly instead of doing a division
    } else {
        printf("Even number\n");
    }
    printf("%d\n", 5 & 7);
    //0000.0000.0000.0101
    //0000.0000.0000.0111
    //0000.0000.0000.0TFT -> 0000.0000.0000.0101 -> 5/

    a = 30;     //0000.0000.0001.1110
    b = 19;     //0000.0000.0001.0011
                //0000.0000.000T.TTTT
    c = a | b;  //0000.0000.0001.1111  -> 31
    printf("%d | %d = %d\n", a, b, c);
    c = a || b; //0000.0000.0000.0001 logical OR evaluates to 1(since both are nonzero)
    printf("%d | %d = %d\n", a, b, c);
    //you can use bitwise OR (|) to turn a specific bit ON
    a = 1;
    b = a | (1 << 1); //0000.0000.0000.0010 -> 3
    printf("a: %d\tb: %d\n", a, b);//bit1 is on
    b = a | (1 << 2); //0000.0000.0000.0100 -> 5
    printf("a: %d\tb: %d\n", a, b);//bit2 is on

    //the bitwise XOR is useful when we need to invert/toggle the state of a bit
    a = 73; //0000.0000.0100.1001
    b = a ^ (1 << 3); //(1 << 3) to invert the bit3
    //0000.0000.0100.1001 -> 73
    //0000.0000.0000.1000 -> 8
    //0000.0000.0T00.F00T -> 65
    printf("a: %d\tb: %d\n", a, b);//bit3 is off -> the result is 65
    b = b ^ (1 << 3); //0000.0000.0000.1000
    printf("a: %d\tb: %d\n", a, b);//bit3 is on -> the result is 73
    //0000.0000.0100.0001 -> 65
    //0000.0000.0000.1000 -> 8
    //0000.0000.0T00.T00T -> 73
    

    return EXIT_SUCCESS;
}