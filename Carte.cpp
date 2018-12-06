#include "Carte.h"

void Carte::allocTab(){
	freeTab();
	int j;
	tab = new Entity**[largeur] ();
	for (int i = 0; i < largeur; i++){
		tab[i] = new Entity*[hauteur] ();
		for (j = 0; j < hauteur; i++){
			tab[i][j] = NULL;
		}
	}
}

void Carte::freeTab(){
	int j;
	if(tab){
		for (int i = 0; i < largeur; i++){
			for (j = 0; j < hauteur; i++){
				delete tab[i][j];
				tab[i][j] = NULL;
			}
			delete[] tab[i];
			tab[i] = NULL;
		}
		delete[] tab;
		tab = NULL;
	}
}

Carte::Carte(const char* name){
	tab = NULL;
	nom = NULL;
}

Carte::Carte(int largeur, int hauteur){
	tab = NULL;
	nom = NULL;
	this->largeur = largeur;
	this->hauteur = hauteur;
	allocTab();
}

Carte::~Carte(){
	freeTab();
	if(nom) delete nom;
}

void Carte::draw(Fenetre& w){
	int j;
	for (int i = 0; i < largeur; i++){
		for (j = 0; j < hauteur; i++){
			tab[i][j]->draw(w);
		}
	}
}

bool Carte::ajoutEntity(int x, int y, int entity){
	if(tab[x][y] != NULL) return false;
	//if(entity == arbre){
		tab[x][y] = new Arbre(x,y,20,100);
	//}
	
	return true;
}
