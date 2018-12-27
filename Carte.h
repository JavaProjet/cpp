#ifndef Carte_h
#define Carte_h

#define petit 1
#define moyen 2
#define grand 3

#define arbre 1
#define cactus 2
#define rocher 3
#define tronc 4
#define mur 5
#define joueurBleu 6
#define joueurRouge 7

#include "entity/Entity.h"
#include "entity/arbre.h"
#include "entity/Cactus.h"
#include "entity/Rocher.h"
#include "entity/Tronc.h"
#include "entity/Mur.h"
#include "entity/Joueur.h"
#include "fenetre.h"

using namespace std;

class Carte{
	private :
		vector <Entity*> entity;
		Joueur jb, jr;
		char *nom;
		int largeur;
		int hauteur;
		void allocTab();
		void freeTab();
	public :
		Carte(const char* name);
		Carte(int, int);
		~Carte();
		virtual void draw(Fenetre& w);
		bool ajoutEntity(int x, int y,int size, int entity);
		void deleteEntity(int x, int y);
		void deleteEntity(int i);
		
		// indique la position de l'element dans le vecteur en collision avec le sprite en parametre -1 sinon 
		int collisionEntity(sf::Sprite& s);
		
		Joueur& getJoueurBleu();
		Joueur& getJoueurRouge();
};

#endif //Carte_h
