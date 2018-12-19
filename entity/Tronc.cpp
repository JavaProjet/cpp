#include "Tronc.h"

Tronc::Tronc(int x, int y, int sizeX,int sizeY, int vie) : Entity_rect(x,y,sizeX,sizeY,vie){
	if(sizeX == 1){
		size.x = 50;
		size.y = 25;
		set_texture("Tronc_50x25px.png");
	}
	if(sizeX == 2){
		size.x = 100;
		size.y = 50;
		set_texture("Tronc_100x50px.png");
	}
	if(sizeX == 3){
		size.x = 120;
		size.y = 60;
		set_texture("Tronc_120x60px.png");
	}
}
Tronc::~Tronc(){
	printf("destruction Tronc\n");
}
