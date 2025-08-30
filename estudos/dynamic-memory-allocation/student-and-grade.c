#include <stdio.h>
#include <stdlib.h>
int main(void) {
    char **names = calloc(3, sizeof(char*)), c;
    for (int i = 0; i < 3; i++)
    {
        names[i] = calloc(20, sizeof(char));
    }
    float *grades = calloc(3, sizeof(float)), ret = 0;
    for (int i = 0; i < 3; i++)
    {
        do {
            
            printf("Enter the name of the student and his grade: (name-grade)");
            ret = scanf("%19[^-]-%f", names[i], &*(grades + i));
            while((c = getchar()) != '\n');
            if(*(grades + i) < 0)
                *(grades + i)*=-1.0;
        } while(ret != 2 || *(grades + i) > 10);
    }
    printf("%50s | Grade\n", "Name");
    for (int i = 0; i < 3; i++)
    {
        printf("%20s | %.2f\n", names[i], *(grades + i));
    }
    for (int i = 0; i < 3; i++) {
        free(names[i]);
    }
    free(names);
    free(grades);
    names = NULL;
    grades = NULL;
    return 0;
}