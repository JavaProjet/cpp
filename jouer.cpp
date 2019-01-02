#include "jouer.h"
#include "fenetre.h"
#include "Carte.h"
#include "entity/Joueur.h"
#include <math.h>
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;

#define Jb c.getJoueurBleu()
#define Jr c.getJoueurRouge()

#define PI 3.14159265

//vie

void JoueurVie (Fenetre& w,int J_vie){
	sf::RectangleShape rectangle (sf::Vector2f(2*J_vie, 4));
	rectangle.setFillColor(sf::Color(0, 70, 33));
	rectangle.setPosition(10,10);
	w.getWindow().draw(rectangle);
}



typedef struct {
	bool up;
	bool down;
	bool left;
	bool right;
} Key;

sf::Keyboard::Key get_key(Fenetre& window, Key& k){
	sf::Event event;
	while (window.getWindow().pollEvent(event)){
		if (event.type == sf::Event::Closed){
			window.close();
		}
		if(event.type == sf::Event::KeyPressed){
			if(event.key.code == sf::Keyboard::Left)
				k.left = true;
			else if(event.key.code == sf::Keyboard::Right)
				k.right = true;
			else if(event.key.code == sf::Keyboard::Up)
				k.up = true;
			else if(event.key.code == sf::Keyboard::Down)
				k.down = true;
			else return event.key.code;
		}
		
		if(event.type == sf::Event::KeyReleased){
			if(event.key.code == sf::Keyboard::Left)
				k.left = false;
			else if(event.key.code == sf::Keyboard::Right)
				k.right = false;
			else if(event.key.code == sf::Keyboard::Up)
				k.up = false;
			else if(event.key.code == sf::Keyboard::Down)
				k.down = false;
		}
	}
	return sf::Keyboard::Unknown;
}

void gestion_touches(Key& k, sf::Keyboard::Key touche, Carte& c, Joueur& J, int move, int& cptMove, bool avancer){
	double Cos, Sin;
	int res;
	
	int rotation = J.getRotation();
	if(k.down){
		rotation += 180;
		if(rotation > 360) rotation -= 360;
	}
	
	Cos = cos(rotation * PI / 180) * 5;
	Sin = sin(rotation * PI / 180) * 5;
	
	int x = J.getPosition().x, y = J.getPosition().y;
	
	if(k.left){
		J.setRotation(-move);
	}
	if(k.right){
		J.setRotation(move);
	}
	if(((k.up && !k.down) || (k.down && !k.up)) && avancer){ //une seule des 2 est appuyé sinon le déplacement s'annule
		
		J.setPosition(J.getPosition().x + (int)Cos, J.getPosition().y + (int)Sin);
		if((res = c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){//collision avec un autre sprite
			J.setPosition(x, J.getPosition().y);
			if(c.collisionEntity(J.getSprite()) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
				J.setPosition(J.getPosition().x, y);
				if(c.collisionEntity(J.getSprite()) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
					J.setPosition(x,y);
					if(c.getEntity(res)->getType()== cactus){//collision avec un cactus
						J.degats(1);
						printf("vie du joueur %d \n",J.getVie());
					}
				}
			}
		}
		if(x + Cos - 20 < 0 || x + 20 + Cos > c.getLargeur())
			J.setPosition(x, J.getPosition().y);
		if(y + Sin - 20 < 0 || y + 20 + Sin > c.getHauteur())
			J.setPosition(J.getPosition().x, y);	
	}
	if(touche == sf::Keyboard::Space){
		
	}
	
	if(J.getPosition().x != x || J.getPosition().y != y) cptMove++;
}

void changeJoueur(Fenetre& w, bool bleu){
	w.getWindow().clear();
	string str = "Joueur ";
	(bleu)? str.append("bleu") : str.append("rouge");
	int size = w.getFont(str.c_str(),40);
	w.write(str.c_str(),40,sf::Color::White, (w.getLargeur() - size) / 2, (500 - 40) / 2);
	w.getWindow().display();
	sleep(2);
}

void drawFond(Fenetre& w, Joueur& J, int largeur, int hauteur){
	w.getWindow().clear();
	sf::Vector2i position, beginTo, size; // points pour dessiner en decalé la photo de fond
	
	position.x = w.getLargeur() / 2 - J.getPosition().x;
	beginTo.x = (position.x >= 0)? 0 : -position.x;
	if(position.x < 0) position.x = 0;
	size.x = largeur;
	size.x -= (J.getPosition().x + w.getLargeur() / 2) - largeur;
	
	position.y = w.getHauteur() / 2 - J.getPosition().y;
	beginTo.y = (position.y >= 0)? 0 : -position.y;
	if(position.y < 0) position.y = 0;
	size.y = hauteur;
	size.y -= (J.getPosition().y + w.getHauteur() / 2) - hauteur;
	
	w.drawSprite(position, beginTo, size,"Sol_600x500.png");
}

void affiche(){
	Fenetre window(600,500,"Menu");

	Carte c(600,500);
	c.ajoutEntity(100,100,petit,arbre);
	c.ajoutEntity(200,100,moyen,rocher);
	c.ajoutEntity(200,200,petit,rocher);
	c.ajoutEntity(300,200,petit,cactus);

	int move = 2, moveMax = (window.getLargeur() + window.getHauteur()) / 40 ;
	printf("move max : %d\n", moveMax);
	Key k = {false, false, false, false};
	int cptMove = 0;
	bool bleuJoue = false;
	sf::Keyboard::Key touche;
	
	while (window.isOpen()){
		if(bleuJoue){
			 drawFond(window, Jb, c.getLargeur(), c.getHauteur());
			 JoueurVie(window,Jb.getVie()); //vie du joueur
		 }
		else {
			drawFond(window, Jr, c.getLargeur(), c.getHauteur());
			JoueurVie(window,Jr.getVie());
				
		}
		//window.drawSprite(0,0,600,500,"Sol_600x500.png");
		
		touche = get_key(window, k);
		if(bleuJoue){
			 gestion_touches(k,touche,c,Jb,move, cptMove, /*cptMove < moveMax*/ true);
			 JoueurVie(window,Jb.getVie());
		 }
		else {
			gestion_touches(k,touche,c,Jr,move, cptMove, true);
			JoueurVie(window,Jr.getVie());
		}

		c.drawAroundJoueur(window, bleuJoue);
		//c.draw(window);
		window.getWindow().display();
		if(touche == sf::Keyboard::Escape){
			bleuJoue = !bleuJoue;
			changeJoueur(window,bleuJoue);
			cptMove = 0;
		}
	}
}
