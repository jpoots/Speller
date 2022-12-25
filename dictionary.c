// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char *wordSearch; //initialises variables
    int hashValue = hash(word);
    node *nodePtr = table[hashValue];
    char wordCopy[LENGTH + 1];
    int wordLength = strlen(word);

    strcpy(wordCopy, word); //makes a non constant copy of the word

    for (int i = 0; i < wordLength; i++)
    {
        if (isupper(wordCopy[i]))
        {
            wordCopy[i] = tolower(wordCopy[i]); //makes the word all lowercase (because dictionary is)
        }
    }


    while (nodePtr != NULL)
    {
        if (strcmp(nodePtr->word, wordCopy) == 0) //compares strings, returns true if found
        {
            return true;
        }

        nodePtr = nodePtr->next; //moves pointer to next node
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char first = word[0]; //intialises variables
    char second = word[1];
    int firstValue;
    int secondValue;
    int hashValue;

    if (second == 39)
    {
        second = word[2];
    }

    if (isupper(first))
    {
        first = tolower(first); //makes the first and second letters lowercase if upper
    }

    if (isupper(second))
    {
        second = tolower(second);
    }

    if (second == 0)
    {
        second = 97;
    }

    firstValue = first - 97; //gets a value of the first and second characters in lowercase, with 0 being a
    secondValue = second - 97;

    hashValue = firstValue * 26 + secondValue; //calculates hash value

    return hashValue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char *buffer;
    char wordBuffer[LENGTH + 1];
    int hashValue;
    FILE *file = fopen(dictionary, "r"); //defines variables

    if (file == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", wordBuffer) != EOF) //takes words into "wordBuffer" until end of file
    {
        node *n = malloc(sizeof(node)); //assigns a new node

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, wordBuffer); //copys the word to the buffer

        hashValue = hash(wordBuffer); //hashes the word

        if (table[hashValue] != NULL)
        {
            n->next = table[hashValue]; //assigns the word to the linked list in the right "bucket"
        }

        else
        {
            n->next = NULL;
        }

        table[hashValue] = n;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int wordCount = 0; // initialising variables
    node *nodePtr;

    for (int i = 0; i < N; i++) //cycles through each bucket
    {
        nodePtr = table[i];

        while (nodePtr != NULL) //cycles through each word
        {
            wordCount++;
            nodePtr = nodePtr->next;
        }
    }

    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *nodePtr;
    node *tmp;

    for (int i = 0; i < N; i++)
    {
        nodePtr = table[i];

        while (nodePtr != NULL)
        {
            tmp = nodePtr;
            nodePtr = nodePtr->next;
            free(tmp);
        }
    }

    return true;
}
