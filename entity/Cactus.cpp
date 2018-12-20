#include "Cactus.h"

Cactus::Cactus(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	
	if(rayon == 1){
		this->rayon = 20;
		set_texture("Cactus_40px.png");
	}
	if(rayon == 2){
		this->rayon = 30;
		set_texture("Cactus_60px.png");
	}
	if(rayon == 3){
		this->rayon = 40;
		set_texture("Cactus_80px.png");
	}
	centre.x = position.x + this->rayon;
	centre.y = position.y + this->rayon;
}
Cactus::~Cactus(){
	printf("destruction Cactus\n");
}
