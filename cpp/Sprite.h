#ifndef Sprite_h
#define Sprite_h

typedef struct{
	int rouge;
	int vert;
	int bleu;
}pixel;

class Sprite{
	private :
		pixel** tab;
		int sizePixel;
		bool allocated;
		void alloc();
		int largeur;
		int hauteur;
		
	public :
		Sprite();
		Sprite(const char* nom_fic);
		~Sprite();
		void loadSprite(const char* nom_fic);
		void setPixel(int x, int y, pixel p);
		pixel getPixel(int x, int y);
		void drawSprite();
		void setSizePixel(int);
		int getSizePixel();
		bool isAllocated();
};

#endif //Sprite_h
