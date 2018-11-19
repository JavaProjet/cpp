#ifndef Entity_h
#define Entity_h

#include "Point.h"

class Entity{
	protected :
		int vie;
		Point pos; //point centrale de la hitbox
		int rayon; //taille de la hitbox
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
		bool degats(int); //infliger des degats à l'entité, retourne faux si les points de vies atteignent 0
		int getVision();
		void setVision(int degre); //définir un degré d'orientation à la vision
		void tourneVision(int degre); //pour pivoter la vision d'un certain degré
		Point& getPoint();
		void setPoint(int x, int y);
		void deplace(int x, int y);
		int getVie();
		void setVie(int);
		void setRayon(int);
		int getRayon();
};

#endif //Entity_h
