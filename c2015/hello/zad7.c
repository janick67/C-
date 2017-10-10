#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int avk, i, liczba[10];// niepotrzebny przcinek
avk=time(NULL);
srand(avk);
for(i=0;i<10;i++)
{
    liczba[i]=rand();
    printf("%d wylosowana %d\n",i, liczba[i]);//brakuje cudzysłowiów
}


int swap, MAX=0;

while(swap!=0)
{
swap=0;
for(i=0;i<10;i++)//zmieniłem 5 na 10
{
if(liczba[i]>MAX)
{
    MAX=liczba[i];
    swap=1;
}}
}printf("max=%d",MAX);//cudzysłowie
}//brakuje zamknięcia klamer

