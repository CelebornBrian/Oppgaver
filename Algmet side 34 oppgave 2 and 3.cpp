//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Oppgave 2 i algmet boka kapittel 3
//Implementere movenexttofront i linked list
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
using namespace std;


void movenexttofront(struct node *t, node* head);
void exchange(struct node *t, struct node *u);
void skrivListe(struct node *head, node* z);

struct node
{
	int key; node* next;
};
int main() {
	int N, M;
	node *t, *head, *z;
	cin >> N >> M;
	head = new node;
	t = new node; t->key = 1; head->next = t;
	z = new node; z->next = z;
	for (int i = 2; i <= N; i++)
	{
		t->next = new node;
		t = t->next; t->key = i;
	}
	t->next = z;
	skrivListe(head, z);
	t = head;
	
	if (t != t->next)
	{
		for (int i = 1; i <= M; ++i)
		{
			t = t->next;
		}
		//movenexttofront(t, head);
		exchange(t, t->next->next->next);
	}
	else
	{
		cout << "Kan ikke flytte hale!\n";
	}
	skrivListe(head, z);
	return 0;
}

void movenexttofront(node * t, node * head)
{
	node* y;
	y = t->next;
	t->next = y->next;
	y->next = head->next;
	head->next = y;
}

void exchange(node * t, node * u)
{
	node *z, *w;
	z = t->next;
	w = u->next->next;
	t->next = u->next;
	u->next->next = z->next;
	u->next = z;
	z->next = w;
}

void skrivListe(node * head, node* z)
	{
	node* y;
	y = head->next;
	while (y->next != y)
	{
		cout << y->key; cout << ' ';
		y = y->next;
	}
	cout << '\n';
}