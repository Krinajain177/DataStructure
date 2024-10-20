#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10
typedef struct
{
    char *key;
    int value;
} HashItem;
typedef struct
{
    HashItem *items[TABLE_SIZE];
} HashTable;
// Hash function to calculate index
int hash(const char *key)
{
    int hashValue = 0;
    while (*key)
    {
        hashValue += *key++;
    }
    return hashValue % TABLE_SIZE;
}
// Create a new hash table
HashTable *createHashTable()
{
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->items[i] = NULL;
    }
    return table;
}
// Insert a key-value pair into the hash table
void insert(HashTable *table, const char *key, int value)
{
    int index = hash(key);
    int originalIndex = index;
    while (table->items[index] != NULL)
    {
        if (strcmp(table->items[index]->key, key) == 0)
        {
            // Key already exists, update value
            table->items[index]->value = value;
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex)
        {
            printf("Hash table is full!\n");
            return; // Table is full
        }
    }
    // Create a new item and insert it
    HashItem *newItem = (HashItem *)malloc(sizeof(HashItem));
    newItem->key = strdup(key);
    newItem->value = value;
    table->items[index] = newItem;
}
// Search for a key in the hash table
int search(HashTable *table, const char *key)
{
    int index = hash(key);
    int originalIndex = index;
    while (table->items[index] != NULL)
    {
        if (strcmp(table->items[index]->key, key) == 0)
        {
            return table->items[index]->value; // Found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex)
        {
            break; // Back to the original index
        }
    }
    return -1; // Not found
}
// Delete a key from the hash table
void delete(HashTable *table, const char *key)
{
    int index = hash(key);
    int originalIndex = index;
    while (table->items[index] != NULL)
    {
        if (strcmp(table->items[index]->key, key) == 0)
        {
            free(table->items[index]->key);
            free(table->items[index]);
            table->items[index] = NULL; // Delete the item
            // Rehash items in the same cluster
            index = (index + 1) % TABLE_SIZE;
            while (table->items[index] != NULL)
            {
                HashItem *temp = table->items[index];
                table->items[index] = NULL;            // Temporarily remove the item
                insert(table, temp->key, temp->value); // Re-insert
                free(temp->key);
                free(temp);
                index = (index + 1) % TABLE_SIZE;
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
        {
            break; // Back to the original index
        }
    }
}
// Free the hash table
void freeHashTable(HashTable *table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table->items[i] != NULL)
        {
            free(table->items[i]->key);
            free(table->items[i]);
        }
    }
    free(table);
}
// Main function to demonstrate the hash table
int main()
{
    // Default code
    printf("Practial-10\n");
    printf("Enrollment NO. :-230130107052 \n");
    printf("Krina Jain\n");
    printf("10.1 Write a program to create hash table and handle the collision using linear probing.\n");
    HashTable *ht = createHashTable();
    insert(ht, "key1", 1);
    insert(ht, "key2", 2);
    insert(ht, "key3", 3);
    printf("Search for key2: %d\n", search(ht, "key2"));
    delete (ht, "key2");
    printf("Search for key2 after deletion: %d\n", search(ht, "key2"));
    freeHashTable(ht);
    return 0;
}
