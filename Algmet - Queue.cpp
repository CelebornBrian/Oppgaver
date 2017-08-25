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

class Queue
{
private:
	struct node {
		itemType key;
		struct node *next;
	};
	struct node *head, *z;
public:
	Queue(int max = 100);
	~Queue();
	void put(itemType v);
	itemType get();
	bool empty();
	void skrivQueue();
};

int main() {
	itemType variabel[] = "EAS*Y**QUE***ST***I*ON**";
	Queue main;
	cout << "Queue:\n";
	for (int i = 0; i < strlen(variabel + 1); i++)
	{
		if (variabel[i] == '*')
		{
			main.get();
		}
		else
		{
			main.put(variabel[i]);
		}
		main.skrivQueue();
	}
	return 0;
}

Queue::Queue(int max)
{
	head = new node;
	z = new node;
	head->next = z;
	z->next = z;
}

Queue::~Queue()
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

void Queue::put(itemType v)
{
	struct node *t = new node, *s = head;
	while (s->next != z)
	{
		s = s->next;
	}
	t->key = v;
	t->next = z;
	s->next = t;
}

itemType Queue::get()
{
	itemType x = head->next->key;
	struct node *t = head->next;
	if (head->next != z) {
		head->next = t->next;
		delete t;
	}
	else cout << "Liste tom\n";
	return x;
}

bool Queue::empty()
{
	return head->next == z;
}

void Queue::skrivQueue()
{
	node *t = head->next;
	while (t != z)
	{
		cout << t->key << ' ';
		t = t->next;
	}
	cout << endl;
}
