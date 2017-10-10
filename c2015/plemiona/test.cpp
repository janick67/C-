#include <string>
#include <fstream>
#include <stdio.h>
#include <curl/curl.h>


int main()
{  CURL * ch = curl_init('http://qwe12.cba.pl/test/budowanie.php');
curl_exec(ch);
}
