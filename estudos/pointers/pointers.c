#include <stdio.h>
#include <stdlib.h>
//A pointer is a variable that stores the memory address of another variable
//The pointer's type must match the type of the value whose address it stores
void printByCopy(int num) {
    printf("%d\n", num);
    num = 80;
    //change the copy value
}
void printByReference(int *num) {
    printf("%d\n", *num);
    *num = 75;
    //change the value in the memory address pointed by num
}
void printArray(int nums[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
void modifyArray(int nums[], int size) {
    for (int i = 0; i < size; i++)
        nums[i] = nums[i] * 2;
    //functions/procedures receive the array's address instead of a copy,
    //so modifying the array insite the function also changes the original
    /*
        To modify an array only inside a function, create a new array
        and copy the original array's values into it.
    */
}
int main(void) {
    int age = 12;
    int *p;
    p = &age;
    char *p2;
    float *p3;
    printf("age value: %d\n", age);//value of age
    printf("age address: %p\n", &age);//memory address of age
    printf("p value: %p\n", p);//value of p
    printf("p address: %p\n", &p);//memory address of p
    printf("Value pointed by p: %d\n", *p);//value at the address pointed to by p
    //Determines how much memory a pointer uses
    printf("int pointer size: %d\n", sizeof(p));
    printf("char pointer size: %d\n", sizeof(p2));
    printf("float pointer size: %d\n", sizeof(p3));
    //A pointer's size is the same regardless of the type of variable it points to
    char word[100];
    /*scanf("%100[^\n]", word);
    printf("\n%s\n", word);*/
    printf("%p\n", word);//memory address of the word[0]
    printf("%p\n", &word);//memory address of the word[0]
    printf("%p\n", &word[0]);//memory address of the word[0]
    //When you create an array, its name is arready a pointer by default
    //That's why we don't use "&" with scanf when reading strings, for example
    printByCopy(age);
    printf("age value: %d\n", age);
    //passing by value does not change the original variable, only its copy
    printByReference(&age);
    printf("age value: %d\n", age);
    //passing a variable's memory address as a pointer parameter allows its
    //value to be modified directly
    int arr[5] = {0,25,11,8,-1};
    printArray(arr, 5);
    modifyArray(arr, 5);
    printArray(arr, 5);
    //when the function receive an array as an argument the program sends a pointer
    //to that array instead
    return 0;
}