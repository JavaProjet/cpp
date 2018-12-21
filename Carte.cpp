#include "Carte.h"

Carte::Carte(const char* name){
	nom = NULL;
}

Carte::Carte(int largeur, int hauteur){
	nom = NULL;
	this->largeur = largeur;
	this->hauteur = hauteur;
}

Carte::~Carte(){
	if(nom) delete nom, nom = NULL;
	vector <Entity*>::iterator i;
	 for (i = entity.begin(); i < entity.end(); i++){
		 entity.erase(i);
	 }
}

void Carte::draw(Fenetre& w){
	for (unsigned int i = 0; i < entity.size(); i++){
		entity[i]->draw(w);
	}
}

bool Carte::ajoutEntity(int x, int y, int size, int entity){
	Entity* ent = NULL;
	
	if(entity == joueur_b)
		ent = new Joueur(x,y,100, true);
	
	else if(entity == joueur_r)
		ent = new Joueur(x,y,100, false);
	
	else if(entity == arbre) {
		if(size == petit)
			ent = new Arbre(x,y,40,100);
		else if (size == moyen)
			ent = new Arbre(x,y,60,100);
		else if (size == grand)
			ent = new Arbre(x,y,85,100);
	}
	else if(entity == cactus) {
		if(size == petit)
			ent = new Cactus(x,y,20,100);
		else if (size == moyen)
			ent = new Cactus(x,y,30,100);
		else if (size == grand)
			ent = new Cactus(x,y,40,100);
	}
	else if(entity == rocher) {
		if(size == petit)
			ent = new Rocher(x,y,20,100);
		else if (size == moyen)
			ent = new Rocher(x,y,50,100);
		else if (size == grand)
			ent = new Rocher(x,y,80,100);
		
		
	}
	else if(entity == tronc) {
		if(size == petit)
			ent = new Tronc(x,y,50,25,100);
		else if (size == moyen)
			ent = new Tronc(x,y,80,40,100);
		else if (size == grand)
			ent = new Tronc(x,y,120,60,100);
	}
	
	if(ent != NULL) {
		this->entity.push_back(ent);
		return true;
	}
	else return false;
}
