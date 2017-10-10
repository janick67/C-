#include <SFML/Graphics.hpp>

class pole //klasa przechowuj¹ca wszystki obiekty, ¿elki
{
public:
    int x, y, type; //zmienne nale¿¹ce do ka¿dego pola
    sf::Sprite zelek; //zmienna w której jest "przechowywany" obrazek
    int ustaw(), uzupelnij();
   // int przesun(double x, double y), zjedz(kulka* ofiara), usun(), ustaw(), spr(kulka* cel);
};

int pole::ustaw()
{
    zelek.setPosition(x,y);
    return 1;
}

int pole::uzupelnij()
{
    if (type == 0){

    }
return 1;
//    zelek.setTexture(tekstura[type]);
}

int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 640, 480, 32 ), "Kurs SFML - http://cpp0x.pl" );

    sf::Texture tekstura[5];

    for (int i=0;i<6;i++)
    tekstura[i].loadFromFile( "img/"+i+".png" );

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

        for (i=0;i<100;i++)
        {
            pole[i].ustaw();
            oknoAplikacji.draw(pole[i].zelek);
        }

        oknoAplikacji.display();
    }
    return 0;
}
