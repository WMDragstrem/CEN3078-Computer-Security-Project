// File : ShapesProject.cpp
// Class: COP 3003, Fall 2022
// Devl : William Dragstrem
// Desc : Final project in which user adds different shapes to a collection
// and prints calculation details about all the shapes
//--------------------------------------------------------------
#include <iostream> //console I/O
#include <vector>
#include "Point.h" //points class
#include "Shape.h" //shape class
#include "Line.h" //line class
#include "Rectangle.h" //rectangle class
#include "Circle.h" //circle class

//Constants & Types
//--------------------------------------------------------------

// Function Prototypes
//--------------------------------------------------------------
Point getPoint();

Line *getLine();

Rectangle *getRectangle();

Circle *getCircle();

int getDimension(std::string dimName);

//--------------------------------------------------------------


int main() {

    char input;

    std::vector<Shape *> shapesVec;


    do {
        std::cout << "\n-------------------------Shapes.cpp-------------------------";
        std::cout << "\nEnter 1st character:" << std::endl;
        std::cout << "Line" << std::endl;
        std::cout << "Rectangle" << std::endl;
        std::cout << "Circle" << std::endl;
        std::cout << "Print" << std::endl;
        std::cout << "Exit" << std::endl;
        std::cout << ">";
        std::cin >> input;


        input = tolower(input); //sets input to lowercase so capital and lowercase input can be accepted



        switch (input) {
            case 'l':
                std::cout << "\nLine Selected." << std::endl;
                shapesVec.push_back(getLine());
                std::cout << "Line Saved." << std::endl;
                break; //end line
            case 'r':
                std::cout << "\nRectangle selected. Input top-left coordinate." << std::endl;
                shapesVec.push_back(getRectangle());
                std::cout << "Rectangle Saved." << std::endl;
                break; //end rectangle
            case 'c':
                std::cout << "\nCircle selected. Input center coordinate." << std::endl;
                shapesVec.push_back(getCircle());
                std::cout << "Circle Saved." << std::endl;
                break; //end circle
            case 'p':
                std::cout << "\nPrinting Selections..." << std::endl;
                for (int i = 0; i < shapesVec.size(); i++) {
                    std::cout << shapesVec[i]->displayInfo() << std::endl;
                }
                break; // end print
            case 'e':
                std::cout << "\nExiting..." << std::endl;

                break; //end exit
            default:
                std::cout << "\nUNKNOWN INPUT" << std::endl;


        }


    } while (input != 'e');

//clears shapesVec
    for (int i = 0; i < shapesVec.size(); i++) {
        delete shapesVec[i];
    }

}//end main



// Function Definitions
//--------------------------------------------------------------
/**
 * Prompts user for x and y coordinate info for a single point
 * @return point variable
 */
Point getPoint() {
    Point point;//Calls default constructor, makes empty point (0,0)
    std::cout << "Type X then Y coord separated by a space\n>";

    int xInput, yInput;
    std::cin >> xInput >> yInput;

    point.setX(xInput);
    point.setY(yInput);

    return point;

}//end getPoint

/**
 * prompts for necessary information to create line shape class variable
 * @return Line pointer
 */
Line *getLine() {
    Line *ptrLine;

    Point point1 = getPoint();
    Point point2 = getPoint();

    ptrLine = new Line();
    ptrLine->setPointOne(point1);
    ptrLine->setPointTwo(point2);
    ptrLine->setShapeType(LINE);

    return ptrLine;

}//end getLine

/**
 * prompts for necessary information to create Rectangle shape class variable
 * @return Rectangle pointer
 */
Rectangle *getRectangle() {
    Rectangle *ptrRectangle;

    Point topLeft = getPoint();
    int width = getDimension("width");
    int height = getDimension("height");

    ptrRectangle = new Rectangle(topLeft, width, height);
    ptrRectangle->setShapeType(RECTANGLE);

    return ptrRectangle;
}//end getRectangle

/**
 * prompts for necessary information to create Circle shape class variable
 * @return Circle pointer
 */
Circle *getCircle() {
    Circle *ptrCircle;

    Point center = getPoint();
    int radius = getDimension("radius");

    ptrCircle = new Circle();
    ptrCircle->setCenter(center);
    ptrCircle->setRadius(radius);
    ptrCircle->setShapeType(CIRCLE);

    return ptrCircle;
}//end getCircle

/**
 * Prompts user for an int dimension, string used in prompt to state type of dimension
 * @param dimName - string input representing dimension type (ex: width, height, length)
 * @return dimension measurement
 */
int getDimension(std::string dimName) {
    std::cout << "Enter " + dimName + "\n";
    int dimension;
    std::cin >> dimension;

    return dimension;
}//end getDimension