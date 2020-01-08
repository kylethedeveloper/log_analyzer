#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string fileName;
	int count;
	Node*rlink;
	Node*llink;
	static void print(Node *a);
	Node();
};

class LinkedList
{
	Node *first, *last;
	int size;

public:
	LinkedList();
	~LinkedList();

	Node* getFirst();

	int getSize();
	bool isEmpty();

	void insert(string s);

	void swap(Node *a, Node *b);
};