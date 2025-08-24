#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int a, *b, **c, ***d, ret = 0;
    b = &a;//b points to a
    c = &b;//c points to b that points to a
    d = &c;//d points to c that poins to b that points to a
    char ch;
    do {
        printf("Enter an integer: ");
        ret = scanf("%d", &a);
        while((ch = getchar()) != '\n');
    } while (ret != 1);
    printf("Value:     %d\nDouble:    %d\nTriple:    %d\nQuadruple: %d\n", a, *b * 2, **c * 3, ***d * 4);
    return 0;
}