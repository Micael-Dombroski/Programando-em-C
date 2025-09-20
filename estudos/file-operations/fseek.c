#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Open file modes
    wb -> write
    rb -> read
    ab -> attach
    rb+ -> read and write
    wb+ -> read and write (delete the content from the file if the file already exist)
    ab+ -> read and write (insert in the end of the file)
*/
/*
    using fseek to update data from file throw update_contact function
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
        printf("\tID:%d\tBirthdate: %2d/%2d/%4d\tName: %s\n", i+1, c[i]->month, c[i]->day, c[i]->year, c[i]->name);
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
    return 1;
}
void update_contact(char f[]) {
    FILE *file = fopen(f, "rb+");
    if(file) {
        Contact c;
        int id, i = 1;
        printf("\tContact List: \n");
        printf("\t--------------------------------");
        while(fread(&c, sizeof(Contact), 1, file)) {
            printf("ID: %d\tBirthdate: %2d/%2d/%4d\tName: %s\n", i, c.month, c.day, c.year, c.name);
            i++;
        }
        printf("\t--------------------------------");
        printf("\n\tEnter the contact ID to update: ");
        scanf("%d", &id);
        while((getchar()) != '\n');
        if(id < 1 || id >= i) {
            printf("\n\tInvalid ID\n");
            return;
        }
        id--;
        int ret = 0;
        do {
            printf("\tEnter the contact name and birthdate (mm dd yyyy): ");
            ret = scanf("%49[^\n]%d %d %d", c.name, &c.month, &c.day, &c.year);  
        } while (ret != 4);
        fseek(file, id * sizeof(Contact), SEEK_SET);
        //SEEK_SET reuturn the file pointer to the start of file
        fwrite(&c, sizeof(Contact), 1, file);
        fclose(file);
    } else {
        printf("\n\tFailed to open file!\n");
    }
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
    char fileName[] = "contactBook2.dat";
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
                update_contact(fileName);
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
    for(int i = 0; i < qtt; i++) {
        free(contactBook[i]);
    }
    return 0;
}