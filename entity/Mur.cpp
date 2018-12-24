#include "Mur.h"
#include <ctime>
#include <cstdlib>

Mur::Mur(int x, int y, int sizeX,int sizeY, int vie) : Entity_rect(x,y,sizeX,sizeY,vie){
	//petit mur
	if(sizeX == 50 && sizeY == 10){
		int aleat = rand()%5;
		if (aleat == 0){
			set_texture("Mur_50x10px.png");
		}
		else if (aleat == 1){
			set_texture("Mur2_50x10px.png");
		}
		else if (aleat == 3){
			set_texture("Mur3_50x10px.png");
		}
		else if (aleat == 4){
			set_texture("Mur4_50x10px.png");
		}
	}
	//moyen mur
	if(sizeX == 100 && sizeY == 20){
		int aleat = rand()%5;
		if (aleat == 0){
			set_texture("Mur_100x20px.png");
		}
		else if (aleat == 1){
			set_texture("Mur2_100x20px.png");
		}
		else if (aleat == 3){
			set_texture("Mur3_100x20px.png");
		}
		else if (aleat == 4){
			set_texture("Mur4_100x20px.png");
		}
		
	}
	//grand mur
	if(sizeX == 160 && sizeY == 30){
		int aleat = rand()%5;
		if (aleat == 0){
			set_texture("Mur_160x30px.png");
		}
		else if (aleat == 1){
			set_texture("Mur2_160x30px.png");
		}
		else if (aleat == 3){
			set_texture("Mur3_160x30pxpng");
		}
		else if (aleat == 4){
			set_texture("Mur4_160x30px.png");
		}
	}
}
Mur::~Mur(){
	printf("destruction Mur\n");
}
