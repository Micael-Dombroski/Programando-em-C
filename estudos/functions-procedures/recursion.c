#include <stdio.h>
#include <stdlib.h>

//recursive procedure that prints numbers from N until 0
void printUntil0(int n) {
    if(n < 0) return;
    printf("%d ", n);
    printUntil0(n - 1);
}
//recursive procedure that prints numbers from 0 until N
void printUntilN(int n) {
    if(n  < 0) return;
    printUntilN(n - 1);
    printf("%d ", n);
    //print when the program statis to "unwind" the stack
}
int factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
//When a recursive function/procedure is called, the computer
//uses a stack to keep track of the current function/procedure calls.
//Once the base condition to stop the recursion is met, the program 
//starts to "unwind" the stack, returning from each recursive call.
int nthNumberFromFibonacciSequence(int n) {
    if(n == 1)
        return 0;
    else {
        if(n == 2)
            return 1;
        else {
            return nthNumberFromFibonacciSequence(n-1) + nthNumberFromFibonacciSequence(n - 2);
        }
    }
}
int main(void) {
    int n;
    printf("Write a number: \n");
    scanf("%d", &n);
    printUntil0(n);
    printf("\n");
    printUntilN(n);
    printf("\nFactorial of %d: %d\n", n, factorial(n));
    printf("The elemente number %d from Fibonacci sequence is: %d\n", n, nthNumberFromFibonacciSequence(n));
    return 0;
}