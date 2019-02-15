//
//  main.cpp
//  E limit
//
//  Created by Sean Tesch on 10/24/17.
//  Copyright © 2017 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x = 1.0, e = 2.71828, y = 0;
    int it = 0;
    
    do
    {
        y = 1 / x;
        y = 1 + y;
        y = pow(y, x);
        x++;
        it++;
        cout << it << " " << y << endl;
    } while (y != e);
    
    return 0;
}
