#include "Point.h"
#include <iostream>

Point::Point(){
	x = 0;
	y = 0;
}

Point::~Point(){}

Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

Point::Point(Point &p){
	x = p.getX();
	y = p.getY();
}

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

void Point::setX(int x){
	this->x = x;
}

void Point::setY(int y){
	this->y = y; 
}

Point& Point::getPoint(){
	return *this;
}

Point& Point::operator=(Point& p){
	x = p.getX();
	y = p.getY();
	return *this;
}

void Point::deplace(int x, int y){
	this->x += x;
	this->y += y;
}
