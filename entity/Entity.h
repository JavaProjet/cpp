#ifndef Entity_h
#define Entity_h

#include "../fenetre.h"

class Entity{
	protected :
		int vie;
		sf::Vector2i position;
		char* texture;
		//int vision;
		//int degatArme;
		
	public :
		/*static const int top;
		static const int left;
		static const int right;
		static const int bottom;*/
		Entity();
		~Entity();
		Entity(int x, int y);
		bool degats(int); //infliger des degats à l'entité, retourne faux si les points de vies atteignent 0
		void set_texture(const char* name);
		void draw(Fenetre& w);
		//int getVision();
		//void setVision(int degre); //définir un degré d'orientation à la vision
		//void tourneVision(int degre); //pour pivoter la vision d'un certain degré
		sf::Vector2i& getPosition();
		void deplace(int x, int y);
		int getVie();
		void setVie(int);
};

#endif //Entity_h
