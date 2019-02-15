#include <iostream>

using namespace std;
int factorial(int, int);

int main()
{
    int inputNum;

    cout << "Enter a number for which you want the factorial" << endl;
    cout << "(Use -1 to quit) - ";
    cin >> inputNum;

    while (inputNum != -1)
    {
	cout << "The factorial of " << inputNum << " is:" << endl << factorial(inputNum,1) << endl;
	cout << "Enter another number - ";
	cin >> inputNum;
    }

    return 0;
}

int factorial(int n, int depth)
{
    for (int i = 0; i < depth; i++)
	cout << "  ";
    cout << "Calculating at depth " << depth << endl;
    if (n == 1)
    {
	for (int i = 0; i < depth; i++)
        cout << "  ";
	cout << "Hit stopping condition, returning 1" << endl;
	return(n);
    }
    else
    {
	for (int i = 0; i < depth; i++)
        cout << "  ";
	cout << "Going deeper and returning " << n << "*factorial of " << (n - 1) << endl;
	return(n*factorial(n - 1, depth + 1));
    }
}
