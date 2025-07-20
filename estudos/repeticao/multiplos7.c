#include <stdio.h>
#include <stdlib.h>
void multiplos7(int limite) {
    for (int i = 0; 7*i <= limite; i++)
    {
        printf("7 x %d = %d\n", i, 7*i);
    }
}
int main(void) {
    multiplos7(9999);
    return 0;
}