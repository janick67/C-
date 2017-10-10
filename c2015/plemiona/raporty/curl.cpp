#include <curl/curl.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <fstream>
#define MOJEX 497
//497|509
#define MOJEY 509
#define MOJEFAR 20

std::fstream docelowy2("docelowy2.txt",std::ios::out|std::ios::ate);



static int writer( char * data, size_t size, size_t nmemb, std::string * bufor ) {
    int res = 0;
    if( bufor != NULL ) {
        bufor->append( data, size * nmemb );
        res = size * nmemb;
    }
    return res;
}

std::string sendget(std::string url)
{
    std::string re;
    CURL * curl;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
curl_easy_setopt(curl, CURLOPT_HEADER, 1);
curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
  curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, writer );
  curl_easy_setopt( curl, CURLOPT_WRITEDATA,  &re );
curl_easy_perform(curl);
curl_easy_cleanup(curl);
    return re;
}

int main(){
    std::string re, luck;
    char buf [100];
    int i,p,k;
    std::fstream plik( "raporty.txt", std::ios::in ); //zak³adamy, ¿e plik istnieje
std::string dane;
i=0;
    while (1){
        getline( plik, dane );
        if (dane.size() < 5) break;
        p = dane.find("]");
        k = dane.find("[",p);
        dane = dane.substr(p,k-p);
        //dane ="https://pl116.plemiona.pl/public_report/"+dane;
        dane ="file:///D:/Dropbox/C++/c2015/plemiona/raporty/docelowy2.html";
        re = sendget(dane);
        docelowy2 << re;
        p = re.find("attack_luck");
        p = re.find("b>",p)+2;
        k = re.find("<",p);
        luck = re.substr(p,k-p);
        std::cout << luck;
        break;
        std::cout << dane << "\n";
        i++;
        }


//     re = sendget(buf);
//    p = re.find("TWMap.sectorPrefech =");
//     p = re.find("data\":{",p);
//     if (p==std::string::npos) {printf("npos\n");continue;}
//     k = re.find("\"players\"",p);
//     if (k==std::string::npos) {printf("nposplayers\n");continue;}
//     re = re.substr(p,k-p);
//     p = re.find("x\":");
//     k = re.find(",",p);
//     mx = atoi(re.substr(p+3,k-p-3).c_str());
//
    // printf("%i,%i   %i,%i\n",x,y,mx,my);
//     sprintf(buf,"mapy/%i,%i.txt",mx,my);
//    plik.open(buf,std::ios::out|std::ios::ate);
//    plik<<re;
//    plik.close();
//}
std::fstream docelowy("docelowy.txt",std::ios::out|std::ios::ate);
std::fstream docelowy3("skrocony.txt",std::ios::out|std::ios::ate);


}

