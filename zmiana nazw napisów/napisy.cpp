#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include "../wyszukiwanie wzorców w tekscie/wzorce.cpp"

using namespace std;

class pliki
{
    public:
    string filmy[MAX_ELEMENTS][2], napisy[MAX_ELEMENTS][2];
    int ilosc_napisow = 0, ilosc_filmow = 0;

    int rozdziel(string tab[])
    {
        int i = 0;
        while (tab[i] != "")
        {
            if (tab[i].find(".srt") != string::npos || tab[i].find(".txt") != string::npos)
        {
            napisy[ilosc_napisow][0] = tab[i];
            ilosc_napisow++;
        }else{
            filmy[ilosc_filmow][0] = tab[i];
            ilosc_filmow++;
        }
            i++;
        }
        return 1;
    }


    int spr_nr (char wzorzec[] = "[0-9]{2}[x]{1}[0-9]{2}", char wzorzec2[] = "[0-9]{2}[x]{1}[0-9]{2}")
    {
    int i = 0;
    while (i < ilosc_filmow)
    {
        const char* tekst = filmy[i][0].c_str();
        filmy[i][1] = znajdz_wzorzec(tekst, wzorzec);
        i++;
    }

    i = 0;
    while (i < ilosc_napisow)
    {
        const char* tekst = napisy[i][0].c_str();
        napisy[i][1] = znajdz_wzorzec(tekst, wzorzec2);
        napisy[i][1].insert( 0, "0" );
        napisy[i][1].insert( 2, "x" );
       // napisy[i][1].replace(napisy[i][1].find("E"),1,"x");
        i++;
    }
    }
};


void listujPliki(const char *nazwa_sciezki, string tab[]) {
    struct dirent * plik;
    DIR * sciezka;

    if(( sciezka = opendir( nazwa_sciezki ) ) ) {
        int i = 0;
    while(( plik = readdir( sciezka ) ) ){
        if (strlen(plik->d_name) > 3 ){
             tab[i] = plik->d_name;
             i++;}}
             closedir( sciezka );
    }
    else
         printf( "! wywo³uj¹c funkcjê opendir(%s) pojawi³ siê b³¹d otwarcia strumienia dla danej œcie¿ki, mo¿e nie istnieje, lub podano œcie¿kê pust¹\n", nazwa_sciezki );
}

main() {
    pliki filmy;
    string tab [MAX_ELEMENTS];
    int i = 0, j = 0;
    const char *src = "D:\\download\\House M.D Sezony 1 - 7 HDTV LektorPL\\Sezon 3\\";
    listujPliki(src, tab);
    filmy.rozdziel(tab);
    filmy.spr_nr("[0-9]{2}[x]{1}[0-9]{2}","[3]{1}[0-9]{2}");
//   cout << "napisy " << filmy.ilosc_napisow << " filmy " << filmy.ilosc_filmow << "\n";
//    i = 0;
//    while (i < filmy.ilosc_filmow)
//    {
//        cout <<"f " << filmy.filmy[i][1] << " " << filmy.filmy[i][0] << "\n";
//        cout <<"n " << filmy.napisy[i][1] << " " << filmy.napisy[i][0] << "\n";
//        i++;
//    }
//cout << filmy.ilosc_napisow;

    while (i < filmy.ilosc_napisow)
    {
        string nowa, stara;
        while (j < filmy.ilosc_filmow)
        {
            if (filmy.napisy[i][1] == filmy.filmy[j][1])
                {
                    nowa =  (string) src + filmy.filmy[j][0].substr(0,filmy.filmy[j][0].length()-3) + (string) "srt";
                    cout << "src = " << nowa << "\n";
                    break;
                }
            j++;
        }
        stara = (string) src + filmy.napisy[i][0];
        rename(stara.c_str(),nowa.c_str());
        i++;
    }

}
