//  File : Circle.h
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Declaration of a Circle derived class object
//-------------------------------------------------------

#ifndef SHAPESPROJECT_CIRCLE_H
#define SHAPESPROJECT_CIRCLE_H


#include "Shape.h"
#include "Point.h"
#include <string>


class Circle : public Shape {
private:
    int radius;
public:

    //constructors
    //-------------------------------------------------------
    Circle();//default

    Circle(Point center, int radius);

    //accessors
    //-------------------------------------------------------

    Point getCenter();

    void setCenter(Point point);

    int getRadius();

    void setRadius(int radius);

    //methods
    //-------------------------------------------------------
    float calcCircumference();

    float calcArea();

    float calcDiameter();

    std::string displayInfo();


};


#endif //SHAPESPROJECT_CIRCLE_H
