//  File : Shapes.cpp
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Implementation of a Shape class object
//-------------------------------------------------------

#include "Shape.h"


Shape::Shape() {
    shapeType = UNKNOWN;
}//default constructor

Shape::Shape(TypeOfShape shape_Type) {
    shape_Type = shapeType;
}//property

//Accessors
//-------------------------------------------------------
TypeOfShape Shape::getShapeType() { return shapeType; }

void Shape::setShapeType(TypeOfShape newType) { shapeType = newType; }

//methods
//-------------------------------------------------------
