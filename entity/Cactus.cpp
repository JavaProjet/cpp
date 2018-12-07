#include "Cactus.h"

Cactus::Cactus(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	
	set_texture("cac2.png");

}
Cactus::~Cactus(){
	printf("destruction Cactus\n");
}
