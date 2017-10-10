#include <curl/curl.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#define FAR 100
#define MOJEX 341
#define MOJEY 387

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
curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "dane/cookies.txt");
curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "dane/cookies.txt");
  curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, writer );
  curl_easy_setopt( curl, CURLOPT_WRITEDATA,  &re );
curl_easy_perform(curl);
curl_easy_cleanup(curl);
    return re;
}

std::string logowanie()
{
    std::string bufor;
    char post[100]="user=janick67&password=andigal67a&cookie=false&clear=true", url[100]="www.plemiona.pl/index.php?action=login&server_pl116";
CURL *curl = curl_easy_init();
if(curl) {
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_HEADER, 1);
  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
  curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, writer );
  curl_easy_setopt( curl, CURLOPT_WRITEDATA,  &bufor );
  curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  int p = bufor.find("Location: ")+10;
bufor = bufor.substr(p,bufor.find("\n",p)-p-1);
bufor = sendget(bufor);
}else bufor="error";
return bufor;}

int main()
{
    std::cout << "logowanie();
    std::string re;
    std::fstream plik;
    char buf [100];
    int i,mx,my,p,k,j=0,x=MOJEX-FAR,y=MOJEY-FAR;
    while (1){
        x+=20;
        if (x>MOJEX+FAR){
            x=MOJEX-FAR;
            y+=20;
        }
        if (y>MOJEY+FAR) break;
    sprintf(buf,"http://pl116.plemiona.pl/game.php?x=%i&y=%i&screen=map",x,y);
     re = sendget(buf);
     p = re.find("TWMap.sectorPrefech =");
     k = re.find("},{\"x",p);
     re = re.substr(p,k-p);
     p = re.find("x\":");
     k = re.find(",",p);
     mx = atoi(re.substr(p+3,k-p-3).c_str());
     p = re.find("y\":");
     k = re.find(",",p);
     my = atoi(re.substr(p+3,k-p-3).c_str());
     printf("%i,%i   %i,%i\n",x,y,mx,my);
    sprintf(buf,"mapy/%i,%i.txt",mx,my);
    plik.open(buf,std::ios::out|std::ios::ate);
    plik<<re;
    plik.close();
    }
    return 1;
}
