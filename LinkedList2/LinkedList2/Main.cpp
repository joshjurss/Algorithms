/*************************************
**  Name:   Josh Jurss				**
**	Date:	Nov 4, 2015				**
** 	Lab:	Lab 19					**
**	Desc:	Linked List				**
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

ofstream ofs("jurss_lab19.txt");
/*************************************
**		  ---Variables---			**
*************************************/
string no = "EOF MESSAGE: ";
string hard = "Josh Jurss ";
string coding = "Nov 4, 2015 ";
string of = "Linked List ";
string labn = "Lab19 ";
string course = "CIS2542-001 ";
string anything = "Cheers!";
string sp = " ";
string star =
"|-----------------------------------------------------------------------------|";
string star2 =
"|=============================================================================|";
string rstar = " |";
string lstar = "| ";
string header = "---Linked List---";
string sl = "/";
string co = ", ";
string col = ":";
string qu = "?";
string pcnt = "%";

string add = "Do you want to add the item";
char yes = 'y';
string output =
"|=============================================================================|\n"
"| Entered Value                                                               |\n"
"|=============================================================================|\n";
/*************************************
**		  Linked List Class			**
*************************************/
class Link_list
{
private:
	string name;
	Link_list *next_node;
public:
	void add_item(Link_list *);
	void add_item();
	friend void show(Link_list *sptr)
	{
		ofs << output;
		while (sptr)
		{
			ofs << lstar << setw(75) << left;
			ofs << sptr->name;
			sptr = sptr->next_node;
			ofs << rstar << endl;
		}
	}
};

void Link_list::add_item()
{
	cin >> name;
	next_node = NULL;
}
void Link_list::add_item(Link_list *pptr)
{
	cin >> name;
	next_node = NULL;
	pptr->next_node = this;
}

/*************************************
**				Lab19				**
*************************************/
void lab19()
{
	Link_list *str_ptr = NULL;
	Link_list *curr_ptr = str_ptr;
	Link_list *prev_ptr;
	char ch = yes;

	str_ptr = new(Link_list);
	str_ptr->add_item();
	curr_ptr = str_ptr;
	do
	{
		prev_ptr = curr_ptr;
		curr_ptr = new(Link_list);
		curr_ptr->add_item(prev_ptr);
		cout << add << endl;
		cin >> ch;
	} while (ch != 'n');
	show(str_ptr);


}

/*************************************
**				Header				**
*************************************/
void hdr()
{
	ofs << star << endl << lstar;
	ofs << left << course << setw(63) <<
		header << right;
	ofs << rstar << endl;
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
	ofs << right << setw(16) << rstar
		<< endl << star2 << endl;
}
/*************************************
**		  ---Main Function---	 	**
*************************************/
void main()
{
	hdr();
	lab19();
	ftr();
	eof();
}