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
	switch (entity){
		case joueur_b : ent = new Joueur(x,y,100, true);break;
		case joueur_r : ent = new Joueur(x,y,100, false);break;
		case arbre : ent = new Arbre(x,y,size,100);break;
		case cactus : ent = new Cactus(x,y,size,100);break;
		case rocher : ent = new Rocher(x,y,size,100);break;
		case tronc : ent = new Tronc(x,y,size,0,100);break;
	}
	if(ent != NULL) this->entity.push_back(ent);
	return true;
}
