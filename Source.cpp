#include <fstream>
#include <ctime>
#include "linkedlist.h"
#include "Hashtable.h"
using namespace std;


int main() 
{

	time_t start = time(0);
	string word;
	Hashtable names;

	ifstream file;
	file.open("access_log"); //open the file

	if (file.is_open()) 
	{
		while (file >> word) //reading word by word
		{
			if (word.find('.') != string::npos && word.find('"') == string::npos) //finding file names from the file
			{
				names.insert(word); //insert word to the list
			}
		}
		names.topten(); //print top ten
	}
	else 
	{
		cout << "Error ! File can not be opened !" << endl; //error message
	}

	double seconds_since_start = difftime(time(0), start); //calculating time elapsed
	cout << "Total Elapsed Time : " << seconds_since_start << " seconds" << endl;

	return 0;
}