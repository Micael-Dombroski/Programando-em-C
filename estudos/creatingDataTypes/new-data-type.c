#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

typedef struct{
    int month, day, year;
} Date;
typedef struct{
    Date birthdate;
    int age;
    char sex;
    char name[100];
} Person;
Date registerBirthdate() {
    Date bdate;
    int ret;
    char c;
    do {
        printf("Enter the birthdate: (format: mm/dd/yyyy)\n");
        ret = scanf("%2d/%2d/%4d", &bdate.month, &bdate.day, &bdate.year);
        while((c = getchar()) != '\n');
    } while(ret != 3 || (bdate.year < 0 || 
        bdate.month < 1 || bdate.month > 12 || 
        bdate.day < 1 || bdate.day > 31));
    return bdate;
}
int calAge(Date bdate) {
    time_t curTime;
    curTime = time(NULL);
    struct tm tm = *localtime(&curTime);
    Date curDate;
    curDate.year = tm.tm_year + 1900;
    curDate.month = tm.tm_mon + 1;
    curDate.day = tm.tm_mday;
    if(bdate.year >= curDate.year)
        return 0;
    else {
        if(bdate.month < curDate.month)
            return curDate.year - bdate.year;
        else if(bdate.month == curDate.month && bdate.day <= curDate.day)
            return curDate.year - bdate.year;
        else
            return curDate.year - bdate.year - 1;
    }
}
Person registerPerson() {
    int ret = 0;
    char c, sex, name[100];
    do {
        printf("What is the person's gender? (M/F)\n");
        ret = scanf("%c", &sex);
        while((c = getchar()) != '\n');
        sex = toupper(sex);
    } while(ret != 1 && (sex != 'F' || sex != 'M'));
    /*do {
        printf("What is the person's name? \n");
        ret = scanf("%100[^\n]", name);
        while((c = getchar()) != '\n');
    } while(ret != 1);*/
    printf("What is the person's name? \n");
    fgets(name, 100, stdin);
    int i = 0;
    while(name[i] != '\n')
        i++;
    name[i] = '\0';
    Person p;
    p.birthdate = registerBirthdate();
    p.age = calAge(p.birthdate);
    strcpy(p.name, name);
    // you can't assign one string to another directly in C.
    // instead, use the strcpy() function from <string.h> to copy the contents.
    p.sex = sex;
    return p;
}
//procedure to print the contents of a Date struct.
void printBirthdate(Date bdate) {
    if(bdate.month < 10)
        printf("Birthdate: 0%d", bdate.month);
    else 
        printf("Birthdate: %2d", bdate.month);
    if(bdate.day < 10)
        printf("/0%d", bdate.day);
    else
        printf("/%2d", bdate.day);
    printf("/%4d\n", bdate.year);
}
//procedure to print the contents of a Person struct.
void printPerson(Person p) {
    printf("Name: %s\n", p.name);
    printf("Age %d\n", p.age);
    printBirthdate(p.birthdate);
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
    //Variables byte size:
    printf("\nLong long int: %d\nDouble: %d\nInt: %d\nShort: %d\nChar: %d\n", 
        sizeof(long long int), sizeof(double), sizeof(int), sizeof(short), sizeof(char));
    Date date;
    Person p;
    printf("Date size: %d\nPerson size: %d\n", sizeof(date), sizeof(p));
    //the size of the Date struct is 12 bytes because it contains three int variables (3 x 4 bytes)
    //the size of the Person struct is 120 bytes because it includes different data types,
    //and the compiler may add padding for alignment purposes.
    return 0;
}