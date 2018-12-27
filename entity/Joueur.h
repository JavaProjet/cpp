#ifndef Joueur_h
#define Joueur_h

#include "entity_ronde.h"

class Joueur : public Entity_ronde{
	private :
	sf::RectangleShape rectangle;
	public :
	Joueur(int x, int y, int vie, bool bleu);
	virtual ~Joueur();
	virtual void draw(Fenetre& w);
	virtual void setPosition(int x, int y);
	void setRotation (int i);
};

#endif // Joueur_h
