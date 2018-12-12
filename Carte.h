#ifndef Carte_h
#define Carte_h

#define petit 20

#define arbre 1
#define cactus 2
#define rocher 3
#define tronc 4
#define joueur_b 5
#define joueur_r 6

#include "entity/Entity.h"
#include "entity/arbre.h"
#include "entity/Cactus.h"
#include "entity/Rocher.h"
#include "entity/Tronc.h"
#include "entity/Joueur.h"
#include "fenetre.h"

using namespace std;

class Carte{
	private :
		vector <Entity*> entity;
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
		bool ajoutEntity(int x, int y,int size, int entity);
		
};

#endif //Carte_h
