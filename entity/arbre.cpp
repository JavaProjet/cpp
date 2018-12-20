#include "arbre.h"

Arbre::Arbre(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 1) {
		this->rayon = 40;
		set_texture("Arbre_80px.png");
	}
	if(rayon == 2) {
		this->rayon = 60;
		set_texture("Arbre_120px.png");
	}
	if(rayon == 3) {
		this->rayon = 85;
		set_texture("Arbre_180px.png");
	}
	centre.x = position.x + this->rayon;
	centre.y = position.y + this->rayon;
}
Arbre::~Arbre(){
	printf("destruction arbre\n");
}
