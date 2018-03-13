#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

/*uses recursion, hash map*/

unordered_map<string, string> test;
vector<string>words;

void initMap()
{
	test["2"] = "A", test["22"] = "B", test["222"] = "C";
	test["3"] = "D", test["33"] = "E", test["333"] = "F";
	test["4"] = "G", test["44"] = "H", test["444"] = "I";
	test["5"] = "J", test["55"] = "K", test["555"] = "L";
	test["6"] = "M", test["66"] = "N", test["666"] = "O";
	test["7"] = "P", test["77"] = "Q", test["777"] = "R", test["7777"] = "S";
	test["8"] = "T", test["88"] = "U", test["888"] = "V";
	test["9"] = "W", test["99"] = "X", test["999"] = "Y", test["9999"] = "Z";
	test["#"] = " ";
}

void getInput()
{
	string input = "-1";

	cin >> input;
	cout << test[input] << "\n";
	words.push_back(test[input]);

	if (input != "0")
	{
		getInput();
	}
	else
	{
		for (int i = 0; i < words.size(); i++)
		{
			cout << words[i];
		}
	}
}

int main()
{
	initMap();

	getInput();

	cin.ignore();
	cout << "\nHit enter to exit";
	cin.get();
	return 0;
}