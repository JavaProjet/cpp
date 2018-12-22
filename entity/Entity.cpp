#include "Entity.h"
#include <string.h>
#include <iostream>

using namespace std;

/*const int Entity::top = 0;
const int Entity::left = 270;
const int Entity::right = 90;
const int Entity::bottom = 180;
*/

Entity::Entity() : position(100,100){
	//vision = top;
	vie = 100;
}

Entity::~Entity(){
	cout << "Destruction entité" << endl;
}

Entity::Entity(int x, int y) : position(x,y){
	//vision = top;
	vie = 100;
}

bool Entity::degats(int nb){
	vie -= nb;
	if(vie <= 0) return false;
	else return true;
}

void Entity::set_texture(const char* name){
	string str = "Textures/";
	if(name)str.append(name);

	if (!texture.loadFromFile(str)){
		cout << "unable to load texture" << str << endl;
	}
	else {
		cout << "texture " << str << " loaded" << endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(position.x, position.y));
	}
}


void Entity::draw(Fenetre& w){
	w.getWindow().draw(sprite);
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

sf::Vector2i Entity::getPosition(){
	return position;
}

void Entity::setPosition(int x, int y){
	position.x = x;
	position.y = y;
	sprite.setPosition(sf::Vector2f(position.x, position.y));
}

void Entity::deplace(int x, int y){
	setPosition(position.x + x, position.y + y);
}

int Entity::getVie(){
	return vie;
}

void Entity::setVie(int _vie){
	vie = _vie;
}

sf::Sprite& Entity::getSprite(){
	return sprite;
}
