#include "jouer.h"
#include "fenetre.h"
#include "Carte.h"
#include "entity/Joueur.h"
#include <math.h>

#define Jb c.getJoueurBleu()
#define Jr c.getJoueurRouge()

#define PI 3.14159265

void affiche(){
    Fenetre window(600,500,"Menu");
       
    Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	c.ajoutEntity(200,100,moyen,rocher);
	c.ajoutEntity(200,200,petit,rocher);
	int x = Jb.getPosition().x, y = Jb.getPosition().y;
	int move = 2;
	sf::Event event;	
    while (window.isOpen()){
		while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
				window.close();
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Left){
					Jb.setRotation(-move);
				 }		
				 
				if(event.key.code == sf::Keyboard::Right){
					Jb.setRotation(move);
				}
								
				if(event.key.code == sf::Keyboard::Up) {
					x += cos(Jb.getRotation() * PI / 180) * 10;
					y += sin(Jb.getRotation() * PI / 180) * 10;
					Jb.setPosition(x, y);
				}
				if(event.key.code == sf::Keyboard::Down) {
					x -= cos(Jb.getRotation() * PI / 180)* 10;
					y -= sin(Jb.getRotation() * PI / 180)* 10;
					Jb.setPosition(x, y);
				}
				if(event.key.code == sf::Keyboard::A)move++;
				if(move > 0 && event.key.code == sf::Keyboard::Q)move--;	
			}	
		}
		
		
	
        window.drawSprite(0,0,600,500,"Sol_600x500.png");
		//Jb.draw(Jb,t);
		c.draw(window);
        
		printf("degré de rotation : %f, cos : %6f, sin : %6f\r",Jb.getRotation(),cos(Jb.getRotation() * PI / 180),sin(Jb.getRotation() * PI / 180));
        window.getWindow().display();
    }
    
}
