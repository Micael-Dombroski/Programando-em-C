//bhaskara
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void clear_buffer() {
    while((getchar()) != '\n');
}

int main(void) {
    float a,b,c;
    int ret = 0;
    do {
        printf("\n\tQuadratic Formula\n");
        printf("\tEnter the element A: \n");
        ret += scanf("%f", &a);
        clear_buffer();
        printf("\tEnter the element B: \n");
        ret += scanf("%f", &b);
        clear_buffer();
        printf("\tEnter the element C: \n");
        ret += scanf("%f", &c);
        clear_buffer();
        if(ret != 3) {
            printf("\n\tThe formula was incomplete. Enter all of the three elements\n");
            ret = 0;
        }
    } while(ret != 3);
    double delta = b * b - (4 * a * c);
    printf("\n\tThe delta from the quadratic formula is: %.2f\n", delta);
    if(delta < 0 || a == 0) {
        printf("\n\tThe root from the parabola isn't a real number\n");
    } else {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("\n\tThe roots of this equation are:\n\tX1: %.2f\n\tX2: %.2f\n", x1, x2);
    }
    return EXIT_SUCCESS;
}