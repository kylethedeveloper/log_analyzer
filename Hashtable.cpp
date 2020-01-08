#include "Hashtable.h"

Hashtable::Hashtable() //The constructer of the Hashtable
{	
	for (int i = 0; i < 10; i++) 
	{
		top_ten[i] = nullptr;
	}
}

int Hashtable::hash(string filename) // The hash function which returns an int value according to string entered
{
	int h = 0;
	for (int i = filename.length() - 1; i >= 0; i--)
	{
		h = (filename[i]+h*31) % tablesize ;
	}
	return h;
}

Hashtable::~Hashtable() // The deconstructer of the Hashtable
{
	for (int i = 0; i < tablesize; i++){
		if (!table[i].isEmpty())
		{
			table[i].~LinkedList();
		}
	}
}

void Hashtable::insert(string filename) // Inserts a element to the Hashtable by using the insert function of Linkedlist
{
	table[hash(filename)].insert(filename);
}

void Hashtable::topten() // Fills the topten array and prints it
{
	Node* temp = new Node;
	temp->count = 0;

	for (int i = 0; i < 10; i++) // Fills the topten array with a node which has a count variable 0.
	{
		top_ten[i] = temp;
	}

	for (int i = 0; i < tablesize; i++) // Fills the topten array sorted
	{ 
		for (int a = 0; a < 10 ; a++)
		{
			if (!table[i].isEmpty())
			{
				if (top_ten[a]->count < table[i].getFirst()->count)
				{
					for (int k = 9; k > a; k--)
					{
						top_ten[k] = top_ten[k - 1];
					}
					top_ten[a] = table[i].getFirst();
					break;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) // Prints the topten array
	{
		Node::print(top_ten[i]);
	}
}