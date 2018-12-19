#include "Entity.h"
#include <string.h>

using namespace std;

/*const int Entity::top = 0;
const int Entity::left = 270;
const int Entity::right = 90;
const int Entity::bottom = 180;
*/

Entity::Entity() : position(100,100){
	//vision = top;
	texture = NULL;
	vie = 100;
}

Entity::~Entity(){
	if(texture != NULL){
		delete texture;
		texture = NULL;
	}
}

Entity::Entity(int x, int y) : position(x,y){
	//vision = top;
	texture = NULL;
	vie = 100;
}

bool Entity::degats(int nb){
	vie -= nb;
	if(vie <= 0) return false;
	else return true;
}
void Entity::set_texture(const char* name){
	texture = new char();
	int taille = strlen(name);
	for (int i = 0; i < taille + 1; i++){
		texture[i] = name[i];
	}
}
/*
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
*/

sf::Vector2i& Entity::getPosition(){
	return position;
}

void Entity::deplace(int x, int y){
	position.x += x;
	position.y += y;
}

int Entity::getVie(){
	return vie;
}

void Entity::setVie(int _vie){
	vie = _vie;
}
