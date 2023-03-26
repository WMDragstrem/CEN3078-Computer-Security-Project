//  File : Point.h
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Declaration of a Point class object
//-------------------------------------------------------

#ifndef SHAPESPROJECT_POINT_H
#define SHAPESPROJECT_POINT_H


class Point {
private:
    int xCoord;
    int yCoord;


public:
    //Constructors
    //-------------------------------------------------------
    Point(); //default constructor

    Point(int xCoord, int yCoord); //property

    //Accessors
    //-------------------------------------------------------
    int getX();

    void setX(int Value);

    int getY();

    void setY(int Value);

};


#endif //SHAPESPROJECT_POINT_H
