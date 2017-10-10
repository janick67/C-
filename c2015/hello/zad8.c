#include <stdio.h>

#define maxucz 4
#define iloscklas 3

void fuzupelnijall(float srednia[iloscklas][maxucz])
{
    int i, j;
    for (j=0; j<iloscklas; j++)
    for (i=0; i<maxucz; i++)
    {
        printf("Wpisz srednia ucznia nr %d z klasy %d ",i+1,j+1);
        scanf("%f",&srednia[j][i]);
    }
}

void fuzupelnijk(float srednia[iloscklas][maxucz], int klasa)
{
    int i;
    for (i=0; i<maxucz; i++)
    {
        printf("Wpisz srednia ucznia nr %d z klasy %d ",i+1,klasa);
        scanf("%f",&srednia[klasa-1][i]);
    }
}

void fuzupelniju(float srednia[iloscklas][maxucz], int klasa, int uczen)
{
    printf("Wpisz srednia ucznia nr %d z klasy %d ",uczen,klasa);
    scanf("%f",&srednia[klasa-1][uczen-1]);
}

void fshowk(float srednia[iloscklas][maxucz], int klasa)
{
    int i;
    printf("\n|Klasa %d|\nNr ucznia\tsrednia\n",klasa);
    for (i=0; i<maxucz; i++)
    printf("   %2.0d\t\t%6.1f\n",i+1,srednia[klasa-1][i]);
}

void fshowall(float srednia[iloscklas][maxucz])
{
    int i;
    for (i=0; i<iloscklas; i++)
    fshowk(srednia,i+1);
}



void fshowu(float srednia[iloscklas][maxucz], int klasa, int i)
{
printf("\n|Klasa %d|\nNr ucznia\tsrednia\n",klasa);
printf("   %2.0d\t\t%6.1f\n",i,srednia[klasa-1][i-1]);
}


int main()
{
    int menu, klasa, uczen;
    float srednia [iloscklas][maxucz] = {};
    do
    {
    printf("aby uzupelnic srednia wszystkich uczniow wpisz 1\n");
    printf("aby uzupelnic srednia wybranej klasy wpisz 2\n");
    printf("aby uzupelnic sredinia wybranego ucznia wpisz 3\n");
    printf("aby pokazac sredia wszystkich uczniow wpisz 4\n");
    printf("aby pokazac srednia wszytkich uczniow wybranej klasy wpisz 5\n");
    printf("aby pokazac srednia wybranego ucznia z wybranej klasy wpisz 6\n");
    printf("aby zakonczyc program wpisz dowolny znak nie bedacy liczba z zakresu 1-6\n");
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
    fuzupelnijall(srednia);
    break;
    case 2:
        {
            printf("Nr klasy ktorej srednia chcesz zmienic ");
            scanf("%d",&klasa);
            fuzupelnijk(srednia, klasa);

        }break;
    case 3:
    {
            printf("Nr klasy w ktorej jest uczen ktorego srednia chcesz zmienic ");
            scanf("%d",&klasa);
            printf("Nr tego ucznia ");
            scanf("%d",&uczen);
            fuzupelniju(srednia, klasa, uczen);
            }
    break;
    case 4:
    fshowall(srednia);
    break;
    case 5:
        {
            printf("Nr klasy ktorej srednia chcesz zobaczyc ");
            scanf("%d",&klasa);
            fshowk(srednia, klasa);
        }
    break;
    case 6:
        {
            printf("Nr klasy w ktorej jest uczen ktorego srednia chcesz zobaczyc ");
            scanf("%d",&klasa);
            printf("Nr tego ucznia ");
            scanf("%d",&uczen);
            fshowu(srednia, klasa, uczen);
        }
    break;
    default: return(0);
    }
    }while (menu > 0 || menu < 7);
}

