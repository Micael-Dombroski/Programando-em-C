#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num) {
    int dividedBy = 0;
    for(int i = 1; i < num; i++) {
        if(num % i == 0) {
            dividedBy++;
        }
    }
    if(dividedBy == 1) {
        return 1;
    }
    return 0;
}

int main(void) {
    int limit;
    printf("Enter the limit number: ");
    while((scanf("%d", &limit)) != 1);
    for (int i = 2; sqrt((double)i) <= sqrt(limit); i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}