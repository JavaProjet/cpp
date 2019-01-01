#ifndef Carte_h
#define Carte_h

#define petit 1
#define moyen 2
#define grand 3

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
		void draw(Fenetre& w);
		void drawIfIn(Fenetre& w, sf::Vector2i min, sf::Vector2i max);
		void drawAroundJoueur(Fenetre& w, bool bleu);
		bool ajoutEntity(int x, int y,int size, entityType entity);
		void deleteEntity(int x, int y);
		void deleteEntity(int i);
		
		// indique la position de l'element dans le vecteur en collision avec le sprite en parametre -1 sinon 
		int collisionEntity(sf::Sprite& s);
		bool collisionJoueur(sf::Sprite& s, bool bleu);
		Joueur& getJoueurBleu();
		Joueur& getJoueurRouge();
		Entity* getEntity(int i);
		int getLargeur();
		int getHauteur();
		bool obstacle_entre_joueurs();
};

#endif //Carte_h
