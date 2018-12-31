#include "jouer.h"
#include "fenetre.h"
#include "Carte.h"
#include "entity/Joueur.h"
#include <math.h>

#define Jb c.getJoueurBleu()
#define Jr c.getJoueurRouge()

#define PI 3.14159265

typedef struct {
	bool up;
	bool down;
	bool left;
	bool right;
} Key;

void get_key(Fenetre& window, Key& k){
	sf::Event event;
	while (window.getWindow().pollEvent(event)){
		if (event.type == sf::Event::Closed){
			window.close();
		}
		if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Left)
				k.left = true;
			if(event.key.code == sf::Keyboard::Right)
				k.right = true;
			if(event.key.code == sf::Keyboard::Up)
				k.up = true;
			if(event.key.code == sf::Keyboard::Down)
				k.down = true;
		}
		
		if(event.type == sf::Event::KeyReleased){
			if(event.key.code == sf::Keyboard::Left)
				k.left = false;
			if(event.key.code == sf::Keyboard::Right)
				k.right = false;
			if(event.key.code == sf::Keyboard::Up)
				k.up = false;
			if(event.key.code == sf::Keyboard::Down)
				k.down = false;
		}
	}
}

void gestion_touches(Key& k, Carte& c, Joueur& J, int move){
	double Cos = cos(J.getRotation() * PI / 180) * 10;
	double Sin = sin(J.getRotation() * PI / 180) * 10;
	if(k.down) Cos *= -1.0, Sin *= -1.0;
	int x = J.getPosition().x, y = J.getPosition().y;
	
	if(k.left){
		J.setRotation(-move);
	}
	if(k.right){
		J.setRotation(move);
	}
	if((k.up && !k.down) || (k.down && !k.up)){ //une seule des 2 est appuyé sinon le déplacement s'annule
		if(x + Cos > 0 && x + 40 + Cos < c.getLargeur() && y + Sin > 0 && y + 40 + Sin < c.getHauteur())
			J.setPosition(x + Cos, y + Sin);
		
		if(c.collisionEntity(J.getSprite()) != -1 || c.collisionJoueur(Jr.getSprite(), true))//collision avec un autre sprite
			J.setPosition(x,y);//on annule le deplacement	
	}
}

void affiche(){
    Fenetre window(600,500,"Menu");
       
    Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	c.ajoutEntity(200,100,moyen,rocher);
	c.ajoutEntity(200,200,petit,rocher);
	Jr.setPosition(400,400);
	
	int move = 2;
	Key k = {false, false, false, false};
		
    while (window.isOpen()){
        window.drawSprite(0,0,600,500,"Sol_600x500.png");
        
        get_key(window, k);
        gestion_touches(k,c,Jb,move);
        
		c.draw(window);
        window.getWindow().display();
    }
    
}
