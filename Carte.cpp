#include "Carte.h"

void Carte::allocTab(){
	freeTab();
	
	tab = new Entity*[largeur] ();
	for (int i = 0; i < largeur; i++){
		tab[i] = new Entity[hauteur] ();
	}
}

void Carte::freeTab(){
	if(tab){
		for (int i = 0; i < largeur; i++){
			delete[] tab[i];
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
}

Carte::~Carte(){
	freeTab();
	if(nom) delete nom;
}

