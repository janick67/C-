#include <stdio.h>      /* printf */
#include <math.h>       /* atan */
#include <stdlib.h>

#define PI 3.14159265

int main ()
{
    double x=10, y=10, celx= 20, cely=210, predkosc=10;
    int i=0;
    while (i<20){
double dystansx = abs(celx-x);
double dystansy = abs(cely-y);
//printf("x=%f y=%f\n", dystansx,dystansy);
double dystans = sqrt(pow(dystansx,2)+pow(dystansy,2));
x+=dystansx/(dystans/predkosc);
y+=dystansy/(dystans/predkosc);
printf("x=%f y=%f\n",x,y);
i++;
}
}
