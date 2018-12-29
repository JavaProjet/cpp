#include "Carte.h"
#include <iostream>
#include "entity/Collision.h"

using namespace std;

sf::Texture texture; //pour garder la texture en mémoire sinon sprite devient invalide
sf::Sprite sprite; //variable contenant un sprite de 1px, pour tester si le clic est dans un autre sprite
bool initialised = false; //pour initialiser le sprite si ce n'est pas fais

Carte::Carte(const char* name) : jb(20,20,100,true), jr(60,20,100,false){
	nom = NULL;
}

Carte::Carte(int largeur, int hauteur) : jb(20,20,100,true), jr(60,20,100,false){
	nom = NULL;
	this->largeur = largeur;
	this->hauteur = hauteur;
}

Carte::~Carte(){
	if(nom) delete nom, nom = NULL;
	
	 for (Entity* v : entity){
		 if(v) delete v;
	 }
	 entity.clear();
}

void Carte::draw(Fenetre& w){
	for (unsigned int i = 0; i < entity.size(); i++){
		entity[i]->draw(w);
	}
	jb.draw(w);
	jr.draw(w);
}

void Carte::drawIfIn(Fenetre& w, sf::Vector2i min, sf::Vector2i max){
	sf::Vector2i point;
	for (unsigned int i = 0; i < entity.size(); i++){
		if(jb.getPosition().x > min.x && jb.getPosition().x < max.x && jb.getPosition().y > min.y && jb.getPosition().y < max.y){
			point.x = entity[i]->getPosition().x - min.x;
			point.y = entity[i]->getPosition().y - min.y;
			entity[i]->drawAt(w, point);
		}
	}
	if(jb.getPosition().x > min.x && jb.getPosition().x < max.x && jb.getPosition().y > min.y && jb.getPosition().y < max.y){
		point.x = jb.getPosition().x - min.x;
		point.y = jb.getPosition().y - min.y;
		jb.draw(w);
	}
	if(jr.getPosition().x > min.x && jr.getPosition().x < max.x && jr.getPosition().y > min.y && jr.getPosition().y < max.y){
		point.x = jr.getPosition().x - min.x;
		point.y = jr.getPosition().y - min.y;
		jr.draw(w);
	}
}

void Carte::drawAroundJoueur(Fenetre& w){
	
}

bool Carte::ajoutEntity(int x, int y, int size, int entity){
	Entity* ent = NULL;
	
	if(entity == arbre) {
		if(size == petit)
			ent = new Arbre(x,y,40,100);
		else if (size == moyen)
			ent = new Arbre(x,y,60,100);
		else if (size == grand)
			ent = new Arbre(x,y,85,100);
	}
	else if(entity == cactus) {
		if(size == petit)
			ent = new Cactus(x,y,20,100);
		else if (size == moyen)
			ent = new Cactus(x,y,30,100);
		else if (size == grand)
			ent = new Cactus(x,y,40,100);
	}
	else if(entity == rocher) {
		if(size == petit)
			ent = new Rocher(x,y,20,100);
		else if (size == moyen)
			ent = new Rocher(x,y,50,100);
		else if (size == grand)
			ent = new Rocher(x,y,80,100);
		
		
	}
	else if(entity == tronc) {
		if(size == petit)
			ent = new Tronc(x,y,50,25,100);
		else if (size == moyen)
			ent = new Tronc(x,y,80,40,100);
		else if (size == grand)
			ent = new Tronc(x,y,120,60,100);
	}
	
	else if(entity == mur) {
		if(size == petit)
			ent = new Mur(x,y,50,10,100);
		else if (size == moyen)
			ent = new Mur(x,y,100,20,100);
		else if (size == grand)
			ent = new Mur(x,y,160,30,100);
	}
	
	if(ent != NULL) {
		this->entity.push_back(ent);
		return true;
	}
	else return false;
}

void initialise(){ //initialise le sprite de 1px
	if (!texture.loadFromFile("Textures/Somb_red_1px.png")){
		cout << "unable to load texture Textures/Somb_red_1px.png" << endl;
	}
	else {
		sprite.setTexture(texture);
	}
	initialised = true;
}

void Carte::deleteEntity(int x, int y){
	if(!initialised) initialise();
	sprite.setPosition(sf::Vector2f(x, y));
	
	bool sup = false;
	for (unsigned int i = 0; i < entity.size() && !sup; i++){
		if(Collision::BoundingBoxTest(sprite,entity[i]->getSprite())){
			this->deleteEntity(i);
			sup = true;
		}
	}
}

void Carte::deleteEntity(int i){
	vector <Entity*> tmp;
	Entity* toSupp = NULL;
	unsigned int j;
	for(j = 0; j < (unsigned)i; j++){
		tmp.push_back(entity[j]);
	}
	toSupp = entity[j++];
	for(; j < entity.size(); j++){
		tmp.push_back(entity[j]);
	}
	delete toSupp;
	entity.clear();
	for(j = 0; j < tmp.size(); j++){
		entity.push_back(tmp[j]);
	}
	tmp.clear();
}

int Carte::collisionEntity(sf::Sprite& s){
	int i;
	for (i = 0; (unsigned)i < entity.size(); i++){
		if(Collision::PixelPerfectTest(s, entity[i]->getSprite(),127))
			return i;
	}
	return -1;
}

bool Carte::collisionJoueur(sf::Sprite& s, bool bleu){
	if(bleu){
		if(Collision::PixelPerfectTest(s, jb.getSprite(),127)) return true;
	}
	else {
		if(Collision::PixelPerfectTest(s, jr.getSprite(),127)) return true;
	}
	return false;
}

Joueur& Carte::getJoueurBleu(){
	return jb;
}

Joueur& Carte::getJoueurRouge(){
	return jr;
}
