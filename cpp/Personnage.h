#ifndef Personnage_h
#define Personnage_h

#include "Point.h"

class Personnage{
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
		Personnage();
		~Personnage();
		Personnage(int x, int y);
		Personnage(int x, int y, int vision);
		bool degats(int); //infliger des degats au personnage
		int getVision();
		void setVision(int degre);
		void tourneVision(int degre); //pour tourner la tete a un certain degré
		Point& getPoint();
		void setPoint(int x, int y);
		void deplace(int x, int y);
		int getVie();
		
};

#endif //Personnage_h
