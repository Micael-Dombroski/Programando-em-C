#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        else
            return nthNumberFromFibonacciSequence(n-1) + nthNumberFromFibonacciSequence(n - 2);
    }
}
//fibonacci with recursion is not efficient, to get the 6th number the 
//function must be called 14 times after the call in main
int xToPowerOfN(int x, int n) {
    if (n == 0) return 1;
    return x * xToPowerOfN(x, n - 1);
}
int sumFrom1ToN(int n) {
    if(n == 0) return 0;
    else {
        if(n == 1) return 1;
        return n + sumFrom1ToN(n - 1);
    }
}
int sumOfTheNumbersInArray(int nums[], int index) {
    if(index - 1 == 0) return nums[0];
    else {
        return nums[index - 1] + sumOfTheNumbersInArray(nums, index - 1);
    }
}
int greaterValueInTheArray(int nums[], int index, int gIndex) {
    if(index == 0) return nums[gIndex];
    else {
        if(nums[index - 1] > nums[gIndex])
            return greaterValueInTheArray(nums, index - 1, index - 1);
        else
            return greaterValueInTheArray(nums, index - 1, gIndex);
    }
}
void reverseArray(int arr[], int start, int end) {
    if(start >= end) return;
    int copy = arr[end-1];
    arr[end-1] = arr[start];
    arr[start] = copy;
    reverseArray(arr, start + 1, end - 1);
}
void printArray(int arr[], int size) {
    if(size == 1)
        printf("%d ", arr[size - 1]);
    else {
        printf("%d ", arr[size - 1]);
        printArray(arr, size - 1);
    }
}
void printReverseArray(int arr[], int size) {
    if(size <= 0)
        return;
    else {
        printReverseArray(arr, size - 1);
        printf("%d ", arr[size - 1]);
    }
}
int main(void) {
    int n1, n2;
    printf("Write two integers positive numbers: \n");
    scanf("%d%d", &n1, &n2);
    printUntil0(n1);
    printf("\n");
    printUntilN(n1);
    printf("\nFactorial of %d: %d\n", n1, factorial(n1));
    if (n1 > 0) {
        printf("The elemente number %d from Fibonacci sequence is: %d\n", n1, nthNumberFromFibonacciSequence(n1));
        printf("%d to power of %d is: %d\n", n1, n2, xToPowerOfN(n1, n2));
    }
    printf("Sum from 1 to %d: %d\n", n1, sumFrom1ToN(n1));
    int size;
    printf("Write the size of the array: \n");
    scanf("%d", &size);
    int nums[size];
    if(size > 0) {
        for(int i = 0; i < size; i++) {
            int ret = 0;
            do {
                printf("Write the number in position %d: \n", i);
                ret = scanf("%d", &nums[i]);
            } while (ret != 1);
        }
        printf("Sum of the numbers ");
        printArray(nums, size);
        printf("is: %d\n", sumOfTheNumbersInArray(nums, size));
        printf("The greater value in the array is: %d\n", greaterValueInTheArray(nums, size, 0));
        printArray(nums, size);
        printf("\n");
        reverseArray(nums, 0, size);
        printArray(nums, size);
        printf("\n");
        printReverseArray(nums, size);
        printf("\n");
    }
    
    return 0;
}