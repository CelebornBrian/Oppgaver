//Per-Kristian ******* ****
//Studentnummer: ******
//Klasse: ********** - *******
//Lage egene strcpy, strlen og strcat
//
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

//  INCLUDE:
#include <iostream>
using namespace std;

//  CONST:
const int LEN = 100;

//  DEKLARASJON AV FUNKSJONER:
int strLen(const char* s);
char* strCpy(char* s, const char* t);
char* strCat(char* s, const char* t);
int strCmp(const char* s, const char* t);

//  GLOBALE VARIABLE:

//  HOVEDPROGRAM:

int main() {
	char test[LEN] = "HELLO WORLD";
	char test2[LEN] = " blabla";
	//STRLEN
	char *cp = test;
	char *txtptr = test2;
	cout << strLen(cp) << endl;
	//STRCPY
	strCpy(txtptr, cp);
	for (int i = 0; i < strLen(txtptr); i++)
	{
		cout << *(txtptr + i);
	}
	cout << endl;
	//STRCAT
	strCat(cp, txtptr);
	strCat(test, test2);
	cout << test << endl;
	//STRCMP
	cout << strCmp(cp, txtptr) << endl;
	return 0;
}

//  DEFINISJON AV FUNKSJONER:

int strLen(const char * s)
{
	int length = 0;
	while (*s)
	{
		length++;
		*s++;
	}
	return length;
}

char * strCpy(char * s, const char * t)
{
	while (*t)
	{
		*s++ = *t++;
	}
	*s = '\0';
	return s;
}

char * strCat(char * s, const char * t)
{
	char* u = s;
	while (*s)
	{
		*s++;
	}
	while (*t)
	{
		*s++ = *t++;
	}
	*s = '\0';
	return u;
}

int strCmp(const char * s, const char * t)
{
	while (*s != '\0' && *t != '\0' && *s == *t)
	{
		s++; t++;
	}
	return (*s - *t);
}

