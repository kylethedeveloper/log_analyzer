#include "linkedlist.h" 

LinkedList::LinkedList() // The constructer of Linkedlist 
{ 
	first = nullptr;
	last = nullptr;
	size = 0;
} 

LinkedList::~LinkedList() // The deconstructer of Linkedlist
{
	Node* temp = first;

	while (temp != nullptr) {
		first = first->rlink;
		delete temp;
		temp = first;
	}
	last = nullptr;
	size = 0;
	
}

Node * LinkedList::getFirst() // Returns the first member of Linkedlist
{ 
	return first;
}

int LinkedList::getSize() // Returns the size of the Linkedlist
{
	return size;
}

bool LinkedList::isEmpty() // Checks if the LinkedList is empty
{
	return first==nullptr;
}

void LinkedList::swap(Node * a, Node * b) // Swaps two nodes position in a Linkedlist
{
	if (a->llink == a) // If a is the first node of the Linkedlist
	{
		if (b->rlink == nullptr) // If b is the last node of the Linkedlist
		{
			a->llink = b;
			b->rlink = a;
			a->rlink = nullptr;
			first = b;
			b->llink = first;
		}
		else
		{
			a->llink = b;
			b->rlink->llink = a;
			a->rlink = b->rlink;
			b->rlink = a;
			first = b;
			b->llink = first;
		}
		
	}
	else if (b->rlink == nullptr) // If b is the last node of the Linkedlist
	{
		b->rlink = a;
		a->llink->rlink = b;
		b->llink = a->llink;
		a->rlink = nullptr;
		a->llink = b;
		last = a;
	}
	else 
	{
		a->rlink = b->rlink;
		b->rlink->llink = a;
		a->llink->rlink = b;
		b->rlink = a;
		b->llink = a->llink;
		a->llink = b;
	}
}

void LinkedList::insert(string s) // Inserts a element to the Linkedlist
{
	bool found = false;

	if (first == nullptr) // If list is empty
	{
		Node *valuenode = new Node;

		valuenode->fileName = s;
		valuenode->count = 1;

		first = last = valuenode;
		valuenode->llink = first;
		size++;
	}
	else  // If list is not empty
	{
		Node *temp = first;
		Node *btemp = first; // the previous member of temp
		while (temp != nullptr)
		{
			if (temp->fileName == s) // If list has a member which has fileName as input increase count of the member
			{
				found = true;
				temp->count++;
				while (btemp->count < temp->count) // Uses swap function to keep the Linkedlist sorted
				{
					swap(btemp, temp); 
					if (temp->llink != temp)
					{
						btemp = temp->llink;
					}
					else break;
				}
				break;
			}
			btemp = temp;
			temp = temp->rlink;
		}
		if (found == false) // If node is not found insert a new node to last 
		{
			Node *valuenode = new Node;

			valuenode->fileName = s;
			valuenode->count = 1;

			valuenode->llink = last;
			last->rlink = valuenode;
			last = valuenode;
			size++;
		}
	}
}

void Node::print(Node *a) // Prints node pointers filename and count
{
		cout << a->fileName << "\t " << "of total visitors : " << a->count << endl;
}

Node::Node() // The constructer of the node
{
	fileName = "";
	count = 0;
	rlink = llink = nullptr;
}

