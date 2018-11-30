#include "fenetre.h"
#include <iostream>
#include <string>

using namespace std;

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

float Fenetre::getFont(int nbChar, int police){
	if(fontLoaded == false){
		if (!font.loadFromFile("dynasty.ttf"))
			return 0.f;
		fontLoaded = true;
	}
	char str[nbChar + 1];
	for (int i = 0; i < nbChar; i++){
		str[i] = 'M';
	}
	str[nbChar] = '\0';
	
	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(str);
	// set the character size
	text.setCharacterSize(police);
	
	sf::FloatRect fr = text.getLocalBounds();
	float largeurTexte = fr.width;
	return largeurTexte;
}

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
	rectangle.setFillColor(color);
	window->draw(rectangle);
}

void Fenetre::drawCircle(int x, int y, int rayon, sf::Color color){
	sf::CircleShape shape(rayon);
    shape.setFillColor(color);
    x -= rayon;
    y -= rayon;
    shape.setPosition(sf::Vector2f(x,y));
	window->draw(shape);
}

bool Fenetre::drawSprite(int x, int y, int Xsize, int Ysize, const char* file){
	sf::Texture texture;
	string str = "Textures/";
	str.append(file);

	if (!texture.loadFromFile(str)){
		return false;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sprite.setTextureRect(sf::IntRect(0, 0, Xsize, Ysize));
	
	sprite.setPosition(sf::Vector2f(x,y));

	window->draw(sprite);
	return true;
}

sf::Vector2f Fenetre::wait_clic(){
	bool encore = true;
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	printf("En attente de clic GAUCHE ... %4d %4d\r",mousePos.x, mousePos.y); fflush(stdout);
	sf::Event event;
	while(encore && window->waitEvent(event)){
		if(event.type == sf::Event::Closed)
			close();
		if (event.type == sf::Event::MouseMoved){
			mousePos = sf::Mouse::getPosition(*window);
			printf("En attente de clic GAUCHE ... %4d %4d\r",mousePos.x, mousePos.y); fflush(stdout);
		}
		if (event.type == sf::Event::MouseButtonPressed){
			if (event.mouseButton.button == sf::Mouse::Left){
				mousePos = sf::Mouse::getPosition(*window);
				encore = false;
			}
		}
	}
	printf("Clic GAUCHE en %4d %4d               \n",mousePos.x, mousePos.y); fflush(stdout);
	return sf::Vector2f(mousePos.x,mousePos.y);
}
