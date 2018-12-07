#include "arbre.h"

Arbre::Arbre(int x, int y, int rayon, int vie){
	Entity_ronde(x,y,rayon,vie);
	set_texture("Arbre-autre2.png");
}
Arbre::~Arbre(){
	printf("destruction arbre\n");
}
