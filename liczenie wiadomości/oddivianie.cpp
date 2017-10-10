#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdio>

using namespace std;
fstream docelowy2("docelowy2.txt",ios::out|ios::ate);

int miesiac_na_liczbe(string miesiac)
{
if (miesiac.find("sty") == 0) return 1;
if (miesiac.find("lut") == 0) return 2;
if (miesiac.find("mar") == 0) return 3;
if (miesiac.find("kwi") == 0) return 4;
if (miesiac.find("maj") == 0) return 5;
if (miesiac.find("cze") == 0) return 6;
if (miesiac.find("lip") == 0) return 7;
if (miesiac.find("sie") == 0) return 8;
if (miesiac.find("wrz") == 0) return 9;
if (miesiac.find("pa") == 0) return 10;
if (miesiac.find("lis") == 0) return 11;
if (miesiac.find("gru") == 0) return 12;
}

void rozbij_date(string tekst, string message [4])
{
    int rok, miesiac, dzien, godzina, minuta, p, k;
    string smiesiac;
    char buf[100];

    sscanf(tekst.substr(0,tekst.find(" ")).c_str(), "%d", &dzien);

    p = tekst.find(" ")+1;
    k = tekst.find(" ",p);
    smiesiac = tekst.substr(p,k-p);
    miesiac = miesiac_na_liczbe(smiesiac);

    p = k+1;
    k = tekst.find(" ",p);
    sscanf(tekst.substr(p,k-p).c_str(), "%d", &rok);

    sprintf(buf,"%d-%d-%d",rok,miesiac,dzien);
    message[2] = buf;

    p = tekst.find("o")+2;
    message[3] = tekst.substr(p,5);
}

int koniecdiva(string napis, int poczatek = 0, string pdiv = "<div", string kdiv = "</div")
{
    int posdivp, posdivk, posdiv=poczatek+1, idiv=1;
            do
                {
                    posdivp = napis.find( pdiv, posdiv+1 );
                    posdivk = napis.find( kdiv, posdiv+1 );

                    if ((posdivp < posdivk || posdivk == string::npos) && posdivp != string::npos)
                    {
                        idiv++;
                        posdiv = posdivp;
                    }
                    if ((posdivp > posdivk || posdivp == string::npos) && posdivk != string::npos)
                    {
                        idiv--;
                        posdiv = posdivk;
                    }

                }while(idiv > 0 || posdiv == string::npos);
                return posdiv;
}


int main()
{
    int poczatekthr=-1, poczatekmes=-1, ja = 0, on = 0, jaz = 0, onz = 0, max = 0;
    string napis="", thread, buff, mess, dzie, message[4];//messsage[wiadomosc, nadawca, dzien, godzina]
    fstream plik;
    plik.open( "messages.htm", ios::in );
    if( plik.good() )
    {
        while( !plik.eof() )
        {
            getline( plik, buff );
            napis += buff;
        }

int j = 0;
        while  (napis.find( "<div class=\"thread\">Gabriela Biernat,",poczatekthr + 1 ) != string::npos)
        {
            poczatekthr = napis.find( "<div class=\"thread\">Gabriela Biernat,",poczatekthr + 1 );
            int posdivthr = koniecdiva(napis, poczatekthr);
            thread = napis.substr(poczatekthr,posdivthr-poczatekthr);
int i = 0;
            while  (thread.find( "<div class=\"message\">", poczatekmes + 1) != string::npos)
            {
                poczatekmes=thread.find( "<div class=\"message\">", poczatekmes + 1);
                int posdivmes = koniecdiva(thread, poczatekmes);
                mess = thread.substr(poczatekmes,posdivmes-poczatekmes);

                int poczatekmes2 = thread.find( "<p>", posdivmes);
                int posdivmes2 = koniecdiva(thread, poczatekmes2, "<p", "</p");
                message[0] = thread.substr(poczatekmes2+3,posdivmes2-poczatekmes2-3);

                int poczatekmes3 = mess.find("user\">")+6;
                int posdivmes3 = mess.find("</",poczatekmes3);
                message[1] = mess.substr(poczatekmes3,posdivmes3-poczatekmes3);

                poczatekmes3 = mess.find("meta\">")+6;
                posdivmes3 = mess.find("</",poczatekmes3);
                rozbij_date(mess.substr(poczatekmes3,posdivmes3-poczatekmes3),message);
                //docelowy2  << message[0] << " \t" << message[1] << " \t" << message[2] << " \t" << message[3] << "\n";
                i++;

                //cout << j << " " << i << "\n";
                if (dzie != message[2])
                {
                    docelowy2 << dzie << "\t" << ja << "\t" << jaz << "\t" << on << "\t" << onz << "\n";
                    dzie = message[2];
                    ja = 0;
                    jaz =0;
                    on = 0;
                    onz = 0;
                }

                if (message[1] == "Jan Worwa")
                {ja++;
                jaz += message[0].length();
                }
                else
                {on++;
                onz += message[0].length();
                }
                                //cout << "elo";
            }
            j++;
        }
cout << ja << " " << on << "\n" << jaz << "\n" << onz << "\n";
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;

    return( 0 );
}
