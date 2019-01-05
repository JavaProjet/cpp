#include "jouer.h"
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
	w.draw_fillRect(10,10,2*J_vie, 4, sf::Color(0, 70, 33));
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

void gestion_touches(Key& k, sf::Keyboard::Key touche, Carte& c, Joueur& J, bool bleu, int move, int& cptMove, bool avancer, Fenetre & w){
	double Cos, Sin;
	int res[3];
	//entityType t;
	string str = "";
	
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
		if((res[0] = c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){//collision avec un autre sprite
			J.setPosition(x, y + (int)Sin);
			if((res[1] = c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
				J.setPosition(x + (int)Cos, y);
				if((res[2] = c.collisionEntity(J.getSprite())) != -1 || c.collisionJoueur(Jr.getSprite(), true)){
					J.setPosition(x,y);
				}
			}
		}
		/*for(int i = 0; i < 3; i++){ ca seg fault
			if(res[i] != -1)
				if(c.getEntity(res[i])->getType() == cactus)
					res[i] = -2;
		}
		if(res[0] == -2 || res[1] == -2 || res[2] == -2) J.degats(1);*/
		
		if(x + Cos - 20 < 0 || x + 20 + Cos > c.getLargeur())
			J.setPosition(x, J.getPosition().y);
		if(y + Sin - 20 < 0 || y + 20 + Sin > c.getHauteur())
			J.setPosition(J.getPosition().x, y);	
	}
	
	if(touche == sf::Keyboard::Space){
		
		int limite_gauche = J.getRotation() - 45;
		if(limite_gauche < 0) limite_gauche += 360;
		int limite_droite = J.getRotation() + 45;
		if(limite_droite > 360) limite_droite -= 360;		
		Joueur &Adversaire = (bleu) ? Jr : Jb;
		touche = sf::Keyboard::A;
		while(touche != sf::Keyboard::Space){
			
			touche = get_key(w, k);
			
			if(k.left){
				J.setRotation(-move);
				if(J.getRotation() > limite_gauche - move &&  J.getRotation() < limite_gauche){
					J.setRotation(move);
				}
				
			}
			if(k.right){
				J.setRotation(move);
				if(J.getRotation()  > limite_droite &&  J.getRotation() < limite_droite + move){
					J.setRotation(-move);
				}
			}
			if(touche == sf::Keyboard::Space && J.getVie() - J.get_balle().get_dommage() > 0 ){
				
				Cos = cos(J.getRotation() * PI / 180) ;
				Sin = sin(J.getRotation() * PI / 180) ;
				 
				 J.get_balle().setPosition(J.getPosition().x + 20 - 7, J.getPosition().y + 20 - 7);
				 int i,j;
				 
				 J.degats(J.get_balle().get_dommage());
				 for(i=0 ; i < J.get_balle().get_distance()*8 && (j = c.collisionEntity(J.get_balle().getSprite())) == -1 && c.collisionJoueur(J.get_balle().getSprite(), !bleu) == false; i++){
					sleep(0.01);
					J.get_balle().setPosition(J.get_balle().getPosition().x + Cos * 2 , J.get_balle().getPosition().y + Sin * 2 );
					w.drawSprite(0,0,600,500,"Sol_600x500.png");
					J.get_balle().draw(w);
					c.draw(w);
					w.getWindow().display();
					
				 }
				 
				 if(j != -1){
					if(c.getEntity(j)->degats(J.get_balle().get_dommage())==false)c.deleteEntity(j);
				}
				else if(c.collisionJoueur(J.get_balle().getSprite(), !bleu)){
					Adversaire.degats(Adversaire.getVie());
				}
				
				 
			}
			w.drawSprite(0,0,600,500,"Sol_600x500.png");
			c.draw(w);
			w.getWindow().display();
			
			
		}
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

void fin(Fenetre& w, Carte& c){
	string str = "";
	if(Jb.getVie() < 1)
		str.append("Victoire pour Joueur rouge");
	else if(Jr.getVie() < 1)
		str.append("Victoire pour Joueur bleu");
	if(Jb.getVie() < 1 || Jr.getVie() < 1){
		sleep(1);
		w.getWindow().clear();
		int size = w.getFont(str.c_str(),40);
		w.write(str.c_str(),40,sf::Color::White, (w.getLargeur() - size) / 2, (500 - 40) / 2);
		w.getWindow().display();
		sleep(3);
		w.close();
	}
}

void affiche(Fenetre& window){

	Carte c("tmp", true);
	/*c.ajoutEntity(100,100,petit,arbre);
	c.ajoutEntity(200,100,moyen,rocher);
	c.ajoutEntity(200,200,petit,rocher);
	c.ajoutEntity(300,200,petit,cactus);
*/
	int move = 2, moveMax = (window.getLargeur() + window.getHauteur()) / 40 ;
	printf("move max : %d\n", moveMax);
	Key k = {false, false, false, false};
	int cptMove = 0;
	bool bleuJoue = false;
	sf::Keyboard::Key touche;
	
	while (window.isOpen()){
		/*if(bleuJoue){
			 drawFond(window, Jb, c.getLargeur(), c.getHauteur());
			 JoueurVie(window,Jb.getVie()); //vie du joueur
		 }
		else {
			drawFond(window, Jr, c.getLargeur(), c.getHauteur());
			JoueurVie(window,Jr.getVie());
				
		}*/
		window.drawSprite(0,0,600,500,"Sol_600x500.png");
		
		touche = get_key(window, k);
		if(bleuJoue){
			 gestion_touches(k, touche, c, Jb, true, move, cptMove, /*cptMove < moveMax*/ true, window);
			 JoueurVie(window, Jb.getVie());
		 }
		else {
			gestion_touches(k, touche,c, Jr, false, move, cptMove, true, window);
			JoueurVie(window,Jr.getVie()); 
		}

		//c.drawAroundJoueur(window, bleuJoue);
		c.draw(window);
		window.getWindow().display();
		if(touche == sf::Keyboard::Escape){
			bleuJoue = !bleuJoue;
			changeJoueur(window, bleuJoue);
			cptMove = 0;
		}
		fin(window, c);
	}
}
