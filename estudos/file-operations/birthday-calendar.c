#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    File opening modes
    w -> write
    r -> read
    a -> append
    r+ -> read and write
    w+ -> read and write (clean the content if the file already exists)
    a+ -> read and write (writes at the end of the file)
*/
typedef struct {
    char name[50];
    int day, month, year;
} Contact;
int getCurrentYear() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year + 1900;
}
void print(Contact *c, int id) {
    if(c) {
        printf("\tId:%d\tName: %s\tBirthdate: %2d/%2d/%d\n", id, c -> name, c -> month, c -> day, c -> year);
    }
    printf("\t----------------------------------------------------------------\n");
}
void print_contact_book(Contact **c, int qtt) {
    printf("\n\tContact Book:\n");
    printf("\t----------------------------------------------------------------\n");
    for (int i = 0; i < qtt; i++) {
        print(c[i], i + 1);
    }
}
int register_contact(Contact **c, int qtt, int size) {
    if(!(size > qtt)) {
        printf("\n\tUnable to regiter a new contact. Contact Book is full\n");
        return 0;
    }
    int ret = 0;
    char ch;
    Contact *new = calloc(1, sizeof(Contact));
    do {
        printf("Enter the contact name: ");
        ret = scanf("%50[^\n]", new->name);
        while((ch = getchar()) != '\n');
    } while(ret != 1);
    do {
        printf("Enter the contact birthday (mm/dd/yyyy): ");
        ret = scanf("%d/%d/%d", &new->month, &new->day, &new->year);
        while((ch = getchar()) != '\n');
    } while (ret != 3 || 
        new->month < 0 || new->month > 12 || 
        new->day < 0 || new->day > 31 || 
        new->year < 1900 || new->year > getCurrentYear());
    c[qtt] = new;
    return 1;
}
void update_contact(Contact **c, int qtt, int size) {
    if(qtt == 0) {
        printf("\n\tThere is nothing to update\n");
        return;
    }
    print_contact_book(c, qtt);
    int ret = 0, contactID = 0;
    char ch;
    do {
        printf("\nEnter the contact ID you want to update: ");
        ret = scanf("%d", &contactID);
        if(contactID < 1 || contactID > qtt)
            printf("\n\tInvalid ID!\n");
        while((ch = getchar()) != '\n');
    } while(ret != 1 || contactID < 1 || contactID > qtt);
    register_contact(c, contactID - 1, size);
    printf("\n\n");
    print_contact_book(c, qtt);
}
Contact* remove_contact(Contact **c, int qtt) {
    if(qtt == 0) {
        printf("\n\tThere is nothing to remove\n");
        return NULL;
    }
    print_contact_book(c, qtt);
    int ret = 0, contactID = 0;
    do {
        printf("\nEnter the contact ID you want to remove: ");
        ret = scanf("%d", &contactID);
        if(contactID < 1 || contactID > qtt)
            printf("\n\tInvalid ID!\n");
        while((getchar()) != '\n');
    } while(ret != 1 || contactID < 1 || contactID > qtt);
    Contact *removed = c[contactID - 1];
    c[contactID - 1] = c[qtt - 1];
    return removed;
}
void save(Contact **c, int qtt, char f[]) {
    FILE *file = fopen(f, "w+");
    if(file) {
        fprintf(file, "%d\n", qtt);
        for (int i = 0; i < qtt; i++)
        {
            if(c[i]) {
                fputs(c[i] ->name, file);
                fputc('\n', file);
                fprintf(file, "%d/%d/%d\n", c[i]->month, c[i]->day, c[i]->year);
            }
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open file\n");
    }
}
int read_file(Contact **c, int size, char f[]) {
    FILE *file = fopen(f, "r");
    int qtt = 0, i;
    if(file) {
        if(fscanf(file, "%d\n", &qtt) != 1) {
            printf("\n\tError: could not read contact count\n");
            fclose(file);
            return 0;
        }
        if(qtt > size) {
            printf("\n\tError: contact data is invalid (too many entries). The file may have been modified manually.\n");
            return 0;
        }
        for (i = 0; i < qtt; i++)
        {
            Contact *contact = calloc(1, sizeof(Contact));
            int ret = fscanf(file, "%50[^\n]", contact->name);
            ret += fscanf(file, "%d/%d/%d\n", &contact->month, &contact->day, &contact->year);
            if(ret != 4) {
                printf("\n\tError reading contact data at line %d\n", i+1);
                free(contact);
                fclose(file);
                return i;
            }
            c[i] = contact;
        }
        fclose(file); 
    } else {
       printf("\n\tFailed to open file\n");
    }
    return qtt;
}
int main(void) {
    Contact *contactBook[50], *removed;
    char fileName[] = "contactBook.txt";
    int size = 50, qtt = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Register\n\t2 - Update\n\t3 - Print\n\t4 - Remove\n\t5 - Save\n\t6 - Read File\n");
        printf("\nChoose an option: ");
        scanf("%d", &opt);
        getchar();
        switch (opt)
        {
            case 0:
                printf("\n\tExiting...\n");
                break;
            case 1:
                qtt += register_contact(contactBook, qtt, size);
                break;
            case 2:
                update_contact(contactBook, qtt, size);
                break;
            case 3:
                print_contact_book(contactBook, qtt);
                break;
            case 4:
                removed = remove_contact(contactBook, qtt);
                if(removed) {
                    printf("\n\tContact was successfully removed!\n");
                    print(removed, 1);
                    qtt--;
                    free(removed);
                }
                break;
            case 5:
                save(contactBook, qtt, fileName);
                break;
            case 6:
                qtt = read_file(contactBook, size, fileName);
                printf("Number of contacts: %d\n", qtt);
                break;
            default:
                printf("\n\tInvalid option!\n");
                break;
        }
    } while (opt != 0);
    return 0;
}