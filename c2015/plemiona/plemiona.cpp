#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#define MOJEX 337
#define MOJEY 691

std::fstream docelowy2("docelowy2.txt",std::ios::out|std::ios::ate);
class mapa
{
    public:
    int x, y, size, owner;
    double far(int mx, int my);
};

double mapa::far(int mx=MOJEX,int my=MOJEY)
{
    double far=sqrt(pow(abs(x-mx),2)+pow(abs(y-my),2));
    return far;
}

int dotab(std::string text, int x, int y, int gx, int gy, mapa * temp)
{
    int p,k,i;
    std::string size,owner;
    for (i=0; i<3;i++)
        p=text.find(",",p+1);

    p=text.find(",",p+1);
    k=text.find(",",p+1);
    size=text.substr(p+2,k-p-3);
    p=text.find(",",k);
    k=text.find(",",p+1);
    owner=text.substr(p+2,k-p-3);
    temp->x=x+gx;
    temp->y=y+gy;
    temp->size=atoi(size.c_str());
    temp->owner=atoi(owner.c_str());
return (1);
}

int pod(std::string text, int i,int gx,int gy, std::vector<mapa> * wioski)
{
    mapa temp;
    int p,j=1,pp, k, y;
    std::string x;
    while(1)
    {
    p=text.find("[");
    if (p==std::string::npos) return 1;
    y=atoi(text.substr(text.rfind("\"",text.rfind("\"",p)-1)+1,text.rfind("\"",text.rfind("\"",text.rfind("\"",p)-1))-text.rfind("\"",text.rfind("\"",p)-1)-1).c_str());
    k=text.find("]",p);
    pp=p;
    if( text.find("[",pp+1)<k)
    {
        pp=text.find("[",pp+1);
       k=text.find("]",k+1);
    }
    if (k==std::string::npos)
    {
            x=text.substr(p);
            docelowy2<<x.c_str()<<"\n\n";
           dotab(x,i,y,gx,gy,&temp);
           if (temp.x>=gx&&temp.y<1000&&temp.size>0)
            wioski->push_back(temp);
            return 1;
    }else    x=text.substr(p,k-p+1);
     docelowy2<<x.c_str()<<"\n\n";
        dotab(x,i,y,gx,gy,&temp);
       if (temp.x>=gx&&temp.y<1000&&temp.size>0)
        wioski->push_back(temp);
    text=text.substr(k+1);
    j++;
    }
    return 1;
}

int main(){
    std::string text, x;
    int p,i,gx,gy;
    std::vector <mapa> wioski;
std::fstream plik( "source07-06.txt", std::ios::in | std::ios::out );

std::fstream docelowy("docelowy.txt",std::ios::out|std::ios::ate);

while (text.find("TWMap.sectorPrefech")==std::string::npos)
{
    getline( plik, text );
}
    p=text.find("\"x\":")+4;
    gx=atoi(text.substr(p,text.find(",",p)-p).c_str());
    p=text.find("\"y\":")+4;
    gy=atoi(text.substr(p,text.find(",",p)-p).c_str());
i=-2;
while (1)
{
    p=text.find("{");
    if (p==std::string::npos) break;
    x=text.substr(p,text.find("}",p)-p);
    //docelowy<<x.c_str()<<"\n\n";
    pod(x,i,gx,gy,&wioski);
    text=text.substr(p+1);
    i++;

}
int j=0;
for (i=0;i<wioski.size();i++)
{
    if (wioski[i].owner==0)//&&wioski[i].far()<5
    {
    j++;
    //docelowy<<wioski[i].x<<","<<wioski[i].y<<"\n";
    docelowy <<"["<<j<<"]\nx = "<<wioski[i].x<<"\ny = "<<wioski[i].y<<"\nsize = "<<wioski[i].size<<"\nowner = "<<wioski[i].owner<<"\nfar = "<<wioski[i].far()<<"\n\n";
}}
//std::cout<<"["<<i<<"]\nx = "<<wioski[i].x<<"\ny = "<<wioski[i].y<<"\nsize = "<<wioski[i].size<<"\nowner = "<<wioski[i].owner<<"\n\n";
printf("%i",j);
//printf("%i = %s",wioski[0].x,x.c_str());

}

