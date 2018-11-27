#ifndef Carte_h
#define Carte_h

#include "Entity"

class Carte{
	private :
		Entity ** tab;
		char *nom;
		int largeur;
		int hauteur;
	public :
		Carte(const char* name);
		Carte(int, int);
		~Carte();
		void allocTab();
		void freeTab();
};

#endif //Carte_h
