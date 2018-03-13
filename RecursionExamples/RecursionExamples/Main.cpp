#include <iostream>
#include <math.h>
#include <array>

using namespace std;

void binary(int n)
{
	if (n == 0)
		return;

	binary(n / 2);
	printf("%d", n % 2);
}

void printStars(int n)
{
	//Recursion for add 4 + 3 + 2 + 1

	int i = 0;
	if (n > 1)
		printStars(n - 1);
	for (i = 0; i < n; i++)
		printf(" * ");
}

int findFactoral(int n)
{
	//Recursion for add 4!
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * findFactoral(n - 1);
	}
}

//Gets power of double
double powers(double d, int pow)
{
	if (pow == 0)
	{
		return 1;
	}

	if (pow % 2 == 0)
	{
		d = powers(d, pow / 2);
		return d*d; 
	}
	else
	{
		return d * powers(d, pow - 1);
	}
}

void main()
{
	cout << "Enter a number: ";

	int num;
	cin >> num;

	cout << "Your number in binary is: ";
	//returns number in binary
	binary(num);

	//prints stars
	cout << "\n";
	printStars(num);

	cout << "\n";
	cout << findFactoral(num);

	double test1;
	int power;
	cout << "\nEnter number: ";
	cin >> test1;
	cout << "Enter Power: ";
	cin >> power;

	cout << powers(test1, power);

	int test[5] = { 1, 2, 3, 4, 5 };
	
	cout << test[2];

	cin.ignore();
	cin.get();
}