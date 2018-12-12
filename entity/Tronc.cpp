#include "Tronc.h"

Tronc::Tronc(int x, int y, int sizeX,int sizeY, int vie) : Entity_rect(x,y,sizeX,sizeY,vie){
	
	set_texture("tronc2.png");
}
Tronc::~Tronc(){
	printf("destruction Tronc\n");
}
