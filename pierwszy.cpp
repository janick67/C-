
#include <iostream>
#include <string>

#define FOR(n) for(int i=0; i<n; i++)
using namespace std;
char plansza[9];
bool check=true;

void WyswietlTytul()
{
cout<<"GRA ";
delay(800);
cout<<"W ";
delay(700);
cout<<_pl("KÓ£KO ");
delay(800);
cout<<"I ";
delay(600);
cout<<_pl("KRZY¯YK ");
delay(800);
cout<<"DLA ";
delay(600);
cout<<"2 ";
delay(500);
cout<<_pl("OSÓB\n\n");
delay(1500);
}

bool LosujGracza()
{
bool random;
srand(static_cast<int>(time(NULL)));
return random=rand() % 2;
}

int RysujPlansze()
{
int trzy=0;

cout<<"  -------\n  |";
FOR(9) {
cout<<plansza[i];
 trzy++;
 if(trzy==3) {
 cout<<"|\n  ";
 trzy=0; }
 if(i!=8)
 cout<<"|";
 }
 cout<<"-------\n";
 delay(1500);
}

bool sprawdz()
{
if((plansza[0]=='O' && plansza[1]=='O' && plansza[2]=='O') ||
   (plansza[3]=='O' && plansza[4]=='O' && plansza[5]=='O') ||
   (plansza[6]=='O' && plansza[7]=='O' && plansza[8]=='O') ||
   (plansza[0]=='O' && plansza[3]=='O' && plansza[6]=='O') ||
   (plansza[1]=='O' && plansza[4]=='O' && plansza[7]=='O') ||
   (plansza[2]=='O' && plansza[5]=='O' && plansza[8]=='O') ||
   (plansza[0]=='O' && plansza[4]=='O' && plansza[8]=='O') ||
   (plansza[2]=='O' && plansza[4]=='O' && plansza[6]=='O'))
 { cout<<_pl("\nKó³ka wygra³y!\n");
   RysujPlansze();
   return false; }

if((plansza[0]=='X' && plansza[1]=='X' && plansza[2]=='X') ||
   (plansza[3]=='X' && plansza[4]=='X' && plansza[5]=='X') ||
   (plansza[6]=='X' && plansza[7]=='X' && plansza[8]=='X') ||
   (plansza[0]=='X' && plansza[3]=='X' && plansza[6]=='X') ||
   (plansza[1]=='X' && plansza[4]=='X' && plansza[7]=='X') ||
   (plansza[2]=='X' && plansza[5]=='X' && plansza[8]=='X') ||
   (plansza[0]=='X' && plansza[4]=='X' && plansza[8]=='X') ||
   (plansza[2]=='X' && plansza[4]=='X' && plansza[6]=='X'))
 { cout<<_pl("\nKrzy¿yki wygra³y!\n");
   RysujPlansze();
   return false; }

if(plansza[0]!='1' && plansza[1]!='2' && plansza[2]!='3' &&
   plansza[3]!='4' && plansza[4]!='5' && plansza[5]!='6' &&
   plansza[6]!='7' && plansza[7]!='8' && plansza[8]!='9')
 { cout<<"\nRemis\n";
  RysujPlansze();
  return false; }
  else return true;
}


int gra(char znak)
{
char NPola;
RysujPlansze();
ponow:
cout<<_pl("\nWprowadŸ numer pola w którym chcesz wstawiæ ");
if(znak=='O')
cout<<_pl("kó³ko\n");
else
cout<<_pl("krzy¿yk\n");
cin>>NPola;
if(NPola != '1'  && NPola != '2' && NPola != '3' && NPola != '4' &&
   NPola != '5' && NPola != '6' && NPola != '7' && NPola != '8' && NPola != '9') {
cout<<_pl("Mo¿na wpisywaæ tylko liczby z zakresu 1-9 !\n");
goto ponow; }
int iNPola=NPola-49;
if(plansza[iNPola]=='O' || plansza[iNPola]=='X')
  {
   cout<<"NA POLU "<<NPola<<_pl(" JEST JU¯ \"")<<plansza[iNPola]<<"\"!";
   goto ponow; }

FOR(9)
{
if(NPola==plansza[i])
plansza[i]=znak;
}}


main()
{
_cinit();
WyswietlTytul();
fillrectattr(0xbb,1,1,200,1000);
FOR(9)
plansza[i]=(i+48)+1; // char(49)=1 (char(49++)=1++)

if(LosujGracza()) { cout<<"GRACZ 2 zaczyna\n\n"; gra('X'); }
else cout<<"GRACZ 1 zaczyna\n\n";

FOR(9){
check=sprawdz();
if(check) {
cout<<"\nGRACZ 1\n\n";
delay(1000);
gra('O'); }
else break;

check=sprawdz();
if(check)
{
cout<<"\nGRACZ 2\n\n";
delay(1000);
gra('X'); }
else break;
}

getch();
return 0;
}
