#include "Joueur.h"

Joueur::Joueur(int x, int y,int vie,bool bleu) : Entity_ronde(x,y,20,vie){

	if(bleu){
		 set_texture("Somb3-bleu.png");
		 
		 
	 }
	else set_texture("Somb3-red.png");
}

Joueur::~Joueur(){
	printf("destruction Joueur\n");
}

void Joueur::draw(Fenetre& w){
	sf::RectangleShape rectangle(sf::Vector2f(25.f, 5.f));
	rectangle.setFillColor(sf::Color(80, 57, 50));
	rectangle.setPosition(centre.x-2,centre.y-2);
	w.getWindow().draw(rectangle);
	Entity::draw(w);

	
}
