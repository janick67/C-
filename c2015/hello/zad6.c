
int main()
{int min,i,j,tab[10]={4,76,2,3,9,5,2,3}; //poprawnie
min=tab[0]; i=0;
while(++i<8)
{
if(min>tab[i])
{
  min=tab[i];
  j=i;
}
}

    printf("liczba nr.%d czyli %d jest najmniejsze",j,min);// cout jest z c++ w c u¿ywamy printf
//cout<<min<<"<<min-i;
return 0;
}
