#include <iostream>
#include <unistd.h>
#include "fenetre.h"
#include "input.h"
#include "editeur.h"
#include "jouer.h"

using namespace std;

int fenetreMenu(){
	int choix = -1;
	Fenetre window(600,500,"Menu");
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 0;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up) choix = -1;
				if(event.key.code == sf::Keyboard::Down) choix = -2;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        
		window.drawSprite(0,0,600,500,"fond.png");

        window.write("Jouer une partie", 40, sf::Color::Black, 170, 180);
        window.write("Creer une carte", 40, sf::Color::Black, 180, 330);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 120, 180);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 120, 330);
		}
        
        window.getWindow().display();
    }
    return choix;
}

void inputTest(){
	Fenetre window(902,600,"yes");
	drawInput(window, 12, 10, 200, 10);
	while(window.isOpen()){
		sf::Event event;
		while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
			}
		}
		window.getWindow().clear(sf::Color(2,2,2));
        window.getWindow().display();
	}
}

int main(int argc, char *argv[]){
    int choix = -1;
    while(choix != 0){
		choix = fenetreMenu();
		if(choix == 1){
			cout << "lancement d'une partie\n";
			//jouer
			affiche();
		}
		else if(choix == 2){
			//editeur de carte
			cout << "lancement de l'éditeur de cartes\n";
			choix = editeur();
		}
	}
	cout << "l'utilisateur a quitté\n";
}
