#ifndef Carte_h
#define Carte_h

#include "Entity"

class Carte{
	private :
		Entity ** tab;
		char *nom;
		int largeur;
		int hauteur;
		
		void allocTab();
		void freeTab();
	public :
		Carte(const char* name);
		Carte(int, int);
		~Carte();
		
};

#endif //Carte_h
