#include "jouer.h"
#include "fenetre.h"

void affiche(){
    Fenetre window(600,500,"Menu");

    while (window.isOpen()){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        
		window.drawSprite(10,10,40, 40,"Arbre2.png");
        window.drawSprite(60,10,40,40,"Som_bleu2.png");
        window.drawSprite(110,10,40,40,"Som_red2.png");
        window.drawSprite(160,10,40,40,"cac2.png");
        window.drawSprite(210,10,40,40,"T-rocher2.png");
        window.drawSprite(260,10,60,40,"tronc2.png");
        
        window.getWindow().display();
    }
}