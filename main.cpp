#include <iostream>
#include <unistd.h>
#include "Sprite.h"
#include "fenetre.h"

using namespace std;


//modele a ne pas supprimer
int fenetre(){
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;

}

int main(int argc, char *argv[]){
    cout << "debut\n";
    
    
    Fenetre w(600,400, "toto");
    sleep(10);
    w.close();
    
    printf("fin\n"); 
}
