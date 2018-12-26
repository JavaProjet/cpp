#ifndef Joueur_h
#define Joueur_h

#include "entity_ronde.h"

class Joueur : public Entity_ronde{
	private :

	public :
	Joueur(int x, int y, int vie, bool bleu);
	virtual ~Joueur();
	virtual void draw(Fenetre& w);
	
};

#endif // Joueur_h
