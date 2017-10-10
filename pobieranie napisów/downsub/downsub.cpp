#include <stdio.h>
#include <string>
#include <curl/curl.h>
#include <fstream>
#include <vector>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

static int writer( char * data, size_t size, size_t nmemb, std::string * bufor ) {
    int res = 0;
    if( bufor != NULL ) {
        bufor->append( data, size * nmemb );
        res = size * nmemb;
    }
    return res;
}

void get_file( const char * url, const char * file_name)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(file_name,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

std::string sendget(std::string url)
{
    std::string re;
    CURL * curl;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
curl_easy_setopt(curl, CURLOPT_HEADER, 1);
curl_easy_setopt(curl, CURLOPT_USE_SSL, 1);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
  curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, writer );
  curl_easy_setopt( curl, CURLOPT_WRITEDATA,  &re );
curl_easy_perform(curl);
curl_easy_cleanup(curl);
    return re;
}


int main()
{
std::fstream plik;
std::string re;
std::string linki[100];

plik.open("html.txt",std::ios::out|std::ios::ate);
re = sendget("https://www.podnapisi.net/subtitles/search/house-md-2004/7IE?seasons=!3&contributors=jaszor");
int i = 0;
int poczatek = re.find("<tbody> <tr");
int koniec = re.find("</tbody>");
if (poczatek != std::string::npos && koniec != std::string::npos){
    re = re.substr(poczatek,koniec-poczatek);
    poczatek = 0;
    while ( re.find("ollow href=/",poczatek+1) != std::string::npos)
    {
        poczatek = re.find("ollow href=/",poczatek+1);
        linki[i] = "https://www.podnapisi.net"+re.substr(poczatek+11,re.find(" ",poczatek+10)-poczatek-11);
        i++;
    }
    i--;
}else {
    printf("nie znaleziono napisów");
    return 0;
}
printf("%d",re.length());
char buf[ 256 ];
while (i>=0){
    sprintf( buf, "download/%d.zip", i );
    get_file(linki[i].c_str(), buf);
    printf("Pobrano plik nr %d\n",i);
//plik<<"link nr "<<i<<" "<<linki[i].c_str()<<"\n";
i--;
}
//plik<<re.c_str();

//if (re.find("sid_wrong") != std::string::npos)

}
