#ifndef input_h
#define input_h

#include "fenetre.h"
#include <iostream>
#include <string>

using namespace std;

class Input{
    private :
        char* str;
        int id;
        static int nbInstance;
        static int nbInstanceActif;
        static sf::Vector2i clic;
        static int focus;
        sf::Vector2i posInput;
        int sizeText; //sizeY
        int sizeX;
        int maxChar;
        Fenetre *w;
        int cursor;
    public :
        Input(Fenetre* w, sf::Vector2i posInput, int sizeText, int maxChar);
        ~Input();
        char* getString();
        void drawInput();
        static sf::Vector2i get_clic(Fenetre& w);
};


#endif //input_h
