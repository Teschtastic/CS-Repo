#include <iostream>
#include <fstream>
#include <string.h>
#include "ItemType.h"

ItemType::ItemType()		// Constructor
{
    word[0] = '\0';
    definition[0] = '\0';
}

ItemType::~ItemType()		// Destructor
{
}

ItemType::ItemType(const ItemType & origElement) // Copy constructor
{
    strncpy(word, origElement.word, WordSize);
    strncpy(definition, origElement.definition, DefinitionSize);
}

const ItemType & ItemType::operator=(const ItemType &rhs)
{
    if (this != &rhs)
    {
        strncpy(word, rhs.word, WordSize);
        strncpy(definition, rhs.definition, DefinitionSize);
    }

    return rhs;
}

bool operator<(const ItemType &lhs, const ItemType &rhs)
{
    return(strcmp(lhs.word, rhs.word) < 0);
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

void ItemType::setWord(char data[])         // Mutator
{
    strncpy(word, data, WordSize);
}

char* ItemType::getWord()              // Accessor
{
    return word;
}

void ItemType::setDefinition(char data[])      // Mutator
{
    strncpy(definition, data, DefinitionSize);
}

char* ItemType::getDefinition()                // Accessor
{
    return definition;
}

ostream& operator<< (ostream& out, const ItemType &it)
{
    out << it.word << ": " << it.definition;

    return out;
}
