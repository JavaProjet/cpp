#include "Joueur.h"

Joueur::Joueur(int x, int y,int vie,bool bleu) : Entity_ronde(x,y,20,vie), rectangle(sf::Vector2f(25.f, 4.f)){

	if(bleu) set_texture("Somb3-bleu.png"); 
	
	else set_texture("Somb3-red.png");
	
	rectangle.setFillColor(sf::Color(80, 57, 50));
	rectangle.setPosition(centre.x,centre.y);
}

Joueur::~Joueur(){
	printf("destruction Joueur\n");
}

void Joueur::draw(Fenetre& w){
	w.getWindow().draw(rectangle);
	Entity::draw(w);

	
}
void Joueur::setPosition(int x, int y){
	Entity_ronde::setPosition(x, y);
	rectangle.setPosition(centre.x,centre.y);
	
}

void Joueur::setRotation(int i){
	rectangle.rotate(i);
	sf::Sprite sprite=Entity::getSprite();
	sprite.rotate(i);
}

float Joueur::getRotation(){
	return rectangle.getRotation();
	
}
