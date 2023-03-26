//  File : Circle.cpp
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Implementation of a Circle derived class object
//-------------------------------------------------------

#include "Circle.h"

#include <cmath>
#include "Point.h"
#include <string>


//constructors
//-------------------------------------------------------
Circle::Circle() {
    radius = 0;
    points.resize(1);
}

Circle::Circle(Point center, int radius) {
    this->radius = radius;
    points[0] = center;
}

//accessors
//-------------------------------------------------------

Point Circle::getCenter() {
    return points[0];
}

void Circle::setCenter(Point point) {
    points[0] = point;
}

int Circle::getRadius() {
    return radius;
}

void Circle::setRadius(int radius) {
    this->radius = radius;
}

//methods
//-------------------------------------------------------
/**
 * Returns the circle circumference with 2 * pi * radius
 * @return circumference
 */
float Circle::calcCircumference() {
    float circumference = radius * 2 * M_PI;
    return circumference;
}

/**
 * Calculates circle area with pi * radius^2
 * @return area
 */
float Circle::calcArea() {
    float area = M_PI * pow(radius, 2);
    return area;
}

/**
 * Stores formatted shape info (Center coordinate, radius, diameter, area, and circumference) in one string
 * @return string of display info
 */
std::string Circle::displayInfo() {
    std::string retInfo = "\nCircle:\n";

    retInfo = retInfo + "Center: (";
    retInfo = retInfo + std::to_string(points[0].getX()) + "," + std::to_string(points[0].getY());
    retInfo += ")\n";

    retInfo = retInfo + "Radius = " + std::to_string(radius) + "\n";
    retInfo = retInfo + "Diameter = " + std::to_string(radius * 2) + "\n";

    retInfo = retInfo + "Circumference = " + std::to_string(calcCircumference()) + "\n";
    retInfo = retInfo + "Area = " + std::to_string(calcArea());


    return retInfo;
}


