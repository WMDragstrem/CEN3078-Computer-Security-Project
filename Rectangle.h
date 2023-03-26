//  File : Rectangle.h
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Declaration of a Rectangle derived class object
//-------------------------------------------------------

#ifndef SHAPESPROJECT_RECTANGLE_H
#define SHAPESPROJECT_RECTANGLE_H

#include "Shape.h"
#include "Point.h"


class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    //constructors
    //-------------------------------------------------------
    Rectangle();//default

    Rectangle(Point topLeft, int width, int height);

    //accessors
    //-------------------------------------------------------

    Point getTopLeft();

    void setTopLeft(Point point);

    Point getTopRight();

    void setTopRight(Point point);

    Point getBottomLeft();

    void setBottomLeft(Point point);

    Point getBottomRight();

    void setBottomRight(Point point);

    int getWidth();

    int setWidth(int width);

    int getHeight();

    int setHeight(int height);

    //methods
    //-------------------------------------------------------
    float calcArea();

    float calcPerimeter();

    std::string displayInfo();
};


#endif //SHAPESPROJECT_RECTANGLE_H
