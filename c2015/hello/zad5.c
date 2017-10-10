#include <stdio.h>

int fnajwieksza(int tab[], int ile)
{
    int max=tab[0] , i=1;
    do
    {
        if (tab[i]>max)
            max=tab[i];
        i++;
    }while(i<ile);
    return (max);
}

int fnajmniejsza(int tab[], int ile)
{
    int min=tab[0], i=1;
    do
    {
        if (tab[i]<min)
            min=tab[i];
        i++;
    }while(i<ile);
    return (min);
}

int main()
{
        int max, min, tab[]={3,43,5,56,87,2,3};
        max=fnajwieksza(tab,sizeof tab / sizeof *tab);
        min=fnajmniejsza(tab,sizeof tab / sizeof *tab);
        printf("Najmniejsza liczba to: %d\nNajwieksza liczba to: %d",min,max);
}
