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
int main (void) {

    
    return EXIT_SUCCESS;
}