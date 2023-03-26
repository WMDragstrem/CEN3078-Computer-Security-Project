//  File : Line.h
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Declaration of a Line derived class object
//-------------------------------------------------------

#ifndef SHAPESPROJECT_LINE_H
#define SHAPESPROJECT_LINE_H

#include "Shape.h"
#include "Point.h"
#include <string>


class Line : public Shape {
public:

    //constructors
    //-------------------------------------------------------
    Line();//default

    Line(Point pointOne, Point pointTwo);

    //accessors
    //-------------------------------------------------------

    Point getPointOne();

    void setPointOne(Point point);

    Point getPointTwo();

    void setPointTwo(Point point);

    //methods
    //-------------------------------------------------------
    float calcLength();

    float calcSlope();

    float calcAngle();

    std::string displayInfo();


};


#endif //SHAPESPROJECT_LINE_H
