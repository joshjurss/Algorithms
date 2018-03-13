#include <string>
#include <iostream>
#include <array>
#include <list>

using namespace std;


void palindromeTest(string word1, string word2)
{
	for (int i = 1; i <= word1.length(); i++)
	{
		word2 += word1[word1.length() - i];
	}

	if (word1 == word2)
	{
		cout << "\nPALINDROME\n";
	}
	else
	{
		cout << "\nNON-PALINDROME\n";
	}
}

void createArray()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
}

void createList(string first)
{
	list<int> list1;

	list1.push_back(1);


	for (auto i : list1)
	{
		cout << i << "\n";
	}
}

int main() 
{
	string test;
	string word2 = "";

	string name = "Josh";
	string hello = "Hello there";

	test.append(hello + " " + name);
	cout << test << endl;

	cin >> test;

	palindromeTest(test, word2);

	createArray();
	createList(name);

	cin.ignore();
	cin.get();

	return 0;
}
