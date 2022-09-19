// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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

// Hash table
node *table[N];

unsigned int x;
unsigned int wordCount;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    x = hash(word);

    node *cursor = table[x];
    while(cursor != NULL)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    //declare a variable to have the return value
    unsigned long total = 0;
    //iterate for each letter in the word
    for(int i = 0; i < strlen(word); i++)
    {
        //adds the value of each letter in the ascii table to the total variable
        //all in lowercase to make the function case sensitive
        total += tolower(word[i]);
    }
    //returns the reminder of the total and N (total of buckets in the hash table)
     return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //opens dictionary to read, hence "r"
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        return 1;
    }

    //Loops in each word of the dictionary until it gets to the End Of File
    char word[LENGTH +1];
    while(fscanf(file, "%s", word) != EOF)
    {
        //Allocates memory for each string(word) that it finds using
        //the node struct for the words on the table
        node *n = malloc(sizeof(node));

        if(n == NULL)
        {
            return 1;
        }
        //copies the word of the dictionary into the word of the node n
        strcpy(n->word, word);

        //x gets the index of the word hashed
        x = hash(word);

        //the next node gets assigned to the next index on the tablle
        n->next = table[x];
        table[x] = n;

        //increases the count for the words better the eficiency of the program and help the size(void) function
        wordCount++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    while(wordCount > 0)
    {
        return wordCount;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0; i < N; i ++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;

            cursor = cursor->next;

            free(tmp);
        }

        if(cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
