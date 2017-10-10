#include <SFML/Graphics.hpp>
#include <math.h>

#define PI 3.14159265

float katodmyszki(const sf::Vector2f pos, sf::Vector2i mouse)
{
    float x,y, kat, tan;
    x = mouse.x-pos.x;
    y = mouse.y-pos.y;


    tan = y/x;
    kat = atan (tan) * 180 / PI;
    if (mouse.x<pos.x){
    kat+=180;
    }
    return kat+90;
}


int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML - http://cpp0x.pl" );
    sf::Texture tekstura;
    sf::Text tekst;

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

        sf::CircleShape circle( 50 ); // tworzymy przyk³adowy kszta³t
        circle.setTexture( & tekstura );
        circle.setPosition(400,300);
        circle.setOrigin(50,50);

    while( oknoAplikacji.isOpen() )
    {
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
        oknoAplikacji.clear( sf::Color::Black );
        mouse=sf::Mouse::getPosition(oknoAplikacji);
        float kat = katodmyszki(circle.getPosition(), mouse);
        circle.setRotation(kat);
        sprintf(buf,"x = %f y = %f",mouse.x-circle.getPosition().x,mouse.y-circle.getPosition().y);
        tekst.setString(buf);
        oknoAplikacji.draw (tekst);
        oknoAplikacji.draw( circle );
        oknoAplikacji.display();
    }
    return 0;
}

