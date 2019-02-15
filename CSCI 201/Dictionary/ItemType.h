#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#ifndef ITEMTYPE
#define ITEMTYPE

const int WordSize = 21;
const int DefinitionSize = 81;

class ItemType
{
    public:
        ItemType();             // Constructor
        ~ItemType();            // Destructor
        ItemType(const ItemType & origElement);         // Copy constructor
        const ItemType & operator=(const ItemType &rhs); // Assignment op overload
        friend bool operator<(const ItemType &lhs, const ItemType &rhs);	// < op overload
        friend bool operator>(const ItemType &lhs, const ItemType &rhs);	// > op overload
        friend bool operator<=(const ItemType &lhs, const ItemType &rhs);	// <= op overload
        friend bool operator>=(const ItemType &lhs, const ItemType &rhs);	// >= op overload
        friend bool operator==(const ItemType &lhs, const ItemType &rhs);	// == op overload
        friend bool operator!=(const ItemType &lhs, const ItemType &rhs);	// != op overload
        void setWord(char data[]);         // Mutator
        char *getWord();              // Accessor
        void setDefinition(char data[]);      // Mutator
        char *getDefinition();                // Accessor

        // Stream operator overloads...
        friend ostream& operator<< (ostream& out, const ItemType &it);

    private:
        // Our data
        char word[WordSize];
        char definition[DefinitionSize];
};

#endif
