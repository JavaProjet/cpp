#include "Sprite.h"
#include <iostream>

using namespace std;

void Sprite::alloc(){
	tab = new pixel* [largeur] ();
	for (int i = 0; i < largeur; i++){
		tab[i] = new pixel[hauteur] ();
	}
	cout << "allocation du tableau de pixel";
	printf("\ttab : %p\n", tab);
}

Sprite::Sprite(){
	tab = NULL;
	largeur = 0;
	hauteur = 0;
}

Sprite::Sprite(const char* nom_fic){
	tab = NULL;
	loadSprite(nom_fic);
}

Sprite::~Sprite(){
	if(tab){
		for (int i = 0; i < hauteur; i++){
			delete[] tab[i];
		}
		delete[] tab;
		cout << "mémoire du tableau libéré";
		printf("\ttab : %p\n", tab);
	}
}

void Sprite::loadSprite(const char* nom_fic) {
	if(tab) {
		delete this;
		tab = NULL;
	}
	largeur = 100;
	hauteur = 100;
	alloc();
}

void Sprite::setPixel(int x, int y, pixel p){
	tab[x][y] = p;
}

pixel Sprite::getPixel(int x, int y){
	return tab[x][y];
}

void Sprite::drawSprite(){
	
}

void Sprite::setSizePixel(int size){
	sizePixel = size;
}

int Sprite::getSizePixel(){
	return sizePixel;
}

bool Sprite::isAllocated(){
	return !(tab == NULL);
}
