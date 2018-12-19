#ifndef Entity_rect_h
#define Entity_rect_h

#include "Entity.h"

class Entity_rect : public Entity{
	protected :
		sf::Vector2i size;
	public :
		Entity_rect();
		virtual ~Entity_rect();
		Entity_rect(int x, int y,int sizeX,int sizeY,  int vie);
		sf::Vector2i &get_size();
		void draw(Fenetre &w);
		
};

#endif // Entity_rect
