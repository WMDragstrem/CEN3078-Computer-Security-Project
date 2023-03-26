//  File : Point.cpp
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Implementation of a Point class object
//-------------------------------------------------------

#include "Point.h"

//Constructors
//-------------------------------------------------------
Point::Point() {
    xCoord = 0;
    yCoord = 0;
}//default constructor

Point::Point(int xCoord, int yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}//property

//Accessors
//-------------------------------------------------------
int Point::getX() { return xCoord; }

void Point::setX(int Value) { xCoord = Value; }

int Point::getY() { return yCoord; }

void Point::setY(int Value) { yCoord = Value; }