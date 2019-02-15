#include <iostream>
#include <fstream>
#include <string.h>
#include "ItemType.h"

ItemType::ItemType()		// Constructor
{
    word = "";
    definition = "";
}

ItemType::~ItemType()		// Destructor
{
}

ItemType::ItemType(const ItemType & origElement) // Copy constructor
{
    word =  origElement.word;
    definition = origElement.definition;
}

const ItemType & ItemType::operator=(const ItemType &rhs)
{
    if (this != &rhs)
    {
	word =  rhs.word;
	definition = rhs.definition;
    }

    return rhs;
}

bool operator<(const ItemType &lhs, const ItemType &rhs)
{
    return(lhs.word < rhs.word);
}

bool operator>(const ItemType &lhs, const ItemType &rhs)
{
    return(rhs < lhs);
}

bool operator<=(const ItemType &lhs, const ItemType &rhs)
{
    return(!(rhs < lhs));
}

bool operator>=(const ItemType &lhs, const ItemType &rhs)
{
    return(!(lhs < rhs));
}

bool operator==(const ItemType &lhs, const ItemType &rhs)
{
    return(!(lhs < rhs) && !(rhs < lhs));
}

bool operator!=(const ItemType &lhs, const ItemType &rhs)
{
    return((lhs < rhs) || (rhs < lhs));
}

void ItemType::setWord(string data)         // Mutator
{
    word = data;
}

string ItemType::getWord()              // Accessor
{
    return word;
}

void ItemType::setDefinition(string data)      // Mutator
{
    definition = data;
}

string ItemType::getDefinition()                // Accessor
{
    return definition;
}

ostream& operator<< (ostream& out, const ItemType &it)
{
    out << it.word << ": " << it.definition;

    return out;
}
