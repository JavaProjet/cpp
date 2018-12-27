#include "editeur.h"
#include "fenetre.h"
#include "input.h"
#include "Carte.h"
#include <iostream>
#include "entity/Collision.h"

using namespace std;

void draw_item(Fenetre &w){
	//dessine le menu
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - 60 * 2 - 1, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - 50 - 1, w.getHauteur() - 60 * 2 - 1 + 10, 40, 40, "Somb3-bleu.png");
	
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - 60 * 3 - 2, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - 50 - 1, w.getHauteur() - 60 * 3 - 2 + 10, 40, 40, "Somb3-red.png");
	
	w.drawRect(w.getLargeur() - 60 * 2 - 2, w.getHauteur() - 60 * 2 - 1, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - (50 + 60) - 2, w.getHauteur() - 60 * 2 - 1 + 10, 40, 40, "Arbre_40px.png");
	
	w.drawRect(w.getLargeur() - 60 * 2 - 2, w.getHauteur() - 60 * 3 - 2, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - (50 + 60) - 2, w.getHauteur() - 60 * 3 - 2 + 10, 40, 40, "Cactus_40px.png");
	
	w.drawRect(w.getLargeur() - 60 * 3 - 3, w.getHauteur() - 60 * 2 - 1, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - (50 + 60 * 2) - 3, w.getHauteur() - 60 * 2 - 1 + 10, 40, 40, "Rocher_40px.png");
	
	w.drawRect(w.getLargeur() - 60 * 3 - 3, w.getHauteur() - 60 * 3 - 2, 60, 60, sf::Color(190,190,190));
	w.drawSprite(w.getLargeur() - (55 + 60 * 2) - 3, w.getHauteur() - 60 * 3 - 2 + 17, 50, 25, "Tronc_50x25px.png");
	
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - 60 * 4 - 3, 60, 60, sf::Color(190,190,190));
	//w.drawSprite(w.getLargeur() - 55 - 3, w.getHauteur() - 60 * 4 - 3 + 17, 50, 25, "Tronc_50x25px.png");
}

void draw_selection(Fenetre &w, int& choix, bool& modifchoix){
	//clique dans le menu pour changer d'item
	if(modifchoix){
		if(Input::clic.x > w.getLargeur() - 60 - 1){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = joueurBleu;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = joueurRouge;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 4 - 3) && (Input::clic.y < w.getHauteur() - 60 * 3 - 1)){
				choix = 0;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
		}
		else if(Input::clic.x > w.getLargeur() - 60 * 2 - 2 && Input::clic.x < w.getLargeur() - 60 - 1){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = arbre;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = cactus;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
		}
		
		else if(Input::clic.x > w.getLargeur() - 60 * 3 - 3 && Input::clic.x < w.getLargeur() - 60 * 2 - 2){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = rocher;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = tronc;
				modifchoix = false;
				Input::clic.x = Input::clic.y = -10;
			}
		}
	}
	
	//clique dans bouton pour ouvrir/fermer le menu
	if(Input::clic.x > w.getLargeur() - 60 - 1){
		if((Input::clic.y > w.getHauteur() - 60 - 1) && (Input::clic.y < w.getHauteur() - 1)){
			modifchoix = !modifchoix;
			Input::clic.x = Input::clic.y = -42;
		}
		else if(Input::clic.y != -42)modifchoix = false;
	}
	else if (Input::clic.x != -42) modifchoix = false;
	
	if(modifchoix) draw_item(w);
	
	//affiche l'item choisit dans le bouton d'ouverture de menu
	switch(choix){
		case joueurBleu  : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - 60 + 10, 40, 40, "Somb3-bleu.png");    break;
		case joueurRouge : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - 60 + 10, 40, 40, "Somb3-red.png");     break;
		case arbre		 : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - 60 + 10, 40, 40, "Arbre_40px.png");    break;
		case cactus		 : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - 60 + 10, 40, 40, "Cactus_40px.png");   break;
		case rocher		 : w.drawSprite(w.getLargeur() - 61 + 10, w.getHauteur() - 60 + 10, 40, 40, "Rocher_40px.png");   break;
		case tronc		 : w.drawSprite(w.getLargeur() - 61 + 5,  w.getHauteur() - 60 + 17, 50, 25, "Tronc_50x25px.png"); break;
		default : /*on affiche la souris*/ break;
	}
}

void AjoutSupp(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix, Carte& c){
	if(Input::clic.y < w.getHauteur() - 60 && Input::clic.y > 0 && !modifchoix){
		if(choix == 0){
			c.deleteEntity(Input::clic.x, Input::clic.y); //si l'on clique sur un item il est supprimé, sauf si c'est celui d'un joueur
		}
		else {
			if(choix == joueurBleu)
				c.getJoueurBleu().setPosition(Input::clic.x, Input::clic.y - 40);
			if(choix == joueurRouge)
				c.getJoueurRouge().setPosition(Input::clic.x, Input::clic.y - 40);
		}
		Input::clic.x = Input::clic.y = -10;
	}
}

void draw_menu(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix, Carte& c){
	//dessine la barre grise en bas de l'ecran ainsi que le carré contenant le choix et une phrase juste au dessus de la barre ou on ecrit
	w.drawRect(0, w.getHauteur() - 60, w.getLargeur(), 60, sf::Color(190,190,190));
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - 60, 60, 60, sf::Color(190,190,190));
	w.write("Nom de la carte :", 20, sf::Color::Black, 10, w.getHauteur() - 55);
	
	//afficher le curseur ou une image a sa place selon ou il est
	if(cursorPos.y > w.getHauteur() - 60 || modifchoix) //dans le menu
		w.getWindow().setMouseCursorVisible(true);
	else {
		if(choix != 0) w.getWindow().setMouseCursorVisible(false); //en dehors du menu
		switch(choix){
			case joueurBleu  : w.drawSprite(cursorPos.x,cursorPos.y - 40, 40, 40, "Somb3-bleu.png");    break;
			case joueurRouge : w.drawSprite(cursorPos.x,cursorPos.y - 40, 40, 40, "Somb3-red.png");     break;
			case arbre		 : w.drawSprite(cursorPos.x,cursorPos.y - 40, 40, 40, "Arbre_40px.png");    break;
			case cactus		 : w.drawSprite(cursorPos.x,cursorPos.y - 40, 40, 40, "Cactus_40px.png");   break;
			case rocher		 : w.drawSprite(cursorPos.x,cursorPos.y - 40, 40, 40, "Rocher_40px.png");   break;
			case tronc		 : w.drawSprite(cursorPos.x,cursorPos.y - 25, 50, 25, "Tronc_50x25px.png"); break;
			default 		 : break;
		}
	}
	draw_selection(w,choix,modifchoix);
}

void nouvelle(){
	sf::Vector2i cursorPos;
	Fenetre window(600,500 + 60,"Editeur de cartes");
	Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	Input nomCarte(&window,sf::Vector2i(10,window.getHauteur() - 25), 20, 30);
	int choix = 1;
	bool modifchoix = false;
	
	window.getWindow().clear(sf::Color(160,62,35));
	c.draw(window);
	draw_menu(window, cursorPos, choix, modifchoix, c);
	nomCarte.drawInput();
	window.getWindow().display();
	
	while(window.isOpen()){
		cursorPos = sf::Mouse::getPosition(window.getWindow());
		
		window.getWindow().clear(sf::Color(160,62,35));
		c.draw(window);
		Input::get_clic(window);
		draw_menu(window, cursorPos, choix, modifchoix, c);
		nomCarte.drawInput();
		AjoutSupp(window, cursorPos, choix, modifchoix, c);
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
