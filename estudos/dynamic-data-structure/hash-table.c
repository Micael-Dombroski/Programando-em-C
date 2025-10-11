#include <stdio.h>
#include <stdlib.h>
//What is a hash table?
/*
    Hash tables were created due to allow very fast search
    and retrieval operation.
    In queues, stacks, and linked lists, searches 
    are performed sequentially. If the number of elements 
    is too large, it takes a long time to find the element, 
    since each one must be checked until the target 
    is found (or not found).

    A hash table uses a hash function to map each element (key) 
    to an index in an array. The hash function converts the key 
    into a numeric value (hash key/or hash code), which determines 
    where the element will be stored in the table.
    Example:
        key % table_size = hash key

    Collisions happen when 2 different keys generate the same hash key.
    To handle collisions, techniques like chaining (using linked lists 
    at each index) or open addressing (finding available slot) are used.

    The load factor defines how full the table is allowed to get before 
    it is resized. It’s calculated as:
        loadFactor = number_of_elements / table_size

    Choosing the table size:
    ------------------------
    To reduce collisions, set the table size to roughly twice the 
    expected number of elements.

    Using a prime number as the table size helps distribute hash values
    more evenly across the table, especially when the hash function
    involves modulus operations (key % table_size).

    Example:
        If you expect around 100 elements,
        table_size ≈ 2 × 100 = 200
        Closest prime number → 199 or 211

    This helps minimize collisions and avoid repeating patterns
    that can occur with non-prime table sizes.

    A high load factor increases the number of collisions,
    and a low load factor wastes memory with too many empty spaces.
    To balance performance and space, a common load factor is around 0.75.
*/
#define SIZE 29
//we're creating a table with 15 elements, the closest
//prime number to twice the number of elements choosen was 29
void initializeTable(int t[]) {
    for(int i = 0; i < SIZE; i++)
        t[i] = 0;
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int t[], int value) {
    int id = hashFunction(value);
    while(t[id] != 0) {
        id = hashFunction(id + 1);
    }
    t[id] = value;
}
int search(int t[], int key) {
    int id = hashFunction(key);
    printf("\n\tGenerated index: %d\n", id);
    while(t[id] != 0) {
        if(t[id] == key) {
            return t[id];
        }
        id = hashFunction(id + 1);
    }
    return 0;
}
void print(int t[]) {
    printf("----Hashtable----\n");
    printf("[ID] - [KEY]\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%2d] - [%d]\n", i, t[i]);
    }
    printf("\n");
}
int main (void) {
    int table[SIZE];
    initializeTable(table);
    int opt, ret = 0, value;
    do {
        printf("HashTable Menu\n");
        printf("\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print\n");
        do {
            printf("Choose an option: ");
            ret = scanf("%d", &opt);
            while((getchar()) != '\n');
        } while (ret != 1);
        switch (opt) {
        case 0:
           printf("\n\tExiting...\n");
            break;
        case 1:
            do {
                printf("Which value you want to insert? ");
                ret = scanf("%d", &value);
                while((getchar()) != '\n');
            } while (ret != 1);
            insert(table, value);
            break;
        case 2:
            do {
                printf("Which value you want to search for? ");
                ret = scanf("%d", &value);
                while((getchar()) != '\n');
            } while (ret != 1);
            int returnValue = search(table, value);
            if(returnValue) {
                printf("\nThe value %d was found\n", returnValue);
            } else {
                printf("\n\tThe value wasn't found\n");
            }
            break;
        case 3:
            print(table);
            break;
        default:
        printf("\n\tInvalid option!\n");
            break;
        }
    } while (opt != 0);
    return EXIT_SUCCESS;
}