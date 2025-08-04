#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int findNthElemInFiboSeqRecursive(long long int num) {
    if(num == 1)
        return 0;
    else {
        if(num == 2)
            return 1;
        else {
            return findNthElemInFiboSeqRecursive(num - 1) + 
                findNthElemInFiboSeqRecursive(num - 2);
        }
    }
}
long long int findNthElemInFiboSeq(long long int num) {
    long long int first = 0, second = 1, next;
    if(num == 1)
        return first;
    else {
        if(num == 2)
            return second;
        for (long long int i = 2; i < num; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        return next;
    }
}
int main(void) {
    long long int num;
    time_t start, end;
    printf("Write the number position that you want to see from fibonacci sequence: \n");
    scanf("%lld", &num);
    start = time(NULL);
    printf("The value in the position %lld is %lld\n", num, findNthElemInFiboSeqRecursive(num));
    end = time(NULL);
    printf("\t Execution time: %f (with recursion)\n", difftime(end, start));
    start = time(NULL);
    printf("The value in the position %lld is %lld\n", num, findNthElemInFiboSeq(num));
    end = time(NULL);
    printf("\t Execution time: %f\n", difftime(end, start));

    getchar();
    printf("Press any key to continue.\n");
    getchar();
    return 0;
}