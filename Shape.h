//  File : Shape.h
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Declaration of a Shape class object
//-------------------------------------------------------

//HEADER GUARD
#ifndef SHAPESPROJECT_SHAPE_H
#define SHAPESPROJECT_SHAPE_H

#include "Point.h"
#include <vector>
#include <string>


enum TypeOfShape {
    UNKNOWN,
    LINE,
    RECTANGLE,
    CIRCLE
};


class Shape {
protected:
    TypeOfShape shapeType;
    std::vector<Point> points;

public:
    //constructors
    //-------------------------------------------------------
    Shape(); //Default constructor
    Shape(TypeOfShape shape_Type);

    //accessors
    //-------------------------------------------------------
    TypeOfShape getShapeType();

    void setShapeType(TypeOfShape newType);

    //methods
    //-------------------------------------------------------
    // abstract method to be implemented in derived shape classes
    virtual std::string displayInfo() {};
};


#endif //SHAPESPROJECT_SHAPE_H
