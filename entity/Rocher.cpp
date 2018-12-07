#include "Rocher.h"

Rocher::Rocher(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	
	set_texture("T-rocher2.png");
}
Rocher::~Rocher(){
	printf("destruction Rocher\n");
}
