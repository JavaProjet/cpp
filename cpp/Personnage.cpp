#include "Personnage.h"

const int Personnage::top = 0;
const int Personnage::left = 270;
const int Personnage::right = 90;
const int Personnage::bottom = 180;

Personnage::Personnage() : pos(0,0){
	vision = top;
	vie = 100;
}

Personnage::~Personnage(){}

Personnage::Personnage(int x, int y) : pos(x,y){
	vision = top;
	vie = 100;
}

Personnage::Personnage(int x, int y, int vision) : pos(x,y){
	this->vision = vision;
	vie = 100;
}

bool Personnage::degats(int nb){
	vie -= degat;
	if(vie <= 0) return false;
	else return true;
}

int Personnage::getVision(){
	return vision;
}

void Personnage::setVision(int degre){
	vision = degre;
}

void Personnage::tourneVision(int degre){
	vision += degre;
	if(vision >= 360) vision -= 360; 
	if(vision < 0) vision += 360; 
}

Point& Personnage::getPoint(){
	return pos.getPoint();
}

void Personnage::setPoint(int x, int y){
	pos.setX(x);
	pos.setY(y);
}

void Personnage::deplace(int x, int y){
	pos.deplace(x,y);
}

int Personnage::getVie(){
	return vie;
}
