#include "Rocher.h"

Rocher::Rocher(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 20)
		set_texture("Rocher_40px.png");
	
	if(rayon == 50)
		set_texture("Rocher_100px.png");
	
	if(rayon == 80)
		set_texture("Rocher_160px.png");
}
Rocher::~Rocher(){
	printf("destruction Rocher\n");
}

int Rocher::getType(){
	return rocher; //3
}
