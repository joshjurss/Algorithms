/*************************************
**  Name:   Josh Jurss				**
**	Date:	Nov 7, 2015				**
** 	Lab:	Lab 21					**
**	Desc:	Linked List with append	**
**			and delete utilized		**
**			and NODES				**
*************************************/
#include <iostream>
#include <string>
#include <fstream> 	
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;
ofstream ofs("jurss_lab21.txt");
/*************************************
**		  ---Variables---			**
*************************************/
string no = "EOF MESSAGE: ";
string hard = "Josh Jurss ";
string coding = "Nov 7, 2015 ";
string of = "Linked List/Nodes ";
string labn = "Lab21 ";
string course = "CIS2542-001 ";
string anything = "Cheers!";
string sp = " ";
string star =
"|-----------------------------------------------------------------------------|";
string star2 =
"|=============================================================================|";
string rstar = " |";
string lstar = "| ";
string header = "---Linked List Number Append---";
string sl = "/";
string co = ", ";
string col = ":";
string qu = "?";
string pcnt = "%";

string input;
int menuSelection;
int number;

/*************************************
**	 ---Good looking Menu Prints---	**
*************************************/
string menu1 =
"\n|=============================================================================|\n"
"|                          What would you like to do?                         |\n"
"|-----------------------------------------------------------------------------|\n"
"|  1. Append Number to List                                                   |\n"
"|-----------------------------------------------------------------------------|\n"
"|  2. Delete Number from List                                                 |\n"
"|-----------------------------------------------------------------------------|\n"
"|  3. Print and Exit                                                          |\n"
"|=============================================================================|\n"
"| Selection: ";
string err = "ERROR: Input must be between 1-3 \n"
"Please try again: ";
string menu2 =
"|=============================================================================|\n"
"| Please type the number to append below.                                     |\n"
"|=============================================================================|\n"
"| Number: ";
string menu3 =
"|=============================================================================|\n"
"| Current List                                                                |\n"
"|=============================================================================|\n";
string menu4 =
"|=============================================================================|\n"
"| Please type the number to remove below.                                     |\n"
"|=============================================================================|\n"
"| Number: ";
/*************************************
**		Function Declaration		**
*************************************/
double errCheck3(string test);
void hdr();
void ftr();
void eof();
/*************************************
**		  ---Node Class---			**
*************************************/
class Node {
	friend class List;
	int data;
	Node* next;

public:
	Node() {};
	void SetData(int aData) { data = aData; };
	void SetNext(Node* aNext) { next = aNext; };
	int Data() { return data; };
	Node* Next() { return next; };
};
/*************************************
**		  ---List Class---			**
*************************************/
class List {
	Node *head;
public:
	List() { head = NULL; };
	void Print();
	void Print(int n);
	void Append(int data);
	void Delete(int data);
	int size();
};
int List::size()
{
	int cnt = 0; /* counter */
	Node* pNode = head;
	/* traverse the list */
	while (pNode != NULL) {
		/* Update the counter */
		cnt++;
		/* move along to the next node */
		pNode = pNode->next;
	}
	return cnt;
}
/*************************************
**	   ---Print List Contents---	**
*************************************/
void List::Print() {
	Node *tmp = head;

	if (tmp == NULL) {
		cout << "EMPTY" << endl;
		return;
	}

	if (tmp->Next() == NULL) {
		cout << tmp->Data();
		cout << "--> ";
		cout << "NULL" << endl;
	}
	else {
		do {
			cout << tmp->Data();
			cout << "--> ";
			tmp = tmp->Next();
		} while (tmp != NULL);

		cout << "NULL" << endl;
	}
}
/*************************************
** ---Print List Contents to File---**
*************************************/
void List::Print(int n) {
	List list;
	Node *tmp = head;
	ofs << lstar;
	if (tmp == NULL) {
		ofs << setw(75) << left << "EMPTY" << rstar << endl;
		return;
	}

	if (tmp->Next() == NULL) {
		ofs << tmp->Data();
		ofs << "--> ";
		ofs << setw(68) << left << "NULL" << rstar << endl;
	}
	else {
		do {
			ofs << tmp->Data();
			ofs << "--> ";
			tmp = tmp->Next();
		} while (tmp != NULL);

		switch (n)
		{
		case 1:
			ofs << "NULL" << setw(60) << right << rstar << endl;
			break;
		case 2:
			ofs << "NULL" << setw(59) << right << rstar << endl;
			break;
		case 3:
			ofs << "NULL" << setw(52) << right << rstar << endl;
			break;
		case 4:
			ofs << "NULL" << setw(45) << right << rstar << endl;
			break;
		case 5:
			ofs << "NULL" << setw(38) << right << rstar << endl;
			break;
		case 6:
			ofs << "NULL" << setw(31) << right << rstar << endl;
			break;
		case 7:
			ofs << "NULL" << setw(24) << right << rstar << endl;
			break;
		case 8:
			ofs << "NULL" << setw(17) << right << rstar << endl;
			break;
		case 9:
			ofs << "NULL" << setw(10) << right << rstar << endl;
			break;
		case 10:
			ofs << "NULL" << setw(3) << right << rstar << endl;
			break;
		default:
			ofs << "NULL" << setw(15) << right << rstar << endl;
			break;
		}
	}
}
/*************************************
** ---Append Node to Linked List---	**
*************************************/
void List::Append(int data) {
	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);

	Node *tmp = head;

	if (tmp != NULL) {
		while (tmp->Next() != NULL) {
			tmp = tmp->Next();
		}
		tmp->SetNext(newNode);
	}
	else {
		head = newNode;
	}
}
/*************************************
**	 ---Delete Node From List---	**
*************************************/
void List::Delete(int data) {
	Node *tmp = head;

	if (tmp == NULL)
		return;

	if (tmp->Next() == NULL) {
		delete tmp;
		head = NULL;
	}
	else {
		Node *prev = tmp;
		do {
			if (tmp->Data() == data) break;
			prev = tmp;
			tmp = tmp->Next();
		} while (tmp != NULL);

		prev->SetNext(tmp->Next());
		delete tmp;
	}
}
/*************************************
**		   Displays Main Menu		**
*************************************/
void displayMenuMain()
{
	system("cls");
	cout << menu1;
}
/*************************************
**			LAB 21 FUNCTION			**
**	Calls other functions and shows	**
**	fancy menu output for better	**
**	user functionality.				**
*************************************/
void lab21()
{
	List list;
	hdr();
	menuSelection = 0;
	list.Print(menuSelection);
	while (menuSelection != 3)
	{
		displayMenuMain();
		do
		{
			getline(cin, input);
			menuSelection = errCheck3(input);
		} while (menuSelection == 0);
		cout << endl;

		switch (menuSelection)
		{
		case 1:
			system("cls");
			cout << menu2;
			cin >> number;
			list.Append(number);
			cout << menu3 << lstar;
			list.Print();
			list.Print(list.size());
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << menu3 << lstar;
			list.Print();
			cout << menu4;
			cin >> number;
			cout << menu3 << lstar;
			list.Delete(number);
			list.Print();
			list.Print(list.size());
			system("pause");
			system("cls");
			break;
		case 3:
			ftr();
			eof();
			break;
		default: cout << err << endl;
		}
	}
};
/*************************************
**		  ---Main Function---	 	**
*************************************/
void main()
{
	lab21();
}
/*************************************
**		  ---Error Check---			**
**	Specific error checks for input	**
**	from user.						**
*************************************/
double errCheck3(string test)
{
	int secondTest;
	string test2;
	if (test.length() == 0)
	{
		return 0;
	}
	if (atoi(test.c_str()) < 1)
	{
		cout << err;
		return 0;
	}
	if (atoi(test.c_str()) > 3)
	{
		cout << err;
		return 0;
	}
	secondTest = atoi(test.c_str());

	test2 = to_string(secondTest);

	if (test.length() != test2.length())
	{
		cout << err;
		return 0;
	}
	else
	{
		return secondTest;
	}
}
/*************************************
**				Header				**
*************************************/
void hdr()
{
	ofs << star2 << endl << lstar;
	ofs << left << course << setw(63) <<
		header << right;
	ofs << rstar << endl << star2 << endl;
}
/*************************************
**				Footer				**
*************************************/
void ftr()
{
	ofs << star2 << endl << lstar;
	ofs << left << hard << coding;
	ofs << labn << course << right
		<< setw(36) << rstar;
	ofs << endl;
}
/*************************************
**			  EOF Message			**
*************************************/
void eof()
{
	ofs << star << endl << lstar;
	ofs << left << no << hard << coding;
	ofs << of << labn << anything;
	ofs << right << setw(10) << rstar
		<< endl << star2 << endl;
}