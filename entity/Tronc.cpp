#include "Tronc.h"

Tronc::Tronc(int x, int y, int sizeX,int sizeY, int vie) : Entity_rect(x,y,sizeX,sizeY,vie){
	if(sizeX == 1){
		size.x = 50;
		size.y = 25;
		set_texture("Tronc_50x25px.png");
	}
	if(sizeX == 2){
		size.x = 80;
		size.y = 40;
		set_texture("Tronc_80x40px.png");
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
