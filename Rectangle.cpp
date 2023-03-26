//  File : Rectangle.cpp
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Implementation of a Rectangle derived class object
//-------------------------------------------------------

#include "Rectangle.h"
#include "Point.h"

//Constructors
//-------------------------------------------------------
Rectangle::Rectangle() {
    points.resize(1);
    width = 0;
    height = 0;
}

Rectangle::Rectangle(Point topLeft, int width, int height) {

    points.push_back(topLeft);

    this->width = width;
    this->height = height;

}

//accessors
//-------------------------------------------------------

Point Rectangle::getTopLeft() {
    return points[0];
}

void Rectangle::setTopLeft(Point point) {
    points[0] = point;
}

int Rectangle::getWidth() {
    return width;
}

int Rectangle::setWidth(int width) {
    this->width = width;
}

int Rectangle::getHeight() {
    return height;
}

int Rectangle::setHeight(int height) {
    this->height = height;

}

//methods
//-------------------------------------------------------
/**
 * calculates rectangle area
 * @return Area
 */
float Rectangle::calcArea() {
    float area = width * height;
    return area;
}

/**
 * calculates rectangle perimeter
 * @return perimeter
 */
float Rectangle::calcPerimeter() {
    float perim = 2 * width + 2 * height;
    return perim;
}

/**
 * Stores formatted shape info (Corner coordinates, height, width, area, and perimeter) in one string
 * @return string of display info
 */
std::string Rectangle::displayInfo() {
    std::string retInfo = "\nRectangle:\n";

    retInfo = retInfo + "Width = " + std::to_string(width) + "\n";
    retInfo = retInfo + "Height = " + std::to_string(height) + "\n";
//points are displayed top left, top right, bottom left, bottom right in that order
    retInfo = retInfo + "Points: (";
    retInfo = retInfo + std::to_string(points[0].getX()) + "," + std::to_string(points[0].getY());
    retInfo += "), (";
    retInfo = retInfo + std::to_string(points[0].getX() + width) + "," + std::to_string(points[0].getY());
    retInfo += "), (";
    retInfo = retInfo + std::to_string(points[0].getX()) + "," + std::to_string(points[0].getY() - height);
    retInfo += "), (";
    retInfo = retInfo + std::to_string(points[0].getX() + width) + "," + std::to_string(points[0].getY() - height);
    retInfo += ")\n";

    retInfo = retInfo + "Perimeter = " + std::to_string(calcPerimeter()) + "\n";
    retInfo = retInfo + "Area = " + std::to_string(calcArea());


    return retInfo;
}