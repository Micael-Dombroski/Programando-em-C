#include <stdio.h>
#include <stdlib.h>
#define SIZE 29

typedef struct {
    int day ,month, year;
} Date;
typedef struct {
    char street[50];
    char neighborhood[50];
    char city[50];
    char country[50];
    int number, zipCode;
} Address;
typedef struct {
    int code;
    Date signatureDate;
    char position[50];
    float salary;
} Contract;

typedef struct {
    char name[50];
    int id;
    Date birthdate;
    Address address;
    Contract employContract;
} Person;

//Printing data from a Person
void print_date(Date date) {
    printf("%2d/%2d/%4d\n", date.month, date.day, date.year);
}
void print_address(Address address) {
    printf("\tAddress:\n");
    printf("\t\tStreet: %s", address.street);
    printf("\t\tNeighborhood: %s", address.neighborhood);
    printf("\t\tCity: %s", address.city);
    printf("\t\tNumber: %d\n", address.number);
    printf("\t\tZip Code: %d\n", address.zipCode);
}
void print_contract(Contract contract) {
    printf("\tContract %d:\n", contract.code);
    printf("\t\tPosition: %s", contract.position);
    printf("\t\tSalary: $%.2f\n", contract.salary);
    printf("\t\tAccession Date: ");
    print_date(contract.signatureDate);
}
void print_person(Person person) {
    printf("\t======================================\n");
    printf("\tName: %s", person.name);
    printf("\tCPF: %d\n", person.id);
    printf("\tBirthdate: ");
    print_date(person.birthdate);
    print_address(person.address);
    print_contract(person.employContract);
    printf("\t======================================\n");
}
//Reading data from a person
Date read_date() {
    Date date;
    int ret = 0;
    do {
        printf("\nEnter the date in the format mm dd yyyy: ");
        ret = scanf("%d%d%d", &date.month, &date.day, &date.year);
        while((getchar()) != '\n');
    } while (ret != 3);
    return date;
}
Address read_address() {
    Address address;
    printf("\nStreet: ");
    fgets(address.street, 49, stdin);
    printf("\nNeighborhood: ");
    fgets(address.neighborhood, 49, stdin);
    printf("\nCity: ");
    fgets(address.city, 49, stdin);
    printf("\nCountry: ");
    fgets(address.country, 49, stdin);
    printf("\nNumber: ");
    scanf("%d", &address.number);
    printf("\nZip Code: ");
    scanf("%d", &address.zipCode);
    while((getchar()) != '\n');
    return address;
}
Contract read_contract() {
    Contract contract;
    printf("\nContract code: ");
    scanf("%d", &contract.code);
    while((getchar()) != '\n');
    printf("Accession Date: ");
    contract.signatureDate = read_date();
    printf("\nPosition: ");
    fgets(contract.position, 49, stdin);
    printf("\nSalary: $");
    scanf("%f", &contract.salary);
    while((getchar()) != '\n');
    return contract;
}
Person read_person() {
    Person person;
    printf("\nName: ");
    fgets(person.name, 49, stdin);
    printf("\nID: ");
    scanf("%d", &person.id);
    printf("\nBirthdate: ");
    person.birthdate = read_date();
    person.employContract = read_contract();
    person.address = read_address();
    return person;
}

//Functions and procedures for the hash table
void initializeTable(Person t[]) {
    for (int i = 0; i < SIZE; i++) {
        t[i].id = 0;
    }
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(Person t[]) {
    Person p = read_person();
    int id = hashFunction(p.id);
    printf("\nGenerated key: %d\n", id);
    while(t[id].id != 0) {
        id = hashFunction(id + 1);
    }
    t[id] = p;
}
Person* search(Person t[], int key) {
    int id = hashFunction(key);
    printf("\nGenerated key: %d\n", id);
    while(t[id].id != 0) {
        if(t[id].id == key) {
            return &t[id];
        }
        id = hashFunction(id + 1);
    }
    return NULL;
}
void print(Person t[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("Hash Key: %d\n", i);
        if(t[i].id != 0) {
            print_person(t[i]);
        }
        printf("\n-------------------------\n");
    }
    printf("\n");
}
int main(void) {
    Person table[SIZE];
    initializeTable(table);
    int opt, value;
    do {
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt) {
        case 0:
            printf("\n\tExiting...\n");
            break;
        case 1:
            insert(table);
            break;
        case 2:
            printf("Which ID do you want to search for? ");
            scanf("%d", &value);
            Person *returnPerson = search(table, value);
            if(returnPerson) {
                printf("\nID was found:\n");
                print_person(*returnPerson);
            } else {
                printf("\n\tID was not found\n");
            }
            break;
        case 3:
            print(table);
            break;
        default:
            break;
        }
    } while (opt != 0);

    return EXIT_SUCCESS;
}