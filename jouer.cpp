#include "jouer.h"
#include "fenetre.h"
#include "Carte.h"
#include "entity/Joueur.h"

#define Jb c.getJoueurBleu()
#define Jr c.getJoueurRouge()

void affiche(){
    Fenetre window(600,500,"Menu");
       
    Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	c.ajoutEntity(200,100,moyen,rocher);
	c.ajoutEntity(200,200,petit,rocher);
	int x = 0, y = 0;
	
	int move = 1;
	sf::Event event;	
    while (window.isOpen()){
		while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
				window.close();
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Left){
					 x = x - move;
					 		
				 }		
				if(event.key.code == sf::Keyboard::Right) x = x + move;				
				if(event.key.code == sf::Keyboard::Up) y = y - move;
				if(event.key.code == sf::Keyboard::Down) y = y + move;
				if(event.key.code == sf::Keyboard::A)move++;
				if(move > 0 && event.key.code == sf::Keyboard::Q)move--;	
			}	
		}
		Jb.setPosition(x, y);
	
        window.drawSprite(0,0,600,500,"Sol_600x500.png");
		c.draw(window);
        
        window.getWindow().display();
    }
    
}
