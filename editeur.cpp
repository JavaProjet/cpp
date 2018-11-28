#include "editeur.h"
#include "fenetre.h"

using namespace std;

int menuEdition(){
    int choix = -1;
	Fenetre window(600,500,"Menu");
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 3;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up) choix = -1;
				if(event.key.code == sf::Keyboard::Down) choix = -2;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        
        window.write("Nouvelle Carte", 40, sf::Color::White, 190, 180);
        window.write("Modifier une Carte", 40, sf::Color::White, 170, 330);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::White, 120, 180);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::White, 120, 330);
		}
        
        window.getWindow().display();
    }
    return choix;
}

void editeur(){
	menuEdition();
}
