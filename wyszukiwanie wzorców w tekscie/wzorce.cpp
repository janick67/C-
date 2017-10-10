#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;
#define MAX_ELEMENTS 200

string znajdz_wzorzec(string tekst, string wzorzec);
int rozpisz_wzorzec(string wzorzec, int wzor[][MAX_ELEMENTS]);

//int main ()
//{
//    char tekst[] = "Hou3se M. D. 02x14 Sex Kills";
//    char wzorzec[] = "[0-9]{2}[x]{1}[0-9]{2}";
//    string wynik = znajdz_wzorzec(tekst, wzorzec);
//    cout << wynik;
//}

string znajdz_wzorzec(string tekst, string wzorzec)
{
    string wynik;
    int poczatek = 0, koniec = 0, pas, i, j, x, element, ii, done;
    int wzor[100][MAX_ELEMENTS]={0};
    rozpisz_wzorzec(wzorzec,wzor);

//        for( int i = 0; i < 10; i++ ) {
//        cout << endl;
//        for( int j = 0; j < 30; j++ ) {
//            cout << " " << wzor[ i ][ j ];
//        }
//    }

    for (int i = 0; i<strlen(tekst.c_str()); i++)
    {
    x=1;
    element = wzor[x][wzor[x][0]]; //na ostatnim wyrazie jest zapisane ile razy ma sie wykonac, na miejscu zerowym w kazdym wymiarze jest zapisana liczba elementów w danym wymiarze
    ii = i;
    //cout << "glowna\n";
    //cout<< done << " " << i << "\n";
    done = 0;
    while (x<=wzor[0][0])
    {
        pas = 0;
        for (j=1;j<wzor[x][0];j++)
        {
         if ((int) tekst.c_str()[ii] == wzor[x][j]) pas=1;//sprawdza czy litera pasuje do x cześć wzoru jedna z możliwych liter (j)
        //cout <<"ii = "<< ii << " x = " << x << " element = " << element << " pas = " << pas << "\n";
        }

      if (pas==1)//jeżeli któreś zpasowało
      {
          element--;
          ii++;// przejdz do następnej litery
          //cout <<"pas ii = "<< ii << " x = " << x << " element = " << element << "\n";
      }else {
      break;
      }

      if (element<=0)
      {
        //cout <<"przed ii = "<< ii << " x = " << x << " element = " << element << "\n";
        x++;
        element = wzor[x][wzor[x][0]]; // tak jak wyżej
        //cout <<"po ii = "<< ii << " x = " << x << " element = " << element << "\n";
        if (element == 0) {
            done = 1;
           // cout << "udało się";
            wynik = tekst.substr(i,ii-i); //sprawdzanie wzoru zaczęło się od i ostatni pasujacy element byl na ii
            return wynik;
      }}}}
            return "-1";
}

int rozpisz_wzorzec(string wzorzec, int tab[][MAX_ELEMENTS])
{
    int poczatek, koniec, i=1, j, liczba;
    string miniw; //mini wzorzec
    do
    {
        poczatek = wzorzec.find("[");
        koniec = wzorzec.find("]");
        miniw = wzorzec.substr(poczatek+1,koniec-poczatek-1);
        if (poczatek+koniec+1 > wzorzec.length()) koniec = wzorzec.length()-2-poczatek;//¿eby erase nie wysz³o poza zasieg zmiennej
        j=1;
        while (miniw.find("-")!=string::npos)//zczytanie zakresów
        {
            poczatek = (int) miniw.c_str()[miniw.find("-")-1];
            koniec = (int) miniw.c_str()[miniw.find("-")+1];
            for (int x=poczatek;x<=koniec;x++)
            {
                tab [i][j]=x;
                j++;
            }
                miniw.erase(miniw.find("-")-1,3);
        }

        while (miniw.length()>0) //zczytanie pojedynczych znakow
        {
            tab [i][j]=(int) miniw.c_str()[0];
            miniw.erase(0,1);
            j++;
        }
        tab [i][0]=j;
        tab [0][0]=i;
        poczatek = wzorzec.find("{");
        koniec = wzorzec.find("}");

        sscanf(wzorzec.substr(poczatek+1,koniec-poczatek-1).c_str(), "%d", &liczba);//konwersja z stringa na inta
        tab[i][j] = liczba;
        wzorzec.erase(0,koniec+1);
        i++;
    }while(wzorzec.find("[")!=string::npos);

    return 1;
}
