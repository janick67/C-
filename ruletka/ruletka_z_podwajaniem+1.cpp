#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <windows.h>

int zapiszdoini(int freq[100][3], int i);
int losuj();
int liczprzegrane(int freq[100][3], int i);

int kolor; //0 - zielony, 1 - czerwony, 2 - czarny

class stawki
{
    public:
    int stawka_poczatkowa = 1, stawka_ostatnia = stawka_poczatkowa, depozyt_poczatkowy, depozyt_max = 0, depozyt_gmax = 0, depozyt, obskolor = 1, nr_serii = 0, nr_losowania = 1;
    int obstaw();//funkcja obstawia na jedne kolor stawke a po każdej przegranej zwiększa stawke dwukrotnie arg: stawka - ile ma stawiać na wygraną, depozyt - ile ma kasy w zapasie, kolor - na jaki kolor obstawia
    int doini(); //zapisuje stan depozytu do pliku
    int zeruj(); //ustawia wszystkie dane na stan poczatkowy a nr serii zwiększa o jeden
};

int stawki::doini()
{
    char temp1[100], temp2[100], temp3[100], temp4[100]; //do konwersji inta na chara
    sprintf(temp1, "%i", depozyt_poczatkowy);
    sprintf(temp2, "%i", nr_losowania);

    sprintf(temp3, "%i", depozyt_gmax);
    WritePrivateProfileString(temp1, "Maksymalny depozyt", temp3, ".//stawki2//globalny.ini");
    sprintf(temp3, "%i",depozyt_gmax*100/depozyt_poczatkowy);
    WritePrivateProfileString(temp1, "zysk w %", temp3, ".//stawki2//globalny.ini");

    sprintf(temp4, ".//stawki2//%i-%i.ini", depozyt_poczatkowy, stawka_poczatkowa);
    sprintf(temp3, "%i", depozyt_gmax);
    WritePrivateProfileString("Globalnie", "Maksymalny depozyt", temp3, temp4);
    sprintf(temp3, "%i",depozyt_gmax*100/depozyt_poczatkowy);
    WritePrivateProfileString("Globalnie", "zysk w %", temp3, temp4);
    sprintf(temp3, "%i", depozyt_max);

    sprintf(temp1, "%i", nr_serii);
    WritePrivateProfileString(temp1, "Maksymalny depozyt", temp3, temp4);
    sprintf(temp3, "%.0f", round(depozyt_max*100/depozyt_poczatkowy));
    WritePrivateProfileString(temp1, "zysk w %", temp3, temp4);

    sprintf(temp3, "%i", depozyt);
    WritePrivateProfileString(temp1, temp2, temp3, temp4);
}

int stawki::obstaw()
{
    if (obskolor == kolor)
    {
        depozyt += stawka_ostatnia;
        stawka_ostatnia = stawka_poczatkowa;
    }else{
        depozyt -= stawka_ostatnia;
        stawka_ostatnia = stawka_ostatnia*2+stawka_poczatkowa;
    }

    if (depozyt > depozyt_max) depozyt_max = depozyt;
    if (depozyt_max > depozyt_gmax) depozyt_gmax = depozyt_max;

    nr_losowania += 1;
    doini();

    if (depozyt < 0 || stawka_ostatnia > depozyt)
        return 0;

    return 1;
}

  int  stawki::zeruj()
    {
        stawka_ostatnia = stawka_poczatkowa;
        depozyt = depozyt_poczatkowy;
        nr_losowania = 1;
        nr_serii += 1;
        depozyt_max = 0;
    }

int main()
{
    remove("ruletka.ini");
    srand( time( NULL ) );
    int freq[100][3]= {0}; //[99] 0 - ogólna liczba wystapien 1-99 ilosc kolejek od ostatniego, [*][0] - kolejnoœæ tak jak wy¿ej
    int i=0, depozyt = 1;
        stawki ruletka[20];
        for (i=0;i<20;i++)
        {
        ruletka[i].depozyt_poczatkowy = depozyt;
        depozyt = depozyt + pow(2,i+1);
        ruletka[i].zeruj();
        }
    while (1)
    {
        kolor = losuj();
        i++;
        for (i=0;i<20;i++)
            if (ruletka[i].obstaw() == 0) ruletka[i].zeruj();

        liczprzegrane(freq, i);
    } getch ();
    }

    int liczprzegrane(int freq[100][3], int i)
    {
    int last_green = 0;
    int last_red = 0;
    int last_black = 0;
    freq[99][kolor]++;//ogólna liczba wystapien
    last_green++;
    last_red++;
    last_black++;
    switch (kolor)
    {
case 0:
    if (last_green-1<98)
    freq[last_green-1][0]++;
    if (freq[98][0]<last_green) freq[98][0] = last_green;
    last_green = 0;
    break;
case 1:
    if (last_red-1<98)
    freq[last_red-1][1]++;
    if (freq[98][1]<last_red) freq[98][1] = last_red;
    last_red = 0;
    break;
case 2:
    if (last_black-1<98)
    freq[last_black-1][2]++;
    if (freq[98][2]<last_black) freq[98][2] = last_black;
    last_black = 0;
    break;
default:
    break;
    }
    zapiszdoini(freq, i);
    }

    int losuj()
    {
        int  random =( std::rand() % 37 );
    if (random == 0)
        kolor = 0;
    else if(random < 19)
        kolor = 1;
    else
        kolor = 2;
        return kolor;
    }

    int zapiszdoini(int freq[100][3],int i)
{
    int j;
    char temp1[100], temp2[100]; //do konwersji inta na chara
    sprintf(temp2, "%i", i);
    WritePrivateProfileString("Ogólne", "Liczba losowañ", temp2, ".//ruletka.ini");//ogólne losowania
    sprintf(temp2, "%i", freq[99][0]);
    WritePrivateProfileString("Ogólne", "Liczba zielonych", temp2, ".//ruletka.ini");//ogólnie zielone
    sprintf(temp2, "%i", freq[99][1]);
    WritePrivateProfileString("Ogólne", "Liczba czerwonych", temp2, ".//ruletka.ini");//ogólnie czerwone
    sprintf(temp2, "%i", freq[99][2]);
    WritePrivateProfileString("Ogólne", "Liczba czarnych", temp2, ".//ruletka.ini");//ogólnie czarne
    sprintf(temp2, "%i", freq[98][0]);
    WritePrivateProfileString("Ogólne", "Najwieksza przegrana zielonych", temp2, ".//ruletka.ini");//ogólnie zielone
    sprintf(temp2, "%i", freq[98][1]);
    WritePrivateProfileString("Ogólne", "Najwieksza przegrana czerwonych", temp2, ".//ruletka.ini");//ogólnie czerwone
    sprintf(temp2, "%i", freq[98][2]);
    WritePrivateProfileString("Ogólne", "Najwieksza przegrana czarnych", temp2, ".//ruletka.ini");//ogólnie czarne
    for (j=0; j<98;j++)
    {
    sprintf(temp1, "%i", j);
    sprintf(temp2, "%i", freq[j][0]);
    WritePrivateProfileString("Najwiêksze ci¹gi przegranych zielone", temp1, temp2, ".//ruletka.ini");
    sprintf(temp2, "%i", freq[j][1]);
    WritePrivateProfileString("Najwiêksze ci¹gi przegranych czerwone", temp1, temp2, ".//ruletka.ini");
    sprintf(temp2, "%i", freq[j][2]);
    WritePrivateProfileString("Najwiêksze ci¹gi przegranych czarne", temp1, temp2, ".//ruletka.ini");
    }
}
