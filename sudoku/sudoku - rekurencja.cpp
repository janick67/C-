#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypisz_w_tabelce(int tab[]);
bool spr(int liczba, int pole, int tab[]); //liczba, wiersz, kolumna, tab
int losrek(int, int tab[]);
void losuj(int tab[]);

int main()
{
srand( time( NULL ) );
int tab[81] = {0};
//losuj(tab);
losrek(0,tab);
wypisz_w_tabelce(tab);
}

void wypisz_w_tabelce(int tab[81])
{
    cout << "-------------------------" << endl;
for (int i = 0; i < 9; i++)
{
    for (int j = 0; j < 9; j++)
      {
          if (j == 0) cout << "| ";
          if (tab[i*9+j] == 0) cout << "  ";
          else
          cout << tab[i*9+j] << " " ;
          if ((j+1) % 3 == 0) cout << "| ";
      }
      cout << endl;
      if ((i+1) % 3 == 0) cout << "-------------------------" << endl;
}
}

bool spr(int liczba, int pole, int tab[81])
{
    int kol = pole % 9;
    int wiersz = pole/9;
    //sprawdzenie wiersza
    for (int i = 0; i < 9; i++)
        if (tab[i*9+kol] == liczba)
            return false;
    //sprwadzenie kolumny
    for (int i = 0; i < 9; i++)
        if (tab[wiersz*9+i] == liczba)
            return false;
    //sprawdzenie kwadratu
    int left, top; // wspo³rzêdne lewego górnego rogu w kwadracie
    top = wiersz - wiersz % 3;
    left = kol - kol % 3;
    //cout << "top = " << top << " left = " << left << endl;
    for (int i = top; i < top+3; i++)
    {
        for (int j = left; j < left+3; j++)
        {
            if (tab[i*9+j] == liczba)
            return false;
            //cout << i << j << " ";
        }
       //cout << endl;
    }
    return true;
}


int losrek(int pole,int tab[81])
{
if (pole > 80) return 1;

cout << pole << endl;
   int los =( rand() % 9 ) + 1;
       for (int i = 1; i <= 9; i++)
       {
           los += i;
           if (los > 9) los -= 9;
           if (spr(los,pole,tab))
            {
                tab[pole] = los;
                if (losrek(pole+1,tab) == 1) return 1;
                tab[pole] = 0;
            }
   }return 0;
}
