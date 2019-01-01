#include "entity_rect.h"
#include <iostream>

using namespace std;

Entity_rect::Entity_rect() : Entity() {
}

Entity_rect::~Entity_rect(){
	cout << "Destruction entité rectangulaire" << endl;
}

Entity_rect::Entity_rect(int x, int y, int sizeX,int sizeY, int vie) : Entity(x,y){
		
	this->vie = vie;
	size.x = position.x+sizeX;
	size.y = position.y+sizeY;
	
}

sf::Vector2i &Entity_rect::get_size(){
	return size;
}

void Entity_rect::setPosition(int x, int y){
	Entity::setPosition(x, y);
}

entityType Entity_rect::getPrimaryType(){
	return ronde;
}
