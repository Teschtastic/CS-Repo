#include <iostream>
#include <ostream>
#include <fstream>
#ifndef ITEMTYPE
#define ITEMTYPE

using namespace std;

enum symbol {LPAREN, RPAREN, LCURLY, RCURLY, LSQUARE, RSQUARE, OTHER};

class ItemType
{
public:
    ItemType();                                     // Constructor
    ~ItemType();                                    // Destructor
    ItemType(const ItemType &origElement);          // Copy Constructor
    const ItemType &operator=(const ItemType &rhs); // Assignment OP Overloadf
    void decode(char);                              // Mutator
    symbol getToken();                              // Accessor
    void setBlank(bool value);                      // Mutator
    bool getBlank();                                // Accessor
    
    // Stream operator overloads...
    friend ostream& operator<< (ostream& out, const ItemType &it);
    friend ifstream& operator>> (ifstream& in, ItemType &it);
    
private:
    symbol token;
    bool blank;
};

#endif

