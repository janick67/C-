#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypisz_w_tabelce(int tab[9][9]);
bool spr(int liczba, int wiersz, int kolumna, int tab[9][9]); //liczba, wiersz, kolumna, tab
void losuj(int tab[9][9]);
void losuj(int tab[9][9]);

int main()
{
srand( time( NULL ) );
int tab[9][9] = {0};
//losuj(tab);
losrek(tab);
wypisz_w_tabelce(tab);
}

void wypisz_w_tabelce(int tab[9][9])
{
    cout << "-------------------------" << endl;
for (int i = 1; i <= 9; i++)
{
    for (int j = 1; j <= 9; j++)
      {
          if (j == 1) cout << "| ";
          if (tab[i-1][j-1] == 0) cout << "  ";
          else
          cout << tab[i-1][j-1] << " " ;
          if (j % 3 == 0) cout << "| ";
      }
      cout << endl;
      if (i % 3 == 0) cout << "-------------------------" << endl;
}
}

bool spr(int liczba, int wiersz, int kol, int tab[9][9])
{
    //sprawdzenie wiersza
    for (int i = 0; i < 9; i++)
        if (tab[i][kol] == liczba)
            return false;
    //sprwadzenie kolumny
    for (int i = 0; i < 9; i++)
        if (tab[wiersz][i] == liczba)
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
            if (tab[i][j] == liczba)
            return false;
            //cout << i << j << " ";
        }
       //cout << endl;
    }
    return true;
}

void losuj(int tab[9][9])
{
    int wylosowana_liczba;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int k = 0;
            do
            {
                wylosowana_liczba =( std::rand() % 9 ) + 1;
                if (k > 20) return ;
                k++;
                cout << k << endl;
            } while (!spr(wylosowana_liczba,i,j,tab));
            tab[i][j] = wylosowana_liczba;
        }
    }
}

void losrek(int pole,int tab[9][9])
{
   int wylosowana_liczba =( std::rand() % 9 ) + 1;

}
