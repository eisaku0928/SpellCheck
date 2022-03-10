// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Count number of words loaded
unsigned int word_count = 0;

// Keep track if dictionary is loaded
bool loaded = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int index = hash(word);
    
    // Traverse linked list
    // Set a cursor and check each node until cursor == NULL
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // if found return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        // Shift cursor
        cursor = cursor->next;
    }
    // If word was not found return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Source: https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
    unsigned long hash = 5381;
    
    for (const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Read file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    // store current word into character array word with enough space
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        // If word exists, allocate enough memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        
        // Copy word into node
        strcpy(n->word, word);
        
        // Hash word to obtain hash value
        unsigned int index = hash(word);
        
        // Insert node into hash table at that location
        // Set pointer of n to first element in linked list, then reset head pointer
        n->next = table[index];
        table[index] = n;
        
        // Keep track of word count for size function
        word_count++;
    }
    // Close file and set loaded identifier to true
    fclose(dict);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Loop through the hash table
    for (int i = 0; i < N; i++)
    {
        // Loop through each linked list using a cursor
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // let tmp point to the same node
            node *tmp = cursor;
            // free tmp after moving cursor to next element
            cursor = cursor->next;
            free(tmp);
        }
    }
    
    // Return true if successfully unloaded
    return true;
}
