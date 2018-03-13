#include <iostream>
#include <string>

using namespace std;

int findFactoral(int n)
{
	//Recursive example
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * findFactoral(n - 1);
	}
}

int findFactoralIterative(int n)
{
	//Iterative Example
	int total = 1;

	if (n == 1)
	{
		return 1;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			total = total * i;
		}

		return total;
	}
}

int main()
{
	int input;
	cout << "Enter a number: ";
	cin >> input;

	cout << "\nRecursive Example\nFactoral of " << input << " is: " << findFactoral(input);

	cout << "\nIterative Example\nFactoral of " << input << " is: " << findFactoralIterative(input);


	cin.ignore();
	cin.get();
	return 0;
}