// Implements a dictionary's functionality
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// word counter
unsigned long int count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 131072;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // convert word characters to lowercase
    char lowercased_copy[strlen(word) + 1];
    strcpy(lowercased_copy, word);
    for (int i = 0; i < strlen(lowercased_copy); i++)
    {
        lowercased_copy[i] = tolower(lowercased_copy[i]);
    }

    // set cursor to start on proper key in the hashtable (at the head of linked list)
    node *cursor = table[hash(lowercased_copy)];

    // traverse linked list
    while (cursor != NULL)
    {
        // check if the word is in the node (case insensitive)
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // go to next node
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
// I've used SDBM hash from http://www.cse.yorku.ca/~oz/hash.html
unsigned int hash(const char *word)
{
    unsigned long hash = 0;
    int c = *word;
    while (c != '\0')
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
        c = *word++;
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char word_in_dict[LENGTH + 1];

    while (fscanf(file, "%s", word_in_dict) != EOF)
    {

        // make a new word.
        node *n = malloc(sizeof(node));

        // check for error assigning memory
        if (n == NULL)
        {
            return false;
        }
        else
        {
            // copy word into node
            strcpy(n->word, word_in_dict);

            // use the hash function to find the key of the linked list
            int key = hash(n->word);

            // update pointer of the node to point at the start of the linked list (at particular key)
            n->next = table[key];

            // insert the node into linked list (at the beginning of the particular key)
            table[key] = n;

            // Update counter
            count++;
        }
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        // set pointer to the head of the linked list
        node *cursor = table[i];

        // traverse linked list
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);
    }
    return true;
}
