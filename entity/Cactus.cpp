#include "Cactus.h"

Cactus::Cactus(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	
	if(rayon == 20)
		set_texture("Cactus_40px.png");
	
	if(rayon == 30)
		set_texture("Cactus_60px.png");
	
	if(rayon == 40)
		set_texture("Cactus_80px.png");
}
Cactus::~Cactus(){
	printf("destruction Cactus\n");
}

int Cactus::getType(){
	return cactus; //2
}
