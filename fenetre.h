#ifndef Fenetre_h
#define Fenetre_h

#include <SFML/Graphics.hpp>

using namespace sf;

class Fenetre{
	private:
		RenderWindow *window;
		int largeur;
		int hauteur;
		
	public:
		Fenetre(int largeur, int hauteur, const char *title);
		~Fenetre();
		void close();
		bool isOpen();
		RenderWindow& getWindow();
		bool write(const char* str, int police, sf::Color color, int x, int y);
};

#endif //Fenetre_h