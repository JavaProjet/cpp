#include "fenetre.h"

Fenetre::Fenetre(int largeur, int hauteur, const char *title){
	this->largeur = largeur;
	this->hauteur = hauteur;
	window = new RenderWindow(VideoMode(largeur, hauteur), title);
}

Fenetre::~Fenetre(){
	close();
	delete window;
}

void Fenetre::close(){
	if(window->isOpen()){
		window->close();
	}
}



