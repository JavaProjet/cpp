#ifndef Carte_h
#define Carte_h

#define arbre 1

#include "entity/Entity.h"
#include "entity/arbre.h"
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
		bool ajoutEntity(int x, int y, int entity);
		
};

#endif //Carte_h
