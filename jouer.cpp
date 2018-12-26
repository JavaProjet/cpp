#include "jouer.h"
#include "fenetre.h"
#include "Carte.h"
#include "entity/Joueur.h"

void affiche(){
    Fenetre window(600,500,"Menu");
    window.getWindow().clear(sf::Color(160,62,35));
        
     Carte c(600,500);
	 c.ajoutEntity(100,100,petit,arbre);
	 Joueur Jb = c.getJoueurBleu();
	 int x = 0, y = 0;
	
	 int move = 1;
		
    while (window.isOpen()){
        sf::Event event;
        window.drawSprite(0,0,600,500,"Terre.png");
        c.draw(window);
        
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
				window.close();
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Left) x = x - move;					
				if(event.key.code == sf::Keyboard::Right) x = x + move;				
				if(event.key.code == sf::Keyboard::Up) y = y - move;
				if(event.key.code == sf::Keyboard::Down) y = y + move;
				if(event.key.code == sf::Keyboard::A)move++;
				if(move > 0 && event.key.code == sf::Keyboard::Q)move--;
					
			}
				
				
		}
		printf ("fin x = %d,y = %d\n",x,y);
		Jb.setPosition(x, y);
	
        window.drawSprite(0,0,600,500,"Terre.png");
		c.draw(window);
        
            
        window.getWindow().display();
    }
    
}
