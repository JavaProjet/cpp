#include "Rocher.h"

Rocher::Rocher(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 1){
		this->rayon = 20;
		set_texture("Rocher_40px.png");
	}
	if(rayon == 2){
		this->rayon = 50;
		set_texture("Rocher_100px.png");
	}
	if(rayon == 3){
		this->rayon = 80;
		set_texture("Rocher_160px.png");
	}
	centre.x = position.x + this->rayon;
	centre.y = position.y + this->rayon;
}
Rocher::~Rocher(){
	printf("destruction Rocher\n");
}
