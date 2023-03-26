//  File : Line.cpp
//  Class: COP 3003, Fall 2022
//  Devl : William Dragstrem
//  Desc : Implementation of a Line derived class object
//-------------------------------------------------------

#include "Line.h"
#include "Point.h"

#include <cmath>
#include <string>

//constructors
//-------------------------------------------------------
Line::Line() {
    points.resize(2);
}

Line::Line(Point pointOne, Point pointTwo) {
    points.push_back(pointOne);
    points.push_back(pointTwo);
}

//accessors
//-------------------------------------------------------
Point Line::getPointOne() {
    return points[0];
}

void Line::setPointOne(Point point) {
    points[0] = point;
}

Point Line::getPointTwo() {
    return points[1];
}

void Line::setPointTwo(Point point) {
    points[1] = point;
}

//methods
//-------------------------------------------------------
/**
 * calculates length of the line using pythagorean theorem
 * @return float length value
 */
float Line::calcLength() {
    float xSquared = pow(points[1].getX() - points[0].getX(), 2);
    float ySquared = pow(points[1].getY() - points[0].getY(), 2);
    float length = sqrt(xSquared + ySquared);
    return length;
}

/**
 * Uses point slope formula to calculate slope
 * @return float slope value
 */
float Line::calcSlope() {
    float slope = (points[1].getY() - points[0].getY()) / (points[1].getX() - points[0].getX());
    return slope;
}

/**
 * uses arcsine and the length of the line and its y component to calculate its angle
 * @return angle in degrees
 */
float Line::calcAngle() {
    float yLength = points[1].getY() - points[0].getY();
    float sinLine = yLength / Line::calcLength();
    float angle = asin(sinLine) * 180 / M_PI;

    return angle;
}

/**
 * Stores formatted shape info (Coordinates, length, slope, and angle) in one string
 * @return string of display info
 */
std::string Line::displayInfo() {
    std::string retInfo = "\nLine:\n";

    retInfo = retInfo + "Points: (";
    retInfo = retInfo + std::to_string(points[0].getX()) + "," + std::to_string(points[0].getY());
    retInfo += "), (";
    retInfo = retInfo + std::to_string(points[1].getX()) + "," + std::to_string(points[1].getY());
    retInfo += ")\n";

    retInfo = retInfo + "Length = " + std::to_string(calcLength()) + "\n";
    retInfo = retInfo + "Slope = " + std::to_string(calcSlope()) + "\n";
    retInfo = retInfo + "Angle = " + std::to_string(calcAngle());

    return retInfo;
}