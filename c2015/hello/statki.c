#include <stdio.h>

void show(int pla[2][11][11], int players)
{
    int i, j;
    for (i=0; i<11; i++)
    {
        printf("#############################################\n");
        for (j=0; j<11; j++) printf("#%2d ",pla[players][j][i]);
        printf("#\n");
    }
printf("#############################################\n");
}

void generuj_plansze(int pla[2][11][11])
{

}


int main()
{
int pla[2][11][11]={{{9,1,2,3,4,5,6,7,8,9,10},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10}},{{9,1,2,3,4,5,6,7,8,9,10},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10}}};
generuj_plansze(&pla);
show(pla,0);
getch();
}
