#include <stdio.h>
#include <string>
#include <curl/curl.h>
#include <fstream>
#include <vector>

std::string bufor;

class surka
{
public:
    float now, prod;
    int max;
};

class farma
{
  public:
        std::string id;
        int wood,stone,iron,time;
};

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
    char post[100]="user=janick67&password=janick67a&cookie=false&clear=true", url[100]="www.plemiona.pl/index.php?action=login&server_pl92";
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

int tosec(std::string czas)
{
    int sec, hour, min;
    hour=atoi(czas.c_str());
    czas=czas.substr(czas.find(":")+1);
    min=atoi(czas.c_str());
    czas=czas.substr(czas.find(":")+1);
    sec=(60*hour+min)*60+atoi(czas.c_str());
    return sec;
}

farma getatak(std::string id)
{
   std::fstream plik("1234.txt",std::ios::out|std::ios::ate);
    std::string re;
    int p, k;
    farma farm;
    farm.id=id;
    re.append("pl92.plemiona.pl/game.php?village=70327&id=");
    re.append(id.c_str());
    re.append("&type=own&screen=info_command");
    re=sendget(re.c_str());

    p=re.find("command_comment");
    plik<<re.substr(p).c_str();
    p=re.find("timer",p);
    k=re.find("<",p);
    farm.time=tosec(re.substr(p+7,k-p-7));
    p=re.find("wood",p);
    p=re.find("</span>",p);
    k=re.find("<",p+1);
    farm.wood=atoi(re.substr(p+7,k-p-7).c_str());//drewno
    p=re.find("</span>",k+2);
    k=re.find("<",p+1);
    farm.stone=atoi(re.substr(p+7,k-p-7).c_str());//glina
    p=re.find("</span>",k+2);
    k=re.find("<",p+1);
    farm.iron=atoi(re.substr(p+7,k-p-7).c_str());//¿elazo

    return farm;
}

std::vector<std::string> szukajid(std::string source) //zwraca wektor z lista id raportów
{
    std::vector <std::string> id;
    std::string re;
    int k,p = source.find("command-list");
    do
    {
       p = source.find("data-id=",p+1);
       k = source.find("\"",p+9);

       if (p==std::string::npos) break;
       re = source.substr(p+9,k-p-9);
       //printf("%i\n",(source.find(" z ",p)));
       if (source.find(" z ",p)<source.find("</td>",p)&&source.find(" z ",p)!=std::string::npos)
       id.push_back(re);
    }while(1);
    return id;
}

std::vector <surka> getsur(std::string re)
{
    int p,k;
    std::vector <surka> surki;
    surka temp;
    //drewno
    p = re.find("wood_float");
    k = re.find(",",p);
    temp.now = atof(re.substr(p+12,k-p-12).c_str());//now
    p = re.find("wood_prod");
    k = re.find(",",p);
    temp.prod = atof(re.substr(p+11,k-p-11).c_str());//prod
    p = re.find("storage_max");
    k = re.find(",",p);
    temp.max = atoi(re.substr(p+13,k-p-13).c_str());//max
    surki.push_back(temp);
    //glina
    p = re.find("stone_float");
    k = re.find(",",p);
    temp.now = atof(re.substr(p+13,k-p-13).c_str());//now
    p = re.find("stone_prod");
    k = re.find(",",p);
    temp.prod = atof(re.substr(p+12,k-p-12).c_str());//prod
    surki.push_back(temp);
    //żelazo
    p = re.find("iron_float");
    k = re.find(",",p);
    temp.now = atof(re.substr(p+12,k-p-12).c_str());//now
    p = re.find("iron_prod");
    k = re.find(",",p);
    temp.prod = atof(re.substr(p+11,k-p-11).c_str());//prod
    surki.push_back(temp);
    return  surki;//[0] drewno, [1] glina, [2] żelazo
}

float potrzeba(float wood, float stone, float iron,std::vector <surka> raw)
{
    float ilew=0, iles=0, ilei=0;
   if (wood>raw[0].max&&stone>raw[0].max&&iron>raw[0].max) return -1;
   if (wood>raw[0].now)
   {
      ilew=(wood-raw[0].now)/raw[0].prod;
   }
      if (stone>raw[1].now)
   {
      iles=(wood-raw[1].now)/raw[1].prod;
   }
      if (wood>raw[2].now)
   {
      ilei=(wood-raw[2].now)/raw[2].prod;
   }

   if (ilew>iles&&ilew>ilei) return ilew;
   if (iles>ilew&&iles>ilei) return iles;
   if (ilei>ilew&&ilei>iles) return ilei;

   return 0;
}

float potrzeba(float wood, float stone, float iron,std::vector <surka> raw, std::vector <farma> farm)
{
    float ilew=0, iles=0, ilei=0, tw=0, ts=0, ti=0, i;
   if (wood>raw[0].max&&stone>raw[0].max&&iron>raw[0].max) return -1;
   if (wood>raw[0].now)
   {
      ilew=(wood-raw[0].now)/raw[0].prod;
   }
      if (stone>raw[1].now)
   {
      iles=(wood-raw[1].now)/raw[1].prod;
   }
      if (wood>raw[2].now)
   {
      ilei=(wood-raw[2].now)/raw[2].prod;
   }
 i=0;
   while (ilew>farm[i].time)
   {
       raw[0].now+=farm[i].wood+raw[0].prod*farm[i].time;//przesuwam w czasie więc musze też dodać surowce
        tw+=farm[i].time; // przesuwam w czasie do najbliższego ataku
        if (wood>raw[0].now)
        {
            printf("%i\n",i);
      ilew=(wood-raw[0].now)/raw[0].prod+tw;
   }else{ ilew=tw;}

   i++;
   }

   if (ilew>iles&&ilew>ilei) return ilew;
   if (iles>ilew&&iles>ilei) return iles;
   if (ilei>ilew&&ilei>iles) return ilei;

   return 0;
}

int main()
{
std::fstream plik;
std::vector<std::string> id;
std::vector<farma> farm;
std::vector <surka> raw;
std::string re;
int i;
plik.open("source.txt",std::ios::out|std::ios::ate);
re = sendget("pl92.plemiona.pl/game.php?village=70327&screen=place");
plik<<re.c_str();
if (re.find("sid_wrong") != std::string::npos) {//jeżeli nie jestem zalogowany to loguje
logowanie();
re = sendget("pl92.plemiona.pl/game.php?village=70327&screen=place"); //pobieranie strony
}
//plik<< bufor.c_str();
id=szukajid(re.c_str());
for (i=0;i<id.size();i++)
farm.push_back(getatak(id[i]));
raw=getsur(re);
printf("%f",potrzeba(4577,4975,1000,raw,farm)/60);
//plik<<"\ndrewno\nnow = "<<raw[0].now<<"\nprod = "<<raw[0].prod<<"\nmax = "<<raw[0].max<< "\n\n"<<"\nglina\nnow = "<<raw[1].now<<"\nprod = "<<raw[1].prod<<"\nmax = "<<raw[1].max<< "\n\n"<<"\nżelazo\nnow = "<<raw[1].now<<"\nprod = "<<raw[1].prod<<"\nmax = "<<raw[1].max<< "\n\n";
/*plik<<bufor.c_str();
id=szukajid(bufor.c_str());
for (i=0;i<id.size();i++)
farm.push_back(getatak(id[i]));
//printf("%i",id.size());
int swood=0,sstone=0,siron=0;
for (i=0;i<farm.size();i++)
{
    swood+=farm[i].wood;
    sstone+=farm[i].stone;
    siron+=farm[i].iron;
    plik<<i<<"\nid = "<<farm[i].id<<"\nwood = "<<farm[i].wood<<"\nstone = "<<farm[i].stone<< "\niron = "<<farm[i].iron<<"\ntime = "<<farm[i].time<<"\n\n";
}plik<<"\n"<<swood<<"\n"<<sstone<<"\n"<<siron;*/

return 1;
}
