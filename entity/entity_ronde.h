#ifndef Entity_ronde_h
#define Entity_ronde_h

#include "Entity.h"

class Entity_ronde : public Entity{
	private :
		int rayon;
		sf::Vector2i centre;
	public :
		Entity_ronde();
		~Entity_ronde();
		Entity_ronde(int x, int y, int rayon, int vie);
		virtual int get_rayon();
		
};

#endif // Entity_ronde
