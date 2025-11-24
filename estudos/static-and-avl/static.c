#include <stdio.h>
#include <stdlib.h>

/*
    The 'static' keyword gives a variable static storage duration, 
    meaning it is allocated only once and keeps its value between 
    function calls. When used inside a function, it creates a local 
    variable that persists across calls rather than being recreated 
    each time. When used at global scope, 'static' restricts the variable
    or function so it is only visible within that source file (internal 
    linkage).
*/

static int value = 10;
//This global variable has internal linkage, so it is visible only in
//this file. If you declare a global variable without 'static', it will
//have external linkage, meaning it can be accessed from other files
//using 'extern'

float even_average(int array[], int size) {
    static int sum = 0, qtt = 0;
    if(size == 0) {
        return (sum * 1.0) / qtt;
    } else {
        if(array[size - 1] % 2 == 0) {
            sum += array[size -1];
            qtt++;
            return even_average(array, size - 1);
        } else {
            return even_average(array, size - 1);
        }
    }
}

int main(void) {
    int array[6] = {2, 4, 38, 7, 11, 9};
    printf("Average of even numbers: %f\n", even_average(array, 6));
    return EXIT_SUCCESS;
}