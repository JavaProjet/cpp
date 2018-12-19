#ifndef Cactus_h
#define Cactus_h

#include "entity_ronde.h"

class Cactus : public Entity_ronde{
	private :
		
	public :
	Cactus(int x, int y, int rayon, int vie);
	virtual ~Cactus();
};

#endif // Cactus_h
