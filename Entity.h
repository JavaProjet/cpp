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


exo7:
(defun my_eq(x y)
	(if(and(atom x)(atom y))
	        (if(eq x y)t
				(string=x y))
				(eq y))
(defun equal (l1 l2)
	(cond((or(atom l1)(atome l2))(my_eq (l1 l2)))
		((eq l1 l2) t)
		(t(and(my_equal(cdr l2)(car l2))
			   (my_equal(cdr l1)(car l1))))
		(my_equal 2 '(2))=nil))








#endif //Entity_h
