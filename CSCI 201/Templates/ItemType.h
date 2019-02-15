#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

#ifndef ITEMTYPE
#define ITEMTYPE

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
        void setWord(string data);         // Mutator
        string getWord();              // Accessor
        void setDefinition(string data);      // Mutator
        string getDefinition();                // Accessor

        // Stream operator overloads...
        friend ostream& operator<< (ostream& out, const ItemType &it);

    private:
        // Our data
        string word;
        string definition;
};

#endif
