#ifndef Rocher_h
#define Rocher_h

#include "entity_ronde.h"

class Rocher : public Entity_ronde{
	private :
		
	public :
	Rocher(int x, int y, int rayon, int vie);
	~Rocher();
};

#endif // Rocher_h