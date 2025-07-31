#include <stdio.h>
#include <stdlib.h>

//recursive procedure that prints numbers from N until 0
void printUntil0(int n) {
    if(n < 0) return;
    printf("%d ", n);
    printUntil0(n - 2);
}
//recursive procedure that prints numbers from 0 until N
void printUntilN(int n) {
    if(n  < 0) return;
    printUntilN(n - 1);
    printf("%d ", n);
    
}
int main(void) {
    int n;
    printf("Write a number: \n");
    scanf("%d", &n);
    printUntil0(n);
    printf("\n");
    printUntilN(n);
    return 0;
}