#include "entity_ronde.h"

Entity_ronde::Entity_ronde() : Entity() {
	
	rayon = 20;
}

Entity_ronde::~Entity_ronde(){
}

Entity_ronde::Entity_ronde(int x, int y, int rayon, int vie) : Entity(x,y){
		
	this->rayon = rayon;
	this->vie = vie;
	centre.x = position.x + rayon;
	centre.y = position.y + rayon;
	
}

int Entity_ronde::get_rayon(){
	return rayon;
}

void Entity_ronde::draw(Fenetre& w){
	w.drawSprite(position.x, position.y, rayon* 2, rayon* 2, texture);
}
