#include <stdio.h>

main (void)
{
    int stopnie, wynik;
printf("Zamiana stopni Celcjusza na stopnie Fahrenheita\nWpisz ilosc stopni Celcjusza ktora chcesz zamienic: ");
scanf("%d",&stopnie);
wynik = (stopnie*1.8)+32;
printf("%d Celcjusza to %d Fahrenheita",stopnie,wynik);
getch();
}

