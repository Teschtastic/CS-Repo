#include <iostream>
#include <ostream>
#include <fstream>

using namespace std;

#include "ItemType.h"

ItemType::ItemType()                                        // Constructor
{
    token = OTHER;                                          // Default for token
    blank = true;                                           // Default for blank
}

ItemType::~ItemType()                                       // Destructor
{
}

ItemType::ItemType(const ItemType &origElement)             // Copy Constructor
{
    token = origElement.token;
    blank = origElement.blank;
}

const ItemType &ItemType::operator=(const ItemType &rhs)    // Assignment OP Overload
{
    if (this != &rhs)
    {
        token = rhs.token;
        blank = rhs.blank;
    }
    return *this;
}

symbol ItemType::getToken()                                 // Accessor
{
    return token;
}

void ItemType::setBlank(bool value)                         // Mutator
{
    blank = value;
}

bool ItemType::getBlank()                                   // Accessor
{
    return blank;
}

void ItemType::decode(char data)                            // Mutator
{
    switch (data)
    {
        case '(':                                           // Set the enum type for each of the characters
            token = LPAREN;
            break;
        case ')':
            token = RPAREN;
            break;
        case '[':
            token = LSQUARE;
            break;
        case ']':
            token = RSQUARE;
            break;
        case '{':
            token = LCURLY;
            break;
        case '}':
            token = RCURLY;
            break;
        default:
            token = OTHER;
            break;
    }
}

ostream& operator<<(ostream &out, const ItemType &it)       // Output for the enum types
{
    symbol token;
    bool blank;
    
    out << "Token: ";
    switch (token)
    {
        case LPAREN:
            out << "Left Parenthesis";
            break;
        case RPAREN:
            out << "Right Parenthesis";
            break;
        case LSQUARE:
            out << "Left Square Bracket";
            break;
        case RSQUARE:
            out << "Right Square Bracket";
            break;
        case LCURLY:
            out << "Left Curly Brace";
            break;
        case RCURLY:
            out << "Right Curly Brace";
            break;
        case OTHER:
            out << "Other";
            break;
        default:
            out << "Unrecognized value for date of enum: Symbol";
            break;
    }
    out << "Blank: ";
    if (blank)
        out << "True";
    else
        out << "False";
    return out;
}

friend ItemType::ifstream& operator>>(ifstream &in, const ItemType &it)
{
    symbol temp;
    
    in >> temp;
    in.token = temp;
    
    return in;
}

