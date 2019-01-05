#include "Balle.h"

Balle::Balle(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 7){
		set_texture("balle_14px.png");
		dommage = 99;
		distance = 5;
	}


}
Balle::~Balle(){
	printf("destruction Balle\n");
}

void Balle::draw(Fenetre& w){
	Entity::draw(w);
}

void Balle::drawAt(Fenetre& w, sf::Vector2i point){
	Entity::drawAt(w, point);
}

entityType Balle::getType(){
	return balle; //11
}

int Balle::get_dommage(){
	 return dommage;
}
int Balle::get_distance(){
	return distance;
}
