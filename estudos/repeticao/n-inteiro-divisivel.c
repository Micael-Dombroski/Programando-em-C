#include <stdio.h>
#include <stdlib.h>
int divisivelPor(int num, int divisor) {
    if(num%divisor == 0)
        return 1;
    return 0;
}
int main(void) {
    int num = 8;
    printf("Encontrando o menor numero inteiro divisivel por todos os numeros inteiros entre 1 e 10\n");
    printf("...\n");
    do {
        num+= 2;
    } while(!(divisivelPor(num,1)&&divisivelPor(num,2)&&divisivelPor(num,3)&&divisivelPor(num,4)&&divisivelPor(num,5)&&divisivelPor(num,6)&&divisivelPor(num,7)&&divisivelPor(num,8)&&divisivelPor(num,9)&&divisivelPor(num,10)));
    printf("O menor numero inteiro divisivel pelos valores informados e: %d\n", num);
    return 0;
}