#ifndef Entity_h
#define Entity_h

#include "Point.h"

class Entity{
	protected :
		int vie;
		Point pos;
		int vision;
		int degatArme;
		
	public :
		static const int top;
		static const int left;
		static const int right;
		static const int bottom;
		Entity();
		~Entity();
		Entity(int x, int y);
		Entity(int x, int y, int vision);
		bool degats(int); //infliger des degats au personnage
		int getVision();
		void setVision(int degre);
		void tourneVision(int degre); //pour tourner la tete a un certain degré
		Point& getPoint();
		void setPoint(int x, int y);
		void deplace(int x, int y);
		int getVie();
		
};

#endif //Entity_h
