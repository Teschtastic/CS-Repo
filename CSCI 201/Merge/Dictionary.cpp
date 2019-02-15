/*
 Sean Tesch   CSCI 201    Assignment #5
 Due: Wednesday, October 21st, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o dictionary Dictionary.cpp Mergesort.cpp ItemType.cpp
 
 To run, write in the command line:
 ./dictionary
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "ItemType.h"
#include "Mergesort.h"

const int MaxWords = 50;

using namespace std;

int main()
{
    FILE *inFile;
    char inWord[WordSize];
    char inDef[DefinitionSize];
    ItemType dictionary[MaxWords];
    ItemType key;
    int numEntries = 0, i, j;
    MergeSort Merge;
    
    /* - Try to open the input file - */
    inFile = fopen("dictionary.txt","r");
    
    /* - Check if the file opened successfully - */
    if (inFile == NULL)
    {
        /* - Output the error message - */
        cout << "ERROR: Unable to open the input file dictionary.txt\n";
        cout << "Check your current working directory and PATH\n";
        
        /* - Generic error return value - */
        return -1;
    }
    
    /* - As long as we're able to read a word from the input file - */
    while (fscanf(inFile, "%s\n", inWord) > 0)
    {
        /* - Try to read the definition...
        if we fail, print the error and bailout - */
        if (fgets(inDef, DefinitionSize, inFile) == NULL)
        {
            cout << "INPUT ERROR: Word " << inWord;
            cout << " does not have a definition\n";
            return -1;
        }
        //Replace '\n' with '\0'
        inDef[strlen(inDef) - 1] = '\0';
        
        // If we get to here, we have the word and definition
        // Throw it into the ItemType
        dictionary[numEntries].setWord(inWord);
        dictionary[numEntries].setDefinition(inDef);
        
        // Increment the index for the next word
        numEntries++;
    }
    
    /* - Outputs original dictionary - */
    cout << endl << "UNSORTED LIST: " << endl;
    
    for (i = 0; i < numEntries; i++)
    {
        cout << "\t" << dictionary[i] << endl;
    }

    /* - Calls the sorting function - */
    Merge.mergeSort(dictionary, 0, numEntries);
    
    /* - Outputs sorted dictionary - */
    cout << endl << "SORTED LIST: " << endl;
    
    for (j = 1; j < numEntries + 1; j++)
    {
        cout << "\t" << dictionary[j] << endl;
    }
    
    return 0;
}

