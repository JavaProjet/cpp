#include "selecteur_carte.h"
#include "Carte.h"
#include <iostream>
#include <string>

using namespace std;

namespace Selecteur {

vector <string> liste_cartes(){
	vector <string> nomCartes;
	char* cstr = new char[37] (); //30 : taille max d'un nom de carte, 6 : taille de ".carte", 1 pour '\0' 
	system("ls -1 Saves/ > liste_cartes.txt");
	
	string str = "";
	
	FILE* lc_txt = NULL;
	if( (lc_txt = fopen("liste_cartes.txt", "r")) ){
		while(fscanf(lc_txt, "%36s",cstr)){
			str = ""; str.append(cstr);
			if((str.substr(str.length() - 6,str.length())) == ".carte"){
				nomCartes.push_back(str);
			}
		}
		fclose(lc_txt);
	}
	system("rm -f liste_cartes.txt");
	return nomCartes;
}

void insert_in_tab(Carte** tabCartes, bool* sup, vector<string> nomCartes){
	tabCartes = new Carte* [nomCartes.size()] ();
	for (unsigned int i = 0; i < nomCartes.size(); i++){
		tabCartes[i] = new Carte(nomCartes[i].c_str(), false);
	}
	sup = new bool[nomCartes.size()] ();
	for (unsigned int i = 0; i < nomCartes.size(); i++){
		sup[i] = false;
	}
	
}

void supprimer_carte(const char* nom){
	if(nom){
		string str = "Saves/";
		str.append(nom);
		system(str.c_str());
	}
}

Carte* deleteTab(Carte** tabCartes, int sauf_lui, int size){
	Carte* c = NULL;
	if(sauf_lui > 0 && sauf_lui < size) c = tabCartes[sauf_lui];
	else return NULL;
	
	for (int i = 0; i < size; i++){
		if(i != sauf_lui)delete[] tabCartes[i];
	}
	delete[] tabCartes;
	return c;
}

sf::Keyboard::Key keyPressed(Fenetre& w){
	sf::Event event;
	while (w.getWindow().pollEvent(event)){
		if (event.type == sf::Event::Closed){
			w.close();
		}
		if(event.type == sf::Event::KeyPressed){
			return event.key.code;
		}
	}
	return sf::Keyboard::Unknown;
}

void gestionTouches(sf::Keyboard::Key touche, Carte** tabCartes, bool* sup, vector <string> nomCartes, int &i){
	if(touche == sf::Keyboard::Left && i > 1 )
		while(i > 1 && sup[i]) i--;
	
	if(touche == sf::Keyboard::Left && i < (int)(nomCartes.size() - 1))
		while(i < (int)(nomCartes.size() - 1) && sup[i]) i++;
	
	if(touche == sf::Keyboard::Backspace){
		bool allRM = true;
		sup[i] = true;
		supprimer_carte(nomCartes[i].c_str());
		for (unsigned int j = 0; j < nomCartes.size(); j++){
			if(sup[i] == false) allRM = false;
		}
		if(allRM) i = -1;
	}
}

Carte* select_carte(Fenetre& w){
	
	Carte** tabCartes = NULL;
	bool* sup = NULL;
	vector <string> nomCartes = liste_cartes();
	insert_in_tab(tabCartes, sup, nomCartes);
	
	int i = 0;
	sf::Keyboard::Key touche = sf::Keyboard::R;
	
	while(w.isOpen() && touche != sf::Keyboard::Return && i != -1){
		touche = keyPressed(w);
		gestionTouches(touche, tabCartes, sup, nomCartes, i);
		w.getWindow().clear();
		
		if(i != -1) tabCartes[i]->drawMiniature(w);
		else w.write("Aucune carte n'existe", 50, sf::Color::White, 50, 225);
		w.write("[Entree] : valider    [Backspace] : Supprimer la carte", 30, sf::Color::White, 10, w.getHauteur() - 40);
		w.getWindow().display();
	}
	
	Carte* toKeep = deleteTab(tabCartes, i, nomCartes.size());
	return toKeep;
}


}//namespace Select
