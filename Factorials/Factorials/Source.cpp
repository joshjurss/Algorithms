#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string input;
	cout << "Enter your password: ";
	cin >> input;

	sort(input.begin(), input.end());

	do
	{
		cout << input << endl;
	} while (next_permutation(input.begin(), input.end()));


	cin.ignore();
	cin.get();
	return 0;
}