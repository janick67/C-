#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
int main()
{
    fstream plik;
    plik.open( "messages.htm", ios::in );
    if( plik.good() )
    {
        string napis;
        cout << "Zawartosc pliku:" << endl;
        while( !plik.eof() )
        {
            getline( plik, napis );
            cout << napis << endl;
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;

    getch();
    return( 0 );
}
