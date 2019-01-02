#include "Carte.h"
#include <iostream>
#include "entity/Collision.h"
#include <string.h>
#include <string>
using namespace std;

sf::Texture texture; //pour garder la texture en mémoire sinon sprite devient invalide
sf::Sprite sprite; //variable contenant un sprite de 1px, pour tester si le clic est dans un autre sprite
bool initialised = false; //pour initialiser le sprite si ce n'est pas fais

Carte::Carte(const char* name, bool with_joueurs) : jb(-100,20,100,true), jr(-100,20,100,false){
	if(name){
		//fonction de lecture
		/*en attendant, les infos sont pré-remplis, il faudra les supprimer*/
		
		/////////////////////
		
		if(with_joueurs){
			srand(time(NULL));
			do{
				jb.setPosition(rand()%(largeur - 41) + 1, rand()%(hauteur - 41) + 1);
			}while(collisionEntity(jb.getSprite()) != -1 || collisionJoueur(jb.getSprite(), false));
			
			do{
				jr.setPosition(rand()%(largeur - 41) + 1, rand()%(hauteur - 41) + 1);
			}while(collisionEntity(jr.getSprite()) != -1 || collisionJoueur(jr.getSprite(), true));
		}
	}
}

Carte::Carte(int largeur, int hauteur) : jb(-100,20,100,true), jr(-100,20,100,false){
	nom = NULL;
	setNom("sans titre");
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
	obstacle_entre_joueurs(w);
	jb.draw(w);
	jr.draw(w);
}

//dessine si c'est compris entre min et max, en decalant les positions pour afficher dans la fenetre si les coordonnées sont superieurs a la taille de la fenetre
void Carte::drawIfIn(Fenetre& w, sf::Vector2i min, sf::Vector2i max){
	sf::Vector2i point;
	for (unsigned int i = 0; i < entity.size(); i++){
		if(entity[i]->getPosition().x + jr.get_rayon() * 2 > min.x && entity[i]->getPosition().x < max.x && entity[i]->getPosition().y + jr.get_rayon() * 2 > min.y && entity[i]->getPosition().y < max.y){
			point.x = entity[i]->getPosition().x - min.x;
			point.y = entity[i]->getPosition().y - min.y;
			entity[i]->drawAt(w, point);
		}
	}
	if(jb.getPosition().x + jr.get_rayon() * 2 > min.x && jb.getPosition().x < max.x && jb.getPosition().y + jr.get_rayon() * 2 > min.y && jb.getPosition().y < max.y){
		point.x = jb.getPosition().x - min.x;
		point.y = jb.getPosition().y - min.y;
		jb.drawAt(w, point);
	}
	if(jr.getPosition().x + jr.get_rayon() * 2 > min.x && jr.getPosition().x < max.x && jr.getPosition().y + jr.get_rayon() * 2 > min.y && jr.getPosition().y < max.y){
		point.x = jr.getPosition().x - min.x;
		point.y = jr.getPosition().y - min.y;
		jr.drawAt(w, point);
	}
}

void Carte::drawAroundJoueur(Fenetre& w, bool bleu){
	sf::Vector2i point, min, max;
	Entity_ronde* e_ronde;
	Entity_rect* e_rect;
	
	if(bleu){ //on dessine en decalé en mettant le joueur bleu au centre de la fenetre
		min.x = jb.getPosition().x + jb.get_rayon() - w.getLargeur() / 2;
		min.y = jb.getPosition().y + jb.get_rayon() - w.getHauteur() / 2;
		max.x = min.x + w.getLargeur();
		max.y = min.y + w.getHauteur();
	}
	
	else { //on dessine en decalé en mettant le joueur rouge au centre de la fenetre
		min.x = jr.getPosition().x + jb.get_rayon() - w.getLargeur() / 2;
		min.y = jr.getPosition().y + jb.get_rayon() - w.getHauteur() / 2;
		max.x = min.x + w.getLargeur();
		max.y = min.y + w.getHauteur();
	}
	
	for (unsigned int i = 0; i < entity.size(); i++){ //on dessine les entités qui sont autour
		if(entity[i]->getPrimaryType() == ronde){
			e_ronde = (Entity_ronde*)entity[i];
			if(e_ronde->getPosition().x + e_ronde->get_rayon() * 2 > min.x && e_ronde->getPosition().x < max.x && e_ronde->getPosition().y + e_ronde->get_rayon() * 2 > min.y && e_ronde->getPosition().y < max.y){
				point.x = entity[i]->getPosition().x - min.x;
				point.y = entity[i]->getPosition().y - min.y;
				entity[i]->drawAt(w, point);
			}
		}
		else if(entity[i]->getPrimaryType() == rect){
			e_rect = (Entity_rect*)entity[i];
			if(e_rect->getPosition().x + e_rect->get_size().x > min.x && e_rect->getPosition().x < max.x && e_rect->getPosition().y + e_rect->get_size().y > min.y && e_rect->getPosition().y < max.y){
				point.x = entity[i]->getPosition().x - min.x;
				point.y = entity[i]->getPosition().y - min.y;
				entity[i]->drawAt(w, point);
			}
		}
	}
	if(bleu){ //on dessine le joueur bleu, et s'il n'y a pas d'obstacle entre les deux joueurs, on dessine le rouge s'il est aux alentours
		point.x = jb.getPosition().x - min.x;
		point.y = jb.getPosition().y - min.y;
		jb.drawAt(w, point);
		if(jr.getPosition().x + jr.get_rayon() * 2 > min.x && jr.getPosition().x < max.x && jr.getPosition().y + jr.get_rayon() * 2 > min.y && jr.getPosition().y < max.y){
			if(obstacle_entre_joueurs(w) == false){
				point.x = jr.getPosition().x - min.x;
				point.y = jr.getPosition().y - min.y;
				jr.drawAt(w, point);
			}
		}
	}
	
	else { //on dessine le joueur rouge, et s'il n'y a pas d'obstacle entre les deux joueurs, on dessine le bleu s'il est aux alentours
		point.x = jr.getPosition().x - min.x;
		point.y = jr.getPosition().y - min.y;
		jr.drawAt(w, point);
		if(jb.getPosition().x + jr.get_rayon() * 2 > min.x && jb.getPosition().x < max.x && jb.getPosition().y + jr.get_rayon() * 2 > min.y && jb.getPosition().y < max.y){
			if(obstacle_entre_joueurs(w) == false){
				point.x = jb.getPosition().x - min.x;
				point.y = jb.getPosition().y - min.y;
				jb.drawAt(w, point);
			}
		}
	}
}

bool Carte::ajoutEntity(int x, int y, int size, entityType entity){
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
	if (!texture.loadFromFile("Textures/pixel_rouge.png")){
		cout << "unable to load texture Textures/pixel_rouge.png" << endl;
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
		//if(Collision::PixelPerfectTest(sprite,entity[i]->getSprite(),127)){
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
		if(Collision::PixelPerfectTest(s, entity[i]->getSprite(),126))
		//if(Collision::BoundingBoxTest(s, entity[i]->getSprite()))
			return i;
	}
	return -1;
}

bool Carte::collisionJoueur(sf::Sprite& s, bool bleu){
	if(bleu){
		if(Collision::PixelPerfectTest(s, jb.getSprite(),126)) return true;
	}
	else {
		if(Collision::PixelPerfectTest(s, jr.getSprite(),126)) return true;
	}
	return false;
}

Joueur& Carte::getJoueurBleu(){
	return jb;
}

Joueur& Carte::getJoueurRouge(){
	return jr;
}

Entity* Carte::getEntity(int i){
	return entity[i];
}

int Carte::getLargeur(){
	return largeur;
}

int Carte::getHauteur(){
	return hauteur;
}

char* Carte::getNom(){
	return nom ;
}

void Carte::setNom(const char* name){
	int taille = (name != NULL)? strlen(name) : 0;
	if(taille > 0){
		delete[] nom;
		nom = new char [taille+1];
		
		if(name != NULL){
			for (int i = 0; i <= taille; i++)
				nom[i] = name[i] ;
		}
	}
}

//fonction qui calcul une ligne entre les 2 points et teste si une entité la croise, fonction draw_line de fenetre.cpp/.h (uvsqgraphics) modifié
//retourne vrai si une entité dans le vecteur la croise et faux si aucune entité croise la ligne
bool Carte::obstacle_entre_joueurs(Fenetre& w){
	int xmin, xmax;
	int ymin, ymax;
	int i,j;
	float a,b,ii,jj;
	bool obstacle = false;
	
	sf::Vector2i p1 = jb.getPosition(), p2 = jr.getPosition();
	p1.x += jb.get_rayon(); p1.y += jb.get_rayon();
	p2.x += jr.get_rayon(); p2.y += jr.get_rayon();
	
	if(!initialised) initialise();
	
	if (p1.x < p2.x) {xmin=p1.x; xmax=p2.x;} else{xmin=p2.x; xmax=p1.x;}
	if (p1.y < p2.y) {ymin=p1.y; ymax=p2.y;} else{ymin=p2.y; ymax=p1.y;}
	
	// La variation la plus grande est en x
	if ((xmax-xmin >= ymax-ymin) && (ymax-ymin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (i=xmin;i<=xmax;i++) {
			jj = a*i+b;
			j = jj;
			if (((jj-j) > 0.5) && (j < hauteur-1)) j++;
			sprite.setPosition(sf::Vector2f(i, j));
			if(collisionEntity(sprite) != -1){
				//w.add_pix(i,j,sf::Color::Red);
				//w.getWindow().draw(sprite);
				obstacle = true;
			}
			//else w.add_pix(i,j,sf::Color::Blue);
		}
	}
	
	// La variation la plus grande est en y
	if ((ymax-ymin > xmax-xmin) && (xmax-xmin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (j=ymin;j<=ymax;j++) {
			ii = (j-b)/a;
			i = ii;
			if (((ii-i) > 0.5) && (i < largeur-1)) i++;
			sprite.setPosition(sf::Vector2f(i, j));
			if(collisionEntity(sprite) != -1){
				//w.add_pix(i,j,sf::Color::Red);
				//w.getWindow().draw(sprite);
				obstacle = true;
			}
			//else w.add_pix(i,j,sf::Color::Blue);
		}
	}
	return obstacle;
}

void Carte::save(){
	FILE* fs = NULL ;
	system("mkdir Saves");
	string str = "Saves/";
	str.append(nom);
	str.append(".carte");
	if ( ( fs = fopen (str.c_str(),"w+") )){
		fprintf( fs, "%d %d\n",largeur, hauteur );
		fprintf( fs,"\n");
		for (unsigned int i = 0; i < entity.size(); i++){
			entity[i]->save(fs);
			fprintf( fs,"\n");
		}
		fclose (fs);
	} 
}

