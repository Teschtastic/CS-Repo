/*
 Sean Tesch   CSCI 201    Assignment #4
 Due: Friday, October 9th, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o dictionary dictionary.cpp binsearch.cpp ItemType.cpp
 
 To run, write in the command line:
 ./dictionary
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "ItemType.h"
#include "binsearch.h"

const int MaxWords = 50;

using namespace std;

int main()
{
    FILE *inFile;
    char inWord[WordSize];
    char inDef[DefinitionSize];
    ItemType dictionary[MaxWords];
    ItemType key;
    int numEntries = 0, i;
    BinarySearch search;

    /* Try to open the input file c-style... */
    inFile = fopen("dictionary.txt","r");

    /* Check if the file opened successfully */
    if (inFile == NULL)
    {
	/* Output the error message */
	cout << "ERROR: Unable to open the input file dictionary.txt\n";
	cout << "Check your current working directory and PATH\n";

	/* Bail out with a generic error return value */
	return -1;
    }

    /* As long as we're able to read a word from the input file */
    while (fscanf(inFile, "%s\n", inWord) > 0)
    {
        /* Try to read the definition...
	 * if we fail, print the error and bailout */
	if (fgets(inDef, DefinitionSize, inFile) == NULL)
	{
	    cout << "INPUT ERROR: Word " << inWord;
	    cout << " does not have a definition\n";
	    return -1;
	}
	/*****************************************************
	 * Since fgets also reads the newline character '\n' *
	 * from the infile's line, we need to replace this   *
	 * '\n' with the end-of-string character '\0'.	     *
	 *****************************************************/
	inDef[strlen(inDef) - 1] = '\0';

	// If we get to here, we have the word and definition
	// Throw it into the ItemType
	dictionary[numEntries].setWord(inWord);
	dictionary[numEntries].setDefinition(inDef);

	// Increment the index for the next word
	numEntries++;
    }

    /*********************************
     * Test the relational operators *
     *********************************/
    
   /* if (dictionary[0] < dictionary[1] && !(dictionary[1] < dictionary[0]))
	cout << "Successful < operator\n";
    else
	cout << "Failure of <\n";
    if (dictionary[1] > dictionary[0] && !(dictionary[0] > dictionary[1]))
	cout << "Successful > operator\n";
    else
	cout << "Failure of >\n";
    if (dictionary[0] <= dictionary[1] && !(dictionary[1] <= dictionary[0]))
	cout << "Successful <= operator\n";
    else
	cout << "Failure of <=\n";
    if (dictionary[1] >= dictionary[0] && !(dictionary[0] >= dictionary[1]))
	cout << "Successful >= operator\n";
    else
	cout << "Failure of >=\n";
    if (dictionary[0] == dictionary[0] && !(dictionary[1] == dictionary[0]))
	cout << "Successful == operator\n";
    else
	cout << "Failure of ==\n";
    if (dictionary[0] != dictionary[1] && !(dictionary[0] != dictionary[0]))
	cout << "Successful != operator\n";
    else
	cout << "Failure of !=\n"; */

    /*****************************
     * Dump the items that were  *
     * read from the file        *
     *****************************/
    // Output 'em
    
    /*for (i = 0; i < numEntries; i++)
	cout << dictionary[i] << endl;*/

    /*****************************
     * Test the BinarySearch     *
     * interface...we should     *
     * see the same data we just *
     * printed out               *
     *****************************/
    
    /*key.setWord("raccoon");
    key.setDefinition("");
    key = barney.binSearch(dictionary,  key, numEntries);
    cout << key << endl;*/
    
    printf("Enter a word you'd like to find: ");
    scanf("%s", inWord);
    while (strncmp(inWord, "quit", WordSize) != 0)
    {
        key.setDefinition("");
        key.setWord(inWord);
        key = search.binSearch(dictionary, key, numEntries);
        cout << key << endl;
        printf("Enter a word you'd like to find: ");
        scanf("%s", inWord);
    }
    return 0;
}
