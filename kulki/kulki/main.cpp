#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <cstdio>
#define MAXWIDTH 800 //wymiary okna
#define MAXHIGHT 600
#define MAXMAPX 4000 //wymiary wirtualnej mapy
#define MAXMAPY 3000
#define ILOSC_OBCYCH 100
sf::Vector2f apnm(0,0); //aktualna pozycja ekranu na mapie

class kulka
{
public:
    double x, y, rozmiar, predkosc;
    sf::CircleShape circle;
    int przesun(double x, double y), zjedz(kulka* ofiara), usun(), ustaw(), spr(kulka* cel);
};


int kulka::spr(kulka* cel)
{
double dystansx = abs(cel->x-x);
double dystansy = abs(cel->y-y);
double dystans = sqrt(pow(dystansx,2)+pow(dystansy,2));//odleglosc miedzy srodkami kulek
if (rozmiar>cel->rozmiar){
    if (dystans<rozmiar){
    if (rozmiar-cel->rozmiar>rozmiar*1/10){// czy kulki ie są podobnej wielkosci
                zjedz(cel);
                return -1;}}

                }else{
        if (dystans<cel->rozmiar){
        if (cel->rozmiar-rozmiar>cel->rozmiar*1/10)
        cel->zjedz(this);}}
    return 0;
}

int kulka::zjedz(kulka* ofiara)
{
    rozmiar=sqrt(((pow(rozmiar,2)*3.14)+(pow(ofiara->rozmiar,2)*3.14))/3.14);//Suma pól koła a potem liczę z tego nowy promień
    ofiara->rozmiar=0;
    ofiara->x=0;
    ofiara->y=0;
    return 1;
}

int kulka::ustaw()
{
    circle.setOutlineColor(sf::Color::Red);
    circle.setRadius(rozmiar);
    circle.setPosition(x-apnm.x,y-apnm.y);
    return 1;

}

int kulka::przesun(double celx, double cely)
{
    predkosc=10-rozmiar*1/500;
double oldx=x;
double oldy=y;
double dystansx = abs(celx-x);
double dystansy = abs(cely-y);
double dystans = sqrt(pow(dystansx,2)+pow(dystansy,2));
if (x>celx)
x-=dystansx/(dystans/predkosc);
if (x<celx)
    x+=dystansx/(dystans/predkosc);
if (y>cely)
y-=dystansy/(dystans/predkosc);
else
y+=dystansy/(dystans/predkosc);

if (x-apnm.x>0 && x-apnm.x<MAXWIDTH && y-apnm.y>0 && y-apnm.y<MAXHIGHT)
{
    ustaw();
    return 1;
}else{x=oldx; y=oldy;}
    return -1;
}

int kulka::usun()
{
 x=-100;
 y=-100;
 rozmiar=0;
 return 1;
}

    int stworz(int ilosc, kulka *obcy)
{
    int i;

    for (i=0;i<ilosc;i++)
    {
        obcy[i].x=( std::rand() % (MAXMAPX-10) ) + 10;
        obcy[i].y=( std::rand() % (MAXMAPY-10) ) + 10;
        obcy[i].rozmiar=( std::rand() % 100 ) + 1;
        obcy[i].predkosc=0;
    }

    return 1;
}

int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( MAXWIDTH, MAXHIGHT, 32 ), "Kurs SFML - http://cpp0x.pl" );
    sf::Texture tekstura;
    srand( time( NULL ) );
    sf::Text tekst;
int i;
    char buf[100];
    sf::Vector2i mouse;

    sf::Font font;
font.loadFromFile("arial.ttf");
     tekst.setFont(font);
        tekst.setColor(sf::Color::Red);
        tekst.setCharacterSize(24);
        tekst.setPosition(100,550);
    tekstura.loadFromFile( "poland.png" );
    sf::Sprite obrazek;
    obrazek.setTexture( tekstura );

        kulka ja;
        ja.x=200;
        ja.y=200;
        ja.rozmiar=50;
        ja.predkosc=1;
        ja.ustaw();
        ja.circle.setFillColor( sf::Color::Red );
        ja.circle.setOrigin(ja.rozmiar,ja.rozmiar);
        kulka obcy[ILOSC_OBCYCH];
        stworz(ILOSC_OBCYCH, obcy);
        for (i=0;i<ILOSC_OBCYCH;i++)
        {
            obcy[i].ustaw();
            obcy[i].circle.setOrigin(obcy[i].rozmiar,obcy[i].rozmiar);
        }

sf::Clock zegar; //tworzymy zegar, który bêdzie odlicza³ nam czas od jego utworzenia
  sf::Time CzasOdAktualizacji = sf::Time::Zero; //tworzymy obiekt, który bêdzie zapamiêtywa³ czas, który up³yna³
                                                  //od ostatniej aktualizacji i zerujemy go.
    const sf::Time KrokCzasowy = sf::seconds(1.f/60.f); //nasz krok czasowy i czas klatki, tutaj oko³o 60
                                                         //klatek na sekunde


    while(oknoAplikacji.isOpen())
    {

        sf::Time Czas = zegar.restart(); //tworzymy obiekt, który bêdzie przetrzymywa³ czas jaki zaj¹³ obieg pêtli
        CzasOdAktualizacji += Czas; // zwiêkszamy czas od ostatniej aktualizacji(skrót: COOA) o czas obiegu pêtli

        while(CzasOdAktualizacji > KrokCzasowy) //jeœli COOA wiêksze od kroku czasowego
        {
            CzasOdAktualizacji -= KrokCzasowy; // odejmujemy czas trwania klatki
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();

        }
        if (ja.x>MAXWIDTH/2)
            apnm.x=ja.x-MAXWIDTH/2;
        if (ja.y>MAXHIGHT/2)
            apnm.y=ja.y-MAXHIGHT/2;

        mouse=sf::Mouse::getPosition(oknoAplikacji);
        oknoAplikacji.clear( sf::Color::Black );
        ja.przesun(mouse.x+apnm.x,mouse.y+apnm.y);
        for (i=0;i<ILOSC_OBCYCH;i++)
        {
            obcy[i].ustaw();
            oknoAplikacji.draw(obcy[i].circle);
            if (obcy[i].spr(&ja)==-1) return 0;//koniec gry
        }

            sprintf(buf,"%f %f %f %f",ja.x,ja.y,apnm.x,apnm.y);
        oknoAplikacji.draw(ja.circle);
        tekst.setString(buf);
        oknoAplikacji.draw (tekst);
        oknoAplikacji.display();
    }}
    return 0;
}

