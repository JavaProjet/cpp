#include "arbre.h"

Arbre::Arbre(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 40)
		set_texture("Arbre_80px.png");
	
	if(rayon == 60)
		set_texture("Arbre_120px.png");
	
	if(rayon == 85)
		set_texture("Arbre_180px.png");
}
Arbre::~Arbre(){
	printf("destruction arbre\n");
}

int Arbre::getType(){
	return arbre; //1
}
