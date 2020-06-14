# log_analyzer
This is a C++ project for my Data Structures and Algorithms class. <br/>
There is a log file that consists of HTTP requests to a web server. An example part is given below from [access_log](./access_log) file:

```
local - - [24/Oct/1994:13:41:41 -0600] "GET index.html HTTP/1.0" 200 150
local - - [24/Oct/1994:13:41:41 -0600] "GET 1.gif HTTP/1.0" 200 1210
local - - [24/Oct/1994:13:43:13 -0600] "GET index.html HTTP/1.0" 200 3185
local - - [24/Oct/1994:13:43:14 -0600] "GET 2.gif HTTP/1.0" 200 2555
local - - [24/Oct/1994:13:43:15 -0600] "GET 3.gif HTTP/1.0" 200 36403
local - - [24/Oct/1994:13:43:17 -0600] "GET 4.gif HTTP/1.0" 200 441
local - - [24/Oct/1994:13:46:45 -0600] "GET index.html HTTP/1.0" 200 3185
local - - [24/Oct/1994:13:46:45 -0600] "GET 2.gif HTTP/1.0" 200 2555
local - - [24/Oct/1994:13:46:47 -0600] "GET 3.gif HTTP/1.0" 200 36403
local - - [24/Oct/1994:13:46:50 -0600] "GET 4.gif HTTP/1.0" 200 441
```

> The columns represent **Host**, **Timestamp**, **Filename**, **HTTP Reply Code**, **Bytes in Reply** respectively. 

This program reads the log file line by line, finds the *filenames* of each file, inserts them into a suitable data structure and counts them. **Note that** filenames are the strings between *GET* and *HTTP* strings in the above example such as `index.html`, `1.gif`, `2.gif` etc. After reading and processing is over, it lists the "Top 10" most visited web pages in decreasing order of the number of total visitors. A sample output is given in below:

```
Filename1	# of total visitors
Filename2	# of total visitors
Filename3	# of total visitors
Filename4	# of total visitors
Filename5	# of total visitors
.
.
.
Filename10	# of total visitors

Total Elapsed Time : X seconds
```

## Data Structures Used :books:

### Node
There is a node structure which consists of **a string**, **an integer**, **two pointers of itself**, **a print function** and **a constructor**. Check it [over here.](./Linkedlist.h#L6)

### Linked List
This project includes a _sorted doubly linked list_. This linked list class includes the following:

- Two private pointers which keep the first and last member of the linked list
- A constructor and a deconstructor
- A function which returns a node pointer to get the first member of the linked list
- A function that returns the size of the linked list
- A function to check if the list is empty
- A function to insert a node to the list
- A swap function which is used inside of the insert function with the purpose of ordering the inserted nodes

```cpp
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
```

### Hash Table

The table size is defined. This hash table class includes the following:

- A table which consists of linked lists
- A hash function to convert string type to integer
- An array of top ten elements
- A constructor and a deconstructor
- A function to insert a node to the table of linked lists
- A function which fills the top ten array and prints it

```cpp
class Hashtable
{
	static const int tablesize=2048;
	LinkedList table[tablesize];
	int hash(string filename);
	Node* top_ten[10];

public:
	Hashtable();
	~Hashtable();
	void insert(string f);
	void topten();
};
```

# Execution
- All files must be in the same folder.
- Compile and run **Source.cpp**.
- After run, program will find and sort top 10 web pages according to its occurance by their name, which are in **access_log** file. You can change the file that the code reads [over here.](./Source.cpp#L16)

:warning: _Note:_ If you generate an executable file, it should be in the same directory with the **access_log** file.
