#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("Memory6.dat");

    if(!in)
    {
        cout << "Cannot open input file.\n";
        return 1;
    }

    char str[255];
    while(in.getline(str,255))
    {
        cout << str <<endl;
    }

    in.close();
    

  return 0;
}

