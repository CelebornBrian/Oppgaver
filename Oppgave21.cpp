//Oppgave 21
//Array as parameter
#include <iostream>
using namespace std;

const int CHARNUMBER = 26;
void  initArray(int arr[], const int MAX);
void  numberShown(int arr[]);
void  writeHistogram(int arr[], const int MAX);

int main()  {
  int letterShow[CHARNUMBER];

  initArray(letterShow, CHARNUMBER);
  numberShown(letterShow);
  writeHistogram(letterShow, CHARNUMBER);

  cout << "\n\n";
  return 0;
}

void  initArray(int arr[], const int MAX)  {	//  Nullstiller arrayen "arr"
  int i;
  for (i = 0;  i < MAX;  i++)
     arr[i] = 0;
}

void  numberShown(int arr[])  {		//Teller opp antall ganger de ulike
  char tegn;							// bokstaver forekommer.

  cout << "\nSkriv tegn (bokstaver), avslutt med '!':\n\n";
  do  {
    cin >> tegn;                            //  Henter ett og ett tegn.
    if (tegn >= 'a' &&  tegn <= 'z')        //  Tegnet er: 'a'-'z':
      ++arr[tegn-'a'];                      //  Teller opp. 
    else if (tegn >= 'A' &&  tegn <= 'Z')   //  Tegnet er 'A'-'Z':
      ++arr[tegn-'A'];                      //  Teller opp.
  } while (tegn != '!');                    //  Leser inntil '!' trykkes.
}
                                            //  Skriver horisontalt histogram.                                
void  writeHistogram(int arr[], const int MAX)  {
   int i, j;

   for (i = 0;  i < MAX;  i++)  {             // G†r gjennom alle bokstavene:
      cout << "\n" << char(i + 'A') << ": ";  // Skriver bokstaven med ':'.
      for (j = 1;  j <= arr[i];  j++)         // Skriver s† mange '*' som
         cout << "*";                         //   antall forekomster.
   }
}