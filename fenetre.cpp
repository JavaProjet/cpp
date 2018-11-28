#include "fenetre.h"
#include <iostream>

Fenetre::Fenetre(int largeur, int hauteur, const char *title){
	this->largeur = largeur;
	this->hauteur = hauteur;
	window = new RenderWindow(VideoMode(largeur, hauteur), title);
	window->setVerticalSyncEnabled(false);
}

Fenetre::~Fenetre(){
	close();
	delete window;
}

void Fenetre::close(){
		window->close();
}

bool Fenetre::isOpen(){
	return window->isOpen();
}

RenderWindow& Fenetre::getWindow(){
	return *window;
}

sf::Font font;
bool fontLoaded = false;

bool Fenetre::write(const char* str, int police, sf::Color color, int x, int y){
	if(fontLoaded == false){
		if (!font.loadFromFile("dynasty.ttf"))
			return false;
		fontLoaded = true;
	}
	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(str);
	// set the character size
	text.setCharacterSize(police);
	// set the color
	text.setFillColor(color);
	
	text.setPosition(x,y);
	
	window->draw(text);
	
	return true;
}

void Fenetre::drawRect(int x, int y, int largeur, int hauteur, sf::Color color){
	sf::RectangleShape rectangle(sf::Vector2f(largeur, hauteur));

	// change the size to 100x100
	rectangle.setPosition(sf::Vector2f(x, y));
	
	window->draw(rectangle);
}
