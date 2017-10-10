#include <stdio.h>

float fpole(int promien);
float fobwod (int promien);

int main()
{
    int promien;
    printf("Podaj promien kola ");
    scanf("%d",&promien);
printf("Promien=%d\nPole=%.1f\nObwod=%.1f",promien,fpole(promien),fobwod(promien));
}

float fpole(int promien)
{
    float wynik = (3.14*promien*promien);
    return(wynik);
}

float fobwod(int promien)
{
    float wynik = (3.14*2*promien);
    return (wynik);
}
