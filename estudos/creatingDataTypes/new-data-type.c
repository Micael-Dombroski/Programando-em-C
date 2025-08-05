#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int age;
    char sex;
    char name[100];
} Person;
Person registerPerson() {
    int ret = 0, age;
    char c, sex, name[100];
    do {
        printf("How old is the person? (Write the age)\n");
        ret = scanf("%d", &age);
        while((c = getchar()) != '\n');
    } while(ret != 1 && age < 1);
    do {
        printf("What is the person's gender? (M/F)\n");
        ret = scanf("%c", &sex);
        while((c = getchar()) != '\n');
        sex = toupper(sex);
    } while(ret != 1 && (sex != 'F' || sex != 'M'));
    do {
        printf("What is the person's name? \n");
        ret = scanf("%100[^\n]", name);
        while((c = getchar()) != '\n');
    } while(ret != 1);
    Person p;
    p.age = age;
    strcpy(p.name, name);
    p.sex = sex; 
    return p;
}
void printPerson(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age %d\n", p.age);
    printf("Sex: %c\n", p.sex);
}
int main(void) {
    int size, ret = 0;
    char c;
    do {
        printf("How many people do you want to register? \n");
        ret = scanf("%d", &size);
        while((c = getchar()) != '\n');
    } while(ret != 1 && size < 1);
    Person people[size];
    for (int i = 0; i < size; i++)
    {
        people[i] = registerPerson();
    }
    for (int i = 0; i < size; i++)
    {
        printPerson(people[i]);
        printf("-----------------------\n");
    }
    
    return 0;
}