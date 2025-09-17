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
void print(Contact **c, int qtt) {
    printf("\n\tContact Book:\n");
    printf("\t----------------------------------------------------------------\n");
    for (int i = 0; i < qtt; i++) {
        printf("\tId:%d\tName: %s\tBirthdate: %2d/%2d/%d\n", i+1, c[i]->name, c[i]->month, c[i]->day, c[i]->year);
    }
    printf("\t----------------------------------------------------------------\n");
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
        printf("Enter the contact name and birthdate (mm dd yyyy): ");
        ret = scanf("%49[^\n]%d %d %d", new->name, &new->month, &new->day, &new->year);
        while((ch = getchar()) != '\n');
    } while (ret != 4 || 
        new->month < 0 || new->month > 12 || 
        new->day < 0 || new->day > 31 || 
        new->year < 1900 || new->year > getCurrentYear());
    c[qtt] = new;
    free(new);
    return 1;
}
void update_contact(Contact **c, int qtt, int size) {
    print(c, qtt);
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
    print(c, qtt);
}
void save(Contact **c, int qtt, char f[]) {
    FILE *file = fopen(f, "wb+");
    if(file) {
        for (int i = 0; i < qtt; i++) {
            fwrite(c[i], sizeof(Contact), 1, file);
        }
        fclose(file);
    } else {
        printf("\n\tFailed to open file\n");
    }
}
int read_file(Contact **c, int size, char f[]) {
    FILE *file = fopen(f, "rb");
    int qtt = 0;
    if(file) {
        Contact *contact = calloc(1, sizeof(Contact));
        while(fread(contact, sizeof(Contact), 1, file)) {
            c[qtt] = contact;
            qtt++;
            contact = calloc(1, sizeof(Contact));
        }
        free(contact);
        if(qtt > size) {
            printf("\n\tError: contact data is invalid (too many entries). The file may have been modified manually.\n");
            for(int i = 0; i < qtt; i++) {
                free(c[i]);
            }
            return 0;
        }
        fclose(file); 
    } else {
       printf("\n\tFailed to open file\n");
    }
    return qtt;
}
int main(void) {
    Contact *contactBook[50];
    char fileName[] = "contactBook.dat";
    int size = 50, qtt = 0, opt;
    do {
        printf("\n\t0 - Exit\n\t1 - Register\n\t2 - Update\n\t3 - Print\n\t4 - Save\n\t5 - Read File\n");
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
                print(contactBook, qtt);
                break;
            case 4:
                save(contactBook, qtt, fileName);
                break;
            case 5:
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