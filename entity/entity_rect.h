#ifndef Entity_rect_h
#define Entity_rect_h

#include "Entity.h"

class Entity_rect : public Entity{
	private :
		sf::Vector2i size;
	public :
		Entity_rect();
		~Entity_rect();
		Entity_rect(int x, int y,int sizeX,int sizeY,  int vie);
		virtual sf::Vector2i &get_size();
		
};

#endif // Entity_rect
