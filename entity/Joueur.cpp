#include "Joueur.h"

Joueur::Joueur(int x, int y,int vie,bool bleu) : Entity_ronde(x,y,20,vie){
	//bool bleu = bleu;
	if(bleu) set_texture("Somb3-bleu.png");
	else set_texture("Somb3-red.png");
}

Joueur::~Joueur(){
	printf("destruction Joueur\n");
}
