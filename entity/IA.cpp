
#include "IA.h"

IA::IA(int x, int y,int vie,bool bleu,bool tire) : Joueur(x,y,vie,bleu){

	this->tire = tire;
	
}

IA::~IA(){
	printf("destruction IA\n");
}
