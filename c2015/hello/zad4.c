#include<stdio.h>
#define N 7 //jest to dekleracja sta³ej
int mian()
{
int i; char x;
char tab[]={"'A','D','F','J','K','M','O'"};// deklaracja tablicy jedno wymiarowej, 7 elementowej typu char i jej wype³nienie
scanf("%c",&x);
for(i=0;i<N;i++)//pêtla wykonuj¹ca 7 powtórzeñ od 0 do 6
{
if(tab[i]==x) // tkorej wartosc jest wprowadzania z klawiatury
break;//zakoñczenie ifa je¿eli liter¹ bêdzie x
}
return 0;//zwrócenie 0 przez funkcje main
}
