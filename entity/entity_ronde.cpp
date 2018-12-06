#include "entity_ronde.h"

Entity_ronde::Entity_ronde(){
	Entity();
	rayon = 20;
}

Entity_ronde::~Entity_ronde(){
}

Entity_ronde::Entity_ronde(int x, int y, int rayon, int vie){
	Entity(x,y);
	this->rayon = rayon;
	this->vie = vie;
}

int Entity_ronde::get_rayon(){
	return rayon;
}
