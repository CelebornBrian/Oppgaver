//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>

using namespace  std;

//  CONST:


//  ENUM:


//  STRUCT
//Node
struct node
{
	char info;					//Info contained in node
	struct node *l, *r;			//Pointer to left and right node
	bool visitedL, visitedR;	//Check if left or right has been visited
};

//Typedef node pointer to itemType
typedef node* itemType;

//  KLASSE:

class Stack
{
private:
	itemType *stack;	//Pointer to stack
	int p;				//Int for length of used array
public:
	Stack(int max = 100);	//Constructor with default length 100
	~Stack();				//Destructor
	void push(itemType v);	//Push itemType on stack
	itemType pop();			//Pop last from stack
	bool isempty();			//Check if empty
	void skrivArray();		//Write array to screen (Should just be root)
};

//  DEKLARASJON AV FUNKSJONER:
void generateTree();
void visit(itemType t);

void recursivePreOrder(itemType t);
void recursiveInOrder(itemType t);
void recursivePostOrder(itemType t);
int recursivePostOrderChange(itemType t);

//  GLOBALE VARIABLE:
Stack stack(50);						//Create stack array 50 long
itemType x, z;						//Declare head and tail nodes
char text[] = "A B C + D E * * F + *";	//Text for tree

//  HOVEDPROGRAM:
int main() {
	z = new node;					//Setting z to point to a new node
	z->l = z;						//That points to itself
	z->r = z;

	generateTree();						//Generate the tree

	cout << "\nPreorder: \n";
	recursivePreOrder(x);
	cout << "\nInorder: \n";
	recursiveInOrder(x);
	cout << "\nPostorder: \n";
	recursivePostOrder(x);
	cout << "\nPostorder, bokstaver byttet med tall og regnet ut: \n"
		<< recursivePostOrderChange(x) << endl;

	return 0;
}

//  DEFINISJON AV KLASSE-FUNKSJONER:
Stack::Stack(int max)					//Constructor
{
	stack = new itemType[max];			//Create new array
	p = 0;								//Used 0 so far
}

Stack::~Stack()
{
	delete[] stack;						//Delete stack
}

void Stack::push(itemType v) {
	stack[p++] = v;						//Push parameter to stack
}

itemType Stack::pop() {
	return stack[--p];					//Pop last item and return
}

bool Stack::isempty() {
	return !p;							//Return true if empty, false if not
}

void Stack::skrivArray() {				//Write what is currently in the array
	for (int i = 0; i < p; i++)			//Loop through the array
	{
		cout << stack[i]->info << ' ';	//And write the element's info
	}
}



//  DEFINISJON AV FUNKSJONER:

void generateTree()						//Generate the tree
{
	for (int i = 0; i < strlen(text); i++)	//Loop through array
	{
		if (text[i] != ' ')				//Only if there is not blank
		{
			x = new node;				//x points to new node
			x->info = text[i];			//Give the new node the info from the array
			x->l = z;					//Both the left and 
			x->r = z;					//right points to z
			x->visitedL = x->visitedR = false;	//Sett both visited to false
			if (text[i] == '+' || text[i] == '*')	//If there was a + or *
			{
				x->r = stack.pop();		//Set right pointer to what was last on stack
				x->l = stack.pop();		//and left to what is now last on stack
			}
			stack.push(x);				//Then push this node on stack
		}
	}
}

void visit(itemType t) {					//Visit note t
	cout << t->info << "  ";			//Write the info to screen
}

void recursivePreOrder(itemType t)
{
	visit(t);
	if (t->l != z)
	{
		recursivePreOrder(t->l);
	}
	if (t->r != z)
	{
		recursivePreOrder(t->r);
	}
}

void recursiveInOrder(itemType t)
{
	if (t->l != z)
	{
		recursiveInOrder(t->l);
	}
	visit(t);
	if (t->r != z)
	{
		recursiveInOrder(t->r);
	}
}

void recursivePostOrder(itemType t)
{
	if (t->l != z)
	{
		recursivePostOrder(t->l);
	}
	if (t->r != z)
	{
		recursivePostOrder(t->r);
	}
	visit(t);
}

int recursivePostOrderChange(itemType t)
{
	if (t->info == '+')
	{
		return recursivePostOrderChange(t->l) + recursivePostOrderChange(t->r);
	}
	else if (t->info == '*')
	{
		return recursivePostOrderChange(t->l) * recursivePostOrderChange(t->r);
	}
	else
	{
		int tall;
		cout << "\nErstatt " << t->info << " med tallet: ";
		cin >> tall; 
		return tall;
	}
}