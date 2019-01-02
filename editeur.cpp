#include "editeur.h"
#include "fenetre.h"
#include "input.h"
#include "Carte.h"
#include <iostream>
#include "entity/Collision.h"
#include <string>

using namespace std;

sf::Texture textureCursor; //pour garder la texture en mémoire sinon sprite devient invalide
sf::Sprite spriteCursor; //variable contenant le sprite pour changer le cursor
bool changeSprite = false; //indique si le sprite doit etre mit a jour
#define deplacement 100   //valeurs possibles 1 2 5 10 20 50 100 200 ...


void changeCursor(const char* filename, int sizeX, int sizeY){
	changeSprite = false;
	string str = "Textures/";
	if(filename)str.append(filename);

	if (!textureCursor.loadFromFile(str)){
		cout << "unable to load texture" << str << endl;
	}
	else {
		spriteCursor.setTexture(textureCursor);
		spriteCursor.setTextureRect(sf::IntRect(0, 0, sizeX, sizeY));
	}
}

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
	w.drawSprite(w.getLargeur() - 38 - 3, w.getHauteur() - 60 * 4 - 3 + 12, 23, 35, "Souris_23x35px.png");
}

void draw_selection(Fenetre &w, int& choix, bool& modifchoix, int& taille){
	//clique dans le menu pour changer d'item
	if(modifchoix){
		if(Input::clic.x > w.getLargeur() - 60 - 1){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = joueurBleu;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = joueurRouge;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 4 - 3) && (Input::clic.y < w.getHauteur() - 60 * 3 - 1)){
				choix = 0;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
		}
		else if(Input::clic.x > w.getLargeur() - 60 * 2 - 2 && Input::clic.x < w.getLargeur() - 60 - 1){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = arbre;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = cactus;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
		}
		
		else if(Input::clic.x > w.getLargeur() - 60 * 3 - 3 && Input::clic.x < w.getLargeur() - 60 * 2 - 2){
			if((Input::clic.y > w.getHauteur() - 60 * 2 - 1) && (Input::clic.y < w.getHauteur() - 60 - 1)){
				choix = rocher;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
			else if((Input::clic.y > w.getHauteur() - 60 * 3 - 2) && (Input::clic.y < w.getHauteur() - 60 * 2 - 1)){
				choix = tronc;
				modifchoix = false;
				changeSprite = true;
				Input::clic.x = Input::clic.y = -10;
			}
		}
	}
	
	//modifie la taille selon la flèche
	if(Input::clic.x > w.getLargeur() - 60 * 2 - 2 && Input::clic.x < w.getLargeur() - 60 - 1){
		if(Input::clic.y > w.getHauteur() - 60 && Input::clic.y < w.getHauteur() - 30){
			if(taille < grand) taille++;
			changeSprite = true;
			Input::clic.x = Input::clic.y = -10;
		}
		else if(Input::clic.y > w.getHauteur() - 30 && Input::clic.y < w.getHauteur()){
			if(taille > petit)taille--;
			changeSprite = true;
			Input::clic.x = Input::clic.y = -10;
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
		case 0			 : w.drawSprite(w.getLargeur() - 61 + 21, w.getHauteur() - 60 + 12, 23, 35, "Souris_23x35px.png");break;
		default : break;
	}
}

void AjoutSupp(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix, int& taille, Carte& c, sf::Vector2i min){
	if(Input::clic.y < c.getHauteur() && Input::clic.y > 0 && Input::clic.x < c.getLargeur() && !modifchoix){ //le clic est dans la carte
		if(choix == 0){ //le cursor est la souris
			c.deleteEntity(Input::clic.x + min.x, Input::clic.y + min.y); //si l'on clique sur un item, il est supprimé sauf si c'est un joueur
		}
		else { //le cursor n'est pas la souris
			
			spriteCursor.setPosition(spriteCursor.getPosition().x + min.x, spriteCursor.getPosition().y + min.y);
			
			if(c.collisionEntity(spriteCursor) == -1){ // si aucune collision avec une entity
				if(choix == joueurBleu){ 
					if(!(c.collisionJoueur(spriteCursor,false)))
						c.getJoueurBleu().setPosition(Input::clic.x - 20 + min.x, Input::clic.y - 20 + min.y);
					//le joueur est obligatoirement présent, il n'est donc pas supprimé et il est déplacé au lieu d'être ajouté
					
				}
				else if(choix == joueurRouge){
					if(!(c.collisionJoueur(spriteCursor,true)))
						c.getJoueurRouge().setPosition(Input::clic.x - 20 + min.x, Input::clic.y - 20 + min.y);
				}
				if(!(c.collisionJoueur(spriteCursor,false)) && !(c.collisionJoueur(spriteCursor,true))){
					if(taille == petit){
						switch(choix){
							case arbre	 : c.ajoutEntity(Input::clic.x - 40 + min.x, Input::clic.y - 40 + min.y, petit, arbre);  break;
							case cactus	 : c.ajoutEntity(Input::clic.x - 20 + min.x, Input::clic.y - 20 + min.y, petit, cactus); break;
							case rocher	 : c.ajoutEntity(Input::clic.x - 20 + min.x, Input::clic.y - 20 + min.y, petit, rocher); break;
							case tronc	 : c.ajoutEntity(Input::clic.x - 25 + min.x, Input::clic.y - 12 + min.y, petit, tronc);  break;
							default 	 : break;
						}
					}
					else if(taille == moyen){
						switch(choix){
							case arbre	 : c.ajoutEntity(Input::clic.x - 60 + min.x, Input::clic.y - 60 + min.y, moyen, arbre);  break;
							case cactus	 : c.ajoutEntity(Input::clic.x - 30 + min.x, Input::clic.y - 30 + min.y, moyen, cactus); break;
							case rocher	 : c.ajoutEntity(Input::clic.x - 50 + min.x, Input::clic.y - 50 + min.y, moyen, rocher); break;
							case tronc	 : c.ajoutEntity(Input::clic.x - 40 + min.x, Input::clic.y - 20 + min.y, moyen, tronc);  break;
							default 	 : break;
						}
					}
					else if(taille == grand){
						switch(choix){
							case arbre	 : c.ajoutEntity(Input::clic.x - 90 + min.x, Input::clic.y - 90 + min.y, grand, arbre);  break;
							case cactus	 : c.ajoutEntity(Input::clic.x - 40 + min.x, Input::clic.y - 40 + min.y, grand, cactus); break;
							case rocher	 : c.ajoutEntity(Input::clic.x - 80 + min.x, Input::clic.y - 80 + min.y, grand, rocher); break;
							case tronc	 : c.ajoutEntity(Input::clic.x - 60 + min.x, Input::clic.y - 30 + min.y, grand, tronc);  break;
							default 	 : break;
						}
					}
				}
			}
		}
		Input::clic.x = Input::clic.y = -10; //on enleve le clic de la carte pour eviter de repeter l'action
	}
}

void gestionCursor(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix, int& taille){
	//afficher le curseur ou une image a sa place selon ou il est
	if(cursorPos.y > w.getHauteur() - 60 || modifchoix) //dans le menu
		w.getWindow().setMouseCursorVisible(true);
	
	else { // en dehors du menu, on met a jour le sprite qui remplace le cursor souris
		if(taille == petit){
			switch(choix){
				case arbre	: 	if(changeSprite)changeCursor("Arbre_80px.png",80,80);
								spriteCursor.setPosition(cursorPos.x - 40,cursorPos.y - 40);  break;
				case cactus	: 	if(changeSprite)changeCursor("Cactus_40px.png",40,40);
								spriteCursor.setPosition(cursorPos.x - 20,cursorPos.y - 20);  break;
				case rocher	: 	if(changeSprite)changeCursor("Rocher_40px.png",40,40);
								spriteCursor.setPosition(cursorPos.x - 20,cursorPos.y - 20);  break;
				case tronc	: 	if(changeSprite)changeCursor("Tronc_50x25px.png",50,25);
								spriteCursor.setPosition(cursorPos.x - 25,cursorPos.y - 12);  break;
				default 	: break;
			}
		}
		else if(taille == moyen){
			switch(choix){
				case arbre	: 	if(changeSprite)changeCursor("Arbre_120px.png",120,120);
								spriteCursor.setPosition(cursorPos.x - 60,cursorPos.y - 60);  break;
				case cactus	: 	if(changeSprite)changeCursor("Cactus_60px.png",60,60);
								spriteCursor.setPosition(cursorPos.x - 30,cursorPos.y - 30);  break;
				case rocher	: 	if(changeSprite)changeCursor("Rocher_100px.png",100,100);
								spriteCursor.setPosition(cursorPos.x - 50,cursorPos.y - 50);  break;
				case tronc	: 	if(changeSprite)changeCursor("Tronc_80x40px.png",80,40);
								spriteCursor.setPosition(cursorPos.x - 40,cursorPos.y - 20);  break;
				default 	: break;
			}
		}
		else if(taille == grand){
			switch(choix){
				case arbre	: 	if(changeSprite)changeCursor("Arbre_180px.png",180,180);
								spriteCursor.setPosition(cursorPos.x - 90,cursorPos.y - 90);  break;
				case cactus	: 	if(changeSprite)changeCursor("Cactus_80px.png",80,80);
								spriteCursor.setPosition(cursorPos.x - 40,cursorPos.y - 40);  break;
				case rocher	: 	if(changeSprite)changeCursor("Rocher_160px.png",160,160);
								spriteCursor.setPosition(cursorPos.x - 80,cursorPos.y - 80);  break;
				case tronc	: 	if(changeSprite)changeCursor("Tronc_120x60px.png",120,60);
								spriteCursor.setPosition(cursorPos.x - 60,cursorPos.y - 30);  break;
				default 	: break;
			}
		}
		if(choix == joueurBleu){
			spriteCursor.setPosition(cursorPos.x - 20,cursorPos.y - 20);
			if(changeSprite)changeCursor("Somb3-bleu.png",40,40);
		}
		else if(choix == joueurRouge){
			spriteCursor.setPosition(cursorPos.x - 20,cursorPos.y - 20);
			if(changeSprite)changeCursor("Somb3-red.png",40,40);
		}
		if(choix != 0){ //on n'affiche pas le cursor souris mais le sprite
			w.getWindow().setMouseCursorVisible(false); 
			w.getWindow().draw(spriteCursor);
		}
	}
}

void draw_menu(Fenetre &w, sf::Vector2i& cursorPos, int& choix, bool& modifchoix, int& taille, Carte& c){
	gestionCursor(w, cursorPos, choix, modifchoix, taille);
	
	//dessine la barre grise en bas de l'ecran ainsi que le carré contenant le choix et une phrase juste au dessus de la barre ou on ecrit
	w.drawRect(0, w.getHauteur() - 60, w.getLargeur(), 60, sf::Color(190,190,190));
	w.drawRect(w.getLargeur() - 60 - 1, w.getHauteur() - 60, 60, 60, sf::Color(190,190,190));
	w.write("Nom de la carte :", 20, sf::Color::Black, 10, w.getHauteur() - 55);
	
	//dessin de taille
	string str = "Taille : ";
	if(taille == petit) str.append("petit");
	if(taille == moyen) str.append("moyen");
	if(taille == grand) str.append("grand");
	w.drawRect(360 - 3, w.getHauteur() - 60, 120, 60, sf::Color(190,190,190));
	w.write(str.c_str(), 20, sf::Color::Black, 365, w.getHauteur() - 40);
	w.drawRect(w.getLargeur() - 60 * 2 - 2, w.getHauteur() - 60, 60, 30, sf::Color(190,190,190));
	w.write("/\\", 20, sf::Color::Black, w.getLargeur() - 60 * 2 - 2 + 25, w.getHauteur() - 58);
	w.write("\\/", 20, sf::Color::Black, w.getLargeur() - 60 * 2 - 2 + 25, w.getHauteur() - 25);
	
	draw_selection(w,choix,modifchoix,taille);
}

void gestionTouches(sf::Keyboard::Key key, sf::Vector2i& min, sf::Vector2i& max, Carte& c){
	if(key == sf::Keyboard::Key::Up){
		if(min.y - deplacement >= 0){
			min.y -= deplacement;
			max.y -= deplacement;
		}
	}
	
	if(key == sf::Keyboard::Key::Down){
		if(max.y + deplacement <= c.getHauteur()){
			min.y += deplacement;
			max.y += deplacement;
		}
	}
	
	if(key == sf::Keyboard::Key::Left){
		if(min.x - deplacement >= 0){
			min.x -= deplacement;
			max.x -= deplacement;
		}
	}
	
	if(key == sf::Keyboard::Key::Right){
		if(max.x + deplacement <= c.getLargeur()){
			min.x += deplacement;
			max.x += deplacement;
		}
	}
	if(key == sf::Keyboard::Key::Return ){
		c.setNom("tartine");
		c.save();
	}
}

void nouvelle(){
	sf::Vector2i cursorPos;
	Fenetre window(600,500 + 60,"Editeur de cartes");
	Carte c(1500,1500);
	Input nomCarte(&window,sf::Vector2i(10,window.getHauteur() - 25), 20, 30);
	int choix = 0;
	bool modifchoix = false;
	int taille = petit;
	sf::Keyboard::Key key;
	sf::Vector2i min(0,0);
	sf::Vector2i max(window.getLargeur(), window.getHauteur() - 60);
	
	window.getWindow().clear();
	c.drawIfIn(window, min, max);
	draw_menu(window, cursorPos, choix, modifchoix, taille, c);
	nomCarte.drawInput();
	window.getWindow().display();
	
	while(window.isOpen()){
		cursorPos = sf::Mouse::getPosition(window.getWindow());
		
		window.getWindow().clear();
		window.drawRect(0, 0, c.getLargeur(), c.getHauteur(), sf::Color(160,62,35));
		
		key = Input::get_clic(window);
		gestionTouches(key, min, max, c);
		c.drawIfIn(window,min,max);
		draw_menu(window, cursorPos, choix, modifchoix, taille, c);
		nomCarte.drawInput();
		AjoutSupp(window, cursorPos, choix, modifchoix, taille, c, min);
		
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
