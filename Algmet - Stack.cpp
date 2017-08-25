//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Create stack
//Create stack with class
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;

typedef char itemType;

class Stack
{
private:
	struct node {
		itemType key;
		struct node *next;
	};
	struct node *head, *z;
public:
	Stack(int max = 100);
	~Stack();
	void push(itemType v);
	itemType pop();
	bool empty();
	void skrivStack();
};

int main() {
	itemType variabel[] = "EAS*Y**QUE***ST***I*ON**";
	Stack main;
	for (int i = 0; i < strlen(variabel+1); i++)
	{
		if (variabel[i] == '*')
		{
			main.pop();
		}
		else
		{
			main.push(variabel[i]);
		}
		main.skrivStack();
	}
	return 0;
}

Stack::Stack(int max)
{
	head = new node;
	z = new node;
	head->next = z;
	z->next = z;
}

Stack::~Stack()
{
	struct node *t = head;
	while (t != z)
	{
		head = t;
		t = t->next;
		delete head;
	}
	delete z;
}

void Stack::push(itemType v)
{
	struct node *t = new node;
	t->key = v;
	t->next = head->next;
	head->next = t;
}

itemType Stack::pop()
{
	itemType x;
	struct node *t = head->next;
	head->next = t->next;
	x = t->key;
	delete t;
	return x;
}

bool Stack::empty()
{
	return head->next == z;
}

void Stack::skrivStack()
{
	node *t = head->next;
	while (t != z)
	{
		cout << t->key << ' ';
		t = t->next;
	}
	cout << endl;
}
