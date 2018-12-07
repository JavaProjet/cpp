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
	while(entity.size() > 0){
		entity.pop_back();
	} 
}

void Carte::draw(Fenetre& w){
	for (unsigned int i = 0; i < entity.size(); i++){
		entity[i]->draw(w);
	}
}

bool Carte::ajoutEntity(int x, int y, int entity){
	Entity* ent = NULL;
	printf("size : %d\n", (int)this->entity.size()); 
	if(entity == arbre){
		printf("avant\n");
		ent = new Arbre(x,y,20,100);
		printf("apres\n");
	}
	if(ent != NULL) this->entity.push_back(ent);
	printf("size : %d\n", (int)this->entity.size()); 
	return true;
}
