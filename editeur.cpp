#include "editeur.h"
#include "fenetre.h"
#include "input.h"
#include "Carte.h"
#include <iostream>
#include "entity/Collision.h"

using namespace std;

#define size 60

void draw_item(Fenetre &w){
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - size * 2 - 1, 60, size, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - 50 - 1, w.getHauteur() - size * 2 - 1 + 10, 40, 40, "Somb3-bleu.png");
	
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - size * 3 - 1, 60, size, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - 50 - 1, w.getHauteur() - size * 3 - 1 + 10, 40, 40, "Somb3-red.png");
}

void draw_selection(Fenetre &w, int& choix, bool& modifchoix){
	if(modifchoix){
		if(Input::clic.x > w.getLargeur() - 60 - 1){
			if((Input::clic.y > w.getHauteur() - size * 2 - 1) && (Input::clic.y < w.getHauteur() - size - 1)){
				choix = 1;
				modifchoix = false;
			}
			else if((Input::clic.y > w.getHauteur() - size * 3 - 1) && (Input::clic.y < w.getHauteur() - size * 2 - 1)){
				choix = 2;
				modifchoix = false;
			}
		}
	}
	
	if(Input::clic.x > w.getLargeur() - 60 - 1){
		if((Input::clic.y > w.getHauteur() - size - 1) && (Input::clic.y < w.getHauteur() - 1)){
			modifchoix = !modifchoix;
			if(modifchoix) draw_item(w);
		}
		else modifchoix = false;
	}
	else modifchoix = false;
	
	switch(choix){
		case 1 : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - size + 10, 40, 40, "Somb3-bleu.png"); break;
		case 2 : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - size + 10, 40, 40, "Somb3-red.png"); break;
		default : /*on affiche rien*/ break;
	}
}

void draw_menu(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix){
	w.drawRect(0, w.getHauteur() - 60, w.getLargeur(), size, sf::Color(190,190,190));
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - size, 60, size, sf::Color(190,190,190));
	w.write("Nom de la carte :", 20, sf::Color::Black, 10, w.getHauteur() - 55);
	
	printf("on dessine le menu\n");
	
	draw_selection(w,choix,modifchoix);
}

void nouvelle(){
	sf::Vector2i cursorPos;
	Fenetre window(600,500 + size,"Editeur de cartes");
	Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	Input nomCarte(&window,sf::Vector2i(10,window.getHauteur() - 25), 20, 30);
	int choix = 1;
	bool modifchoix = false;
	
	window.drawSprite(0,0,600,500,"Terre.png");
	c.draw(window);
	draw_menu(window, cursorPos, choix, modifchoix);
	nomCarte.drawInput();
	window.getWindow().display();
	
	while(window.isOpen()){
		cursorPos = sf::Mouse::getPosition(window.getWindow());
		
		window.drawSprite(0,0,600,500,"Terre.png");
		c.draw(window);
		Input::get_clic(window);
		draw_menu(window, cursorPos, choix, modifchoix);
		nomCarte.drawInput();
		window.getWindow().display();
	}
}

void modifier(){
    Fenetre window(600,500,"test clic");
    Input a(&window, sf::Vector2i(10,10),30,20);
    Input b(&window, sf::Vector2i(10,40),30,20);
    while(window.isOpen()){
		window.drawSprite(0,0,600,500,"fond.png");
        Input::get_clic(window);
        a.drawInput();
        b.drawInput();
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
