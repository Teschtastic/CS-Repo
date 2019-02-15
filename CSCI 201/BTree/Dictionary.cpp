#include <iostream>
#include <string.h>
#include <stdio.h>
#include "ItemType.h"
#include "BST.h"

using namespace std;

int main()
{
    FILE *inFile;
    char inWord[WordSize], inDef[DefinitionSize], inChar;
    ItemType key;
    int numEntries = 0, i;
    BTree myTree;

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
	key.setWord(inWord);
	key.setDefinition(inDef);
	myTree.insert(key);
    }

    do
    {
	cout << "Binary Search Tree:\n";
	cout << "\tI\tInsert a new word\n";
	cout << "\tR\tRemove a word\n";
	cout << "\tF\tLookup a word's definition\n";
	cout << "\tN\tPrint an inorder traversal of the dicitonary\n";
	cout << "\tE\tPrint a preorder traversal of the dicitonary\n";
	cout << "\tO\tPrint a postorder traversal of the dicitonary\n";
	cout << "\tM\tFind the last word (alphabetically) in the tree\n";
	cout << "\tm\tFind the first word (alphabetically) in the tree\n";
	cout << "\t/\tTest if the dictionary is empty\n";
	cout << "\tK\tEmpty the dictionary\n";
	cout << "\tq\tQuit the program\n";
	cout << "Action? ";
	cin >> inChar;

        switch (inChar)
	{
	    case 'I':
		cout << "Word? ";
		cin >> inWord;
		cout << "Definition? ";
		fflush(stdin);
		fgets(inDef, DefinitionSize, stdin);
		inDef[strlen(inDef) - 1] = '\0';
		key.setWord(inWord);
		key.setDefinition(inDef);
		myTree.insert(key);
	    break;

	    case 'R':
		cout << "Word? ";
		cin >> inWord;
		key.setWord(inWord);
		inDef[0] = '\0';
		key.setDefinition(inDef);
		myTree.remove(key);
	    break;

	    case 'F':
		cout << "Word? ";
		cin >> inWord;
		key.setWord(inWord);
		inDef[0] = '\0';
		key.setDefinition(inDef);
		key = myTree.find(key);
		cout << key << endl;
	    break;

	    case 'N':
		myTree.printInOrder();
	    break;

	    case 'E':
		myTree.printPreOrder();
	    break;

	    case 'O':
		myTree.printPostOrder();
	    break;

	    case 'M':
		key = myTree.maxBTree();
		cout << key << endl;
	    break;

	    case 'm':
		key = myTree.minBTree();
		cout << key << endl;
	    break;

	    case '/':
		if (myTree.isEmpty())
		    cout << "The tree is empty\n";
		else
		    cout << "The tree is not empty\n";
	    break;

	    case 'K':
		myTree.~BTree();
	    break;

	    case 'q':
	    break;

	    default:
		cout << "ERROR: Bad menu selection - " << inChar << endl;
	    break;
	}
    } while (inChar != 'q');

    return 0;
}
