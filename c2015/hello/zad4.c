#include<stdio.h>
#define N 7 //jest to dekleracja sta�ej
int mian()
{
int i; char x;
char tab[]={"'A','D','F','J','K','M','O'"};// deklaracja tablicy jedno wymiarowej, 7 elementowej typu char i jej wype�nienie
scanf("%c",&x);
for(i=0;i<N;i++)//p�tla wykonuj�ca 7 powt�rze� od 0 do 6
{
if(tab[i]==x) // tkorej wartosc jest wprowadzania z klawiatury
break;//zako�czenie ifa je�eli liter� b�dzie x
}
return 0;//zwr�cenie 0 przez funkcje main
}
