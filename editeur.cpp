#include "editeur.h"
#include "fenetre.h"
#include "input.h"
#include "Carte.h"
#include <iostream>

using namespace std;

void draw_menu(Fenetre &w){
	unsigned int size = 60;
	w.drawRect(0, w.getHauteur() - size, w.getLargeur(), size, sf::Color(190,190,190));
}

void nouvelle(){
	Fenetre window(600,500,"Editeur de cartes");
	window.getWindow().clear();
	window.getWindow().display();
	Carte c(600,500);
	Input nomCarte(&window,sf::Vector2i(10,window.getHauteur() - 40), 20, 15);
	sf::Vector2i clic;
	while(window.isOpen()){
		window.getWindow().clear(sf::Color(160,62,35));
		window.drawSprite(0,0,600,500,"Terre.png");
		draw_menu(window);
		c.draw(window);
		clic = Input::get_clic(window);
		nomCarte.drawInput();
		window.getWindow().display();
	}
}

void modifier(){
    Fenetre window(600,500,"test clic");
    Input a(&window,sf::Vector2i(10,10),30,20);	
    while(window.isOpen()){
		window.drawSprite(0,0,600,500,"fond.png");
        Input::get_clic(window);
        a.drawInput();
        window.getWindow().display();
    }
    cout << endl;
}

int menuEdition(){
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
				if(event.key.code == sf::Keyboard::Up && choix < -1) choix++;
				if(event.key.code == sf::Keyboard::Down && choix > -3 ) choix--;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        window.drawSprite(0,0,600,500,"fond.png");
        
        window.write("Nouvelle carte", 40, sf::Color::Black, 200, 100);
        window.write("Modifier une carte", 40, sf::Color::Black, 170, 220);
        window.write("Retour vers le menu", 40, sf::Color::Black, 165, 340);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 120, 100);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 120, 220);
		}
        else if(choix == -3){
			window.write(">", 40, sf::Color::Black, 120, 340);
		}

        window.getWindow().display();
    }
    return choix;
}

int editeur(){
    int choix = -1;

    choix = menuEdition();
    
    if(choix == 1){
        //nouvelle carte
        nouvelle();
    }
    else if(choix == 2){
        //modification de carte
        modifier();
    }

	return choix;
}
