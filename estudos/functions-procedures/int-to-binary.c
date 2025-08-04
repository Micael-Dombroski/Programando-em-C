#include <stdio.h>
#include <stdlib.h>
//recursion procedure that show the binary value of an integer number
void showBynaryValueOf(int num) {
    if(num == 0)
        printf("%d", num);
    else {
        showBynaryValueOf(num / 2);
        printf("%d", num % 2);
    }

}
int main(void) {
    int num, ret;
    char c;
    do {
        printf("Write an integer number: \n");
        ret = scanf("%d", &num);
        while((c = getchar()) != '\n');
    } while(ret != 1);
    printf("Binary value of %d is: ", num);
    showBynaryValueOf(num);
    printf("\n");
    
    return 0;
}