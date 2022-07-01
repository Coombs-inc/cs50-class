// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
int Letters = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashVal = hash(word);

    node *point = table[hashVal];

    while (point != NULL)
    {
        if (strcasecmp(point->word, word) == 0)
        {
            return true;
        }

        point = point->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *Dctfile = fopen(dictionary, "r");

    if (Dctfile == NULL)
    {
        return false;
    }
    // read string
    char str[LENGTH + 1];

    while (fscanf(Dctfile, "%s", str) != EOF)
    {
        node *fold = malloc(sizeof(node));
        if (fold == NULL)
        {
            return false;
        }

        //copy string
        strcpy(fold->word, str);

        //hash
        int hashVal = hash(str);

        // is header pointing to NULL?
        if(table[hashVal] == NULL)
        {
            fold->next = NULL;
        }
        else
        {
            fold->next = table[hashVal];
        }

        table[hashVal] = fold;

        Letters += 1;
    }

    fclose(Dctfile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return Letters;
}

void freenode(node *n)
{
    if (n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
