//
//  main.cpp
//  Floating Point Example
//
//  Created by Sean Tesch on 9/21/17.
//  Copyright © 2017 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int main()
{
    double ecks = 0.3; double why = 0.3;
    for (int i = 0; i < 999999999; i++)
        ecks += why;
    cout << setprecision(20) << ecks << endl;
    return 0;
}
