/*+----------------------------------------+
  | Sean Tesch                    CSCI 211 |
  | Assignment #4   Due: Oct 14 @ Midnight |
  | To compile: g++ -o Euclid Euclid.cpp   |
  |            To run: ./Euclid            |
  +----------------------------------------+*/

#include <iostream>

using namespace std;

/* - Global depth variable - */
int depth;

/* - Prototype for recursion function - */
int euclid(int, int);

int main()
{
    /* - Two input variables - */
    int in1, in2;
    
    /* - Input statement - */
    cout << "To terminate, enter a '0' for either number. \n";
    cout << "Enter the first number: ";
    cin >> in1;
    cout << "Enter the second number: ";
    cin >> in2;
    
    /* - GCD loop - */
    while (in1 != 0 || in2 != 0)
    {
        if (in1 < in2)
        {
            // Swap the two variables
            int swap;
            swap = in1;
            in1 = in2;
            in2 = swap;
        }
        
        /* - Outputs results - */
        cout << "Greatest GCD of " << in1 << " and " << in2 << " is: " << euclid(in1,in2) << endl << "The recursive calculation required a depth of: " << depth + 1 << endl;
        
        /* - Resets depth for next loop - */
        depth = 0;
        
        /* - To keep looping - */
        cout << "To terminate, enter a '0' for either number. \n";
        cout << "Enter the first number: ";
        cin >> in1;
        cout << "Enter the second number: ";
        cin >> in2;
        
        /* - To keep the 0 termination true - */
        if (in1 == 0 || in2 == 0)
            return 0;
        
    }
    return 0;
}

int euclid(int n1, int n2)
{
    
    /* - Returns the GCD - */
    if(n2 == 0)
    {
        return n1;
    }
    else
    {
        /* - Increases depth - */
        depth++;
        return euclid(n2, n1 % n2);
    }
    
}

