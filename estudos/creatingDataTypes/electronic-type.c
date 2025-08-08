#include <stdio.h>
#include <string.h>
typedef struct
{
    char type[100];
    char brand[50];
    char model[25];
    char energy;
    char description[500];
    int quantity;
    int code;
} Electronic;
void printElectronic(Electronic e) {
    printf("\tType: %s", e.type);
    printf("\tBrand: %s", e.brand);
    printf("\tModel: %s", e.model);
    printf("\tEnergy: %c\tQuantity: %d\n", e.energy, e.quantity);
    printf("\tDescription: %s", e.description);
}
Electronic registerElectronic() {
    Electronic e;
    char c;
    int ret = 0;
    printf("Enter the Electronic type: ");
    fgets(e.type, 100, stdin);
    printf("Enter the brand: ");
    fgets(e.brand, 50, stdin);
    printf("Enter the model: ");
    fgets(e.model, 25, stdin);
    printf("Enter the energy efficiency: (from F to A)");
    scanf("%c", &e.energy);
    while((c = getchar()) != '\n');
    printf("Enter the description: ");
    fgets(e.description, 500, stdin);
    do {
        printf("Enter the quantity in stocky: ");
        ret = scanf("%d", &e.quantity);
    } while(ret != 1 && e.quantity < 0);
    while((c = getchar()) != '\n');
    printf("Enter the code: ");
    scanf("%d", &e.code);
    return e;
}
int main(void) {
    int ret, size;
    char c;
    do {
        printf("How many electronic you want to register? ");
        ret = scanf("%d", &size);
        while((c = getchar()) != '\n');
    } while(ret != 1 && size < 0);
    Electronic electronics[size];
    for (int i = 0; i < size; i++)
        electronics[i] = registerElectronic();
    for (int i = 0; i < size; i++) {
        printElectronic(electronics[i]);
        printf("--------------------------");
    }
    return 0;
}