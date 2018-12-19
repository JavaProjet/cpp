#include "entity_rect.h"

Entity_rect::Entity_rect() : Entity() {
}

Entity_rect::~Entity_rect(){
}

Entity_rect::Entity_rect(int x, int y, int sizeX,int sizeY, int vie) : Entity(x,y){
		
	this->vie = vie;
	size.x = position.x+sizeX;
	size.y = position.y+sizeY;
	
}

sf::Vector2i &Entity_rect::get_size(){
	return size;
}

void Entity_rect::draw(Fenetre& w){
	w.drawSprite(position.x, position.y, size.x,size.y, texture);
}
