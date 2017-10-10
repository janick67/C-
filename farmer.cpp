#include <iostream>
#include <cstdlib>
double kr=0;
double o=0;
double s=0;
double k=0;
double n=0;
double mp=0;
double dp=0;
double ko=0;

void wilk(){
if (dp==0){
kr=0;
o=0;
s=0;
k=0;	
}else{
dp=0;
}; 	
};

void lis(){
if (mp==0) kr=0;
if (mp==1) mp=0;	
};

void losuj()
{
ko = (rand() % 21 ) + 0;
std::cout<<ko;
switch (ko)
{
case "1":
kr=kr*2;
if (kr==0) kr=2;
break;

case "2":
lis();
break;

case "3":
wilk();
break;

case "4":
o=o*1.5;
kr=kr*1.5;
break;

case "5":
o=o*2;
if (o==0) o=2;
break;

case "6":
o=o*1.5;
lis();
break;

case "7":
wilk();
break;

case "8":
s=s*1.5;
kr=kr*1.5;
break;

case "9":
s=s*1.5;
o=o*1.5;
break;

case "10":
s=s*2;
if (s==0) s=2;
break;

case "11":
s=s*1.5;
lis();
break;

case "12":
wilk();
break;

case "13":
k=k*1.5;
kr=kr*1.5;
break;

case "14":
k=k*1.5;
o=o*1.5;
break;

case "15":
k=k*1.5;
s=s*1.5;
break;

case "16":
k=k*1.5;
lis();
break;

case "17":
n=n*1.5;
kr=kr*1.5;
break;

case "18":
n=n*1.5;
o=o*1.5;
break;

case "19":
n=n*1.5;
s=s*1.5;
break;

case "20":
n=n*1.5;
k=k*1.5;
break;

case "21":
n=n*1.5;
wilk();
break;

};
};

void zmien(){
if (kr > o*4){
o+=kr/4;
kr-=kr/4;
};

if (o>s*4){
s+=o/4;
o-=o/4;
};

if (s>k*4){
k+=s/4;
s-=s/4;
};

if (k>n*40){
n+=k/4;
k-=k/4;
};

if (o>10){
o--;
mp=1;
};

if (k>10){
k--;
dp=1;
};		
};


int main()
{
std::cout<<"\nkr="<<kr<<"\no="<<o<<"\ns="<<s<<"\nk="<<k<<"\nn="<<n;
srand( time( 0 ) );
  losuj();
  zmien();
  std::cin>>ko;
}
