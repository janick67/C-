#include <stdio.h>
#include <conio.h>
int main()
{
 FILE *in, *out;
 char bufor[512];
 // otwarcie pliku tekstowego do odczytu: rt
 if ((in = fopen("test.txt", "rt"))== NULL)
 {
 fprintf(stderr, "\nBlad otwarcia pliku dyskowego!\n");
 return 1;
 }
 int suma = 0, i = 0;
 while (feof(in)==0) // feof - end of file (koniec pliku)
 {
 fgets(bufor, 512, in); // odczyt jednej linii tekstu
 printf("%s",bufor);
 sscanf( bufor, "%d", & i );
 suma += i;
 }
 printf("%i",suma);
 out = fopen("out.txt", "w");
 fprintf(out,"%i",suma);
 fclose(in);
 getch();
 return 0;
}
