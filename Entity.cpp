#include "Entity.h"

const int Entity::top = 0;
const int Entity::left = 270;
const int Entity::right = 90;
const int Entity::bottom = 180;

Entity::Entity() : pos(0,0){
	vision = top;
	vie = 100;
}

Entity::~Entity(){}

Entity::Entity(int x, int y) : pos(x,y){
	vision = top;
	vie = 100;
}

Entity::Entity(int x, int y, int vision) : pos(x,y){
	this->vision = vision;
	vie = 100;
}

bool Entity::degats(int nb){
	vie -= nb;
	if(vie <= 0) return false;
	else return true;
}

int Entity::getVision(){
	return vision;
}

void Entity::setVision(int degre){
	vision = degre;
}

void Entity::tourneVision(int degre){
	vision += degre;
	if(vision >= 360) vision -= 360; 
	if(vision < 0) vision += 360; 
}

Point& Entity::getPoint(){
	return pos.getPoint();
}

void Entity::setPoint(int x, int y){
	pos.setX(x);
	pos.setY(y);
}

void Entity::deplace(int x, int y){
	pos.deplace(x,y);
}

int Entity::getVie(){
	return vie;
}

void Entity::setVie(int _vie){
	vie = _vie;
}

void Entity::setRayon(int r){
	rayon = r;
}

int Entity::getRayon(){
	return rayon;
}
