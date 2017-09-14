//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Create stack, build binery tree, traverse tree via preorder
//Create stack with class ^^
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;

//Node
struct node
{
	char info;					//Info contained in node
	struct node *l, *r;			//Pointer to left and right node
	bool visitedL, visitedR;	//Check if left or right has been visited
};

//Typedef node pointer to itemType
typedef node* itemType;

//Class
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

void generateTree();
void traversePreOrder(struct node *t);	//Traverse tree in a Preorder way
void traversePostOrder(struct node *t);	//Traverse tree in a Postorder way
void visit(struct node *t);				//Visit node, write info on screen
void recursiveInternalNodeNumber(struct node *t);
void recursiveExternalNodeNumber(struct node *t);
void recursiveFullNodes(struct node *t);
void recursiveTreeHight(struct node *t);

Stack stack(50);						//Create stack array 50 long
struct node *x, *z;						//Declare head and tail nodes
char text[] = "A B C + D E * * F + *";	//Text for tree
int totIntNode = 0, hight = 0;


int main() {
	z = new node;					//Setting z to point to a new node
	z->l = z;						//That points to itself
	z->r = z;

	generateTree();						//Generate the tree
										//stack.skrivArray();	//Write root
	//traversePreOrder(x);				//Travel preorder
	//generateTree();					//Generete the tree again
	//traversePostOrder(x);				//Travel postorder
	//recursiveInternalNodeNumber(x);	//Teller antall interne noder
	//recursiveExternalNodeNumber(x);
	//recursiveFullNodes(x);
	recursiveTreeHight(x);
	cout << totIntNode;
	cout << endl;
	return 0;
}

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

void traversePreOrder(node *t)			//Traverse the tree in a preorder way
{
	while (!stack.isempty())			//As long as the stack is not empty
	{
		t = stack.pop();				//Pop the last node
		visit(t);						//Visit the node
		if (t->r != z)					//If right side is not a z node
		{
			stack.push(t->r);			//Push that node back on the stack
		}
		if (t->l != z)					//Same for left side
		{
			stack.push(t->l);			//Push it back if it's not a z node
		}
	}
}

void traversePostOrder(node * t)		//Traverse the tree in a post order way
{
	struct node *x = t, *y;				//Some help pointers
	while (!stack.isempty())
	{
		if (x->visitedL && x->visitedR)	//If both left and right side is visited
		{
			visit(x);					//visit this node
			x = stack.pop();			//and pop the next node
		}
		else if (x->visitedL && !x->visitedR)	//If only left is visited
		{
			y = x;
			x->visitedR = true;			//Set that we visit right
			if (x->r != z)				//If right side is not a z node
			{
				x = x->r;				//Set x to be x's right
				stack.push(y);			//and push what was x (now y)
			}
		}
		else if (!x->visitedL)			//If nothing has been visited
		{
			y = x;
			x->visitedL = true;			//Set that we have visited left
			if (x->l != z)				//If left ptr is not z
			{
				x = x->l;				//Go there
				stack.push(y);			//And push where we were
			}
		}
	}
}

void visit(node *t) {					//Visit note t
	cout << t->info << " - ";			//Write the info to screen
}

void recursiveInternalNodeNumber(node * t)
{
	totIntNode += 1;
	if (t->l != z)
	{
		recursiveInternalNodeNumber(t->l);
	}
	if (t->r != z)
	{
		recursiveInternalNodeNumber(t->r);
	}
}

void recursiveExternalNodeNumber(node * t)
{
	recursiveInternalNodeNumber(t);
	totIntNode += 1;
}

void recursiveFullNodes(node * t)
{
	if (t->l != z && t->r != z)
	{
		totIntNode++;
	}
	if (t->l != z)
	{
		recursiveFullNodes(t->l);
	}
	if (t->r != z)
	{
		recursiveFullNodes(t->r);
	}
}

void recursiveTreeHight(node * t)
{
	hight++;
	if (t != z)
	{
		recursiveTreeHight(t->l);
		recursiveTreeHight(t->r);
		if (hight > totIntNode)
		{
			totIntNode = hight;
		}
	}
	hight--;
}
