#include <stdio.h>
#include <stdlib.h>
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
    Date birthdate;
    Address address;
    Contract employContract;
} Person;
typedef struct node {
    Person p;
    struct node *next;
} Node;
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
    printf("\tBirthdate: ");
    print_date(person.birthdate);
    print_address(person.address);
    print_contract(person.employContract);
    printf("\t======================================\n");
}
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
    printf("\nBirthdate: ");
    person.birthdate = read_date();
    person.employContract = read_contract();
    person.address = read_address();
    return person;
}
void push(Node **queue, Person person) {
    Node *sup, *new = malloc(sizeof(Node));
    if (new)
    {
        new -> p = person;
        new -> next = NULL;
        if(*queue) {
            sup = *queue;
            while(sup -> next) {
                sup = sup -> next;
            }
            sup -> next = new;
        } else {
            *queue = new;
        }
    } else {
        printf("\n\tFailed to allocate memory\n");
    }
}
Node* pop(Node **queue) {
    Node *remove = NULL;
    if(*queue) {
        remove = *queue;
        *queue = remove -> next;
    } else {
        printf("\n\tQueue is empty\n\n");
    }
    return remove;
}
void print_queue(Node **queue) {
    printf("\n\tQueue elements:\n");
    Node *sup = *queue;
    while(sup) {
        print_person(sup -> p);
        sup = sup -> next;
    }
    printf("\n\n");
}
int main (void) {
    Node *remove, *queue = NULL;
    int opt;
    Person person;
    do {
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Remove\n\t3 - Print\n");
        scanf("%d", &opt);
        while((getchar()) != '\n');
        switch (opt) {
        case 0:
            printf("\n\tExiting...\n");
            break;
        case 1:
            person = read_person();
            push(&queue, person);
            break;
        case 2:
            remove = pop(&queue);
            if(remove) {
                printf("Information from the removed person: \n");
                print_person(remove -> p);
                free(remove);
            }
            break;
        case 3:
            print_queue(&queue);
            break;
        default:
        printf("\n\tInvalid option\n\n");
            break;
        }
    } while(opt != 0);

    return EXIT_SUCCESS;
}