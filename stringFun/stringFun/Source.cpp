#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	string test = "2113500";

	do
	{
		cout << "Card Number: ";
		cin >> s;

		if (s.length() != 14 || s.substr(0, 7) != test)
		{
			cout << "Error - Please enter 12 digits\nStarting with 2113500\n";
		}

	} while (s.length() != 14 || s.substr(0, 7) != test);

	for (int i = 0; i < s.size(); i++)
	{ 
		cout << s[i];
	}

	cout << "\n\n" << s.substr(7, 13);

	cout << endl;

	system("Pause");
	return 0;
}