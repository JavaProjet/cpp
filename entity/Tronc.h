#ifndef Tronc_h
#define Tronc_h

#include "entity_rect.h"

class Tronc : public Entity_rect{
	private :
		
	public :
	Tronc(int x, int y, int sizeX,int sizeY, int vie);
	virtual ~Tronc();
	virtual int getType();
};

#endif // Tronc_h
