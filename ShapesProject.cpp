// File : ShapesProject.cpp
// Class: COP 3003, Fall 2022
// Devl : William Dragstrem
// Desc : Final project in which user adds different shapes to a collection
// and prints calculation details about all the shapes
// Ver  : 1.2.0
//--------------------------------------------------------------
#include <iostream> //console I/O
#include <vector>
#include "Point.h" //points class
#include "Shape.h" //shape class
#include "Line.h" //line class
#include "Rectangle.h" //rectangle class
#include "Circle.h" //circle class
#include <algorithm> //for count()

//Constants & Types
//--------------------------------------------------------------
const int MAX_SHAPES = 256; //maximum amount of shapes allowed to be saved to memory

enum InputType //TypeOfShape Enum in the shape header already uses the shape names, needs addressed.
{
    LINEIN = 1,
    RECTANGLEIN,
    CIRCLEIN,
    PRINTIN,
    EXITIN,


};

// Function Prototypes
//--------------------------------------------------------------
Point getPoint();

Line *getLine();

Rectangle *getRectangle();

Circle *getCircle();

int getDimension(std::string dimName);

int getIntInput();

//--------------------------------------------------------------


int main() {

    int input;

    std::vector<Shape *> shapesVec;
    std::vector<char> shapeInputs;
    shapeInputs = {LINEIN, RECTANGLEIN, CIRCLEIN}; //must be updated whenever a new shape is added to work with the numLoops check during user input

    int numLoops = 0;
    //added at the end of each shape input. Limits the total number of inputs to a set amount
    // (listed in the while loop condition) to prevent memory leaks.

    do {

        if (numLoops < MAX_SHAPES) {
            std::cout << ">";

            input = getIntInput();

        } else {
            std::cout << ">";

            bool redoInput = true;
            while (redoInput) {
                input = getIntInput();


                if (std::count(shapeInputs.begin(), shapeInputs.end(), input) == 0) {
                    //counts how many times the input appears in shapeInputs vector (if 0, then it isn't a shape input, otherwise it is, which would exceed MAX_SHAPES)
                    //allows the UNKNOWN INPUT error message if the input isn't a shape input but still isnt one of the non-shape inputs (such as print or exit)
                    redoInput = false;
                } else {
                    std::cout << "------------------------------------------------------------" << std::endl;
                    std::cout
                            << "You have exceeded the number of saved shapes! \nYou may still Print or Exit the program."
                            << std::endl;
                    std::cout << "------------------------------------------------------------" << std::endl;
                    std::cout << ">";
                }
            }
        }
        //Once the number of saved shapes is >= MAX_SHAPES, the program only allows the user to either print or exit, otherwise it prints an error message

        switch (input) {
            case LINEIN:
                std::cout << "\nLine Selected." << std::endl;
                shapesVec.push_back(getLine());
                std::cout << "Line Saved." << std::endl;
                numLoops += 1;
                break; //end line
            case RECTANGLEIN:
                std::cout << "\nRectangle selected. Input top-left coordinate." << std::endl;
                shapesVec.push_back(getRectangle());
                std::cout << "Rectangle Saved." << std::endl;
                numLoops += 1;
                break; //end rectangle
            case CIRCLEIN:
                std::cout << "\nCircle selected. Input center coordinate." << std::endl;
                shapesVec.push_back(getCircle());
                std::cout << "Circle Saved." << std::endl;
                numLoops += 1;
                break; //end circle
            case PRINTIN:
                std::cout << "\nPrinting Selections..." << std::endl;
                for (int i = 0; i < shapesVec.size(); i++) {
                    std::cout << shapesVec[i]->displayInfo() << std::endl;
                }
                break; // end print
            case EXITIN:
                std::cout << "\nExiting..." << std::endl;

                break; //end exit
            default:
                std::cout << "\nUNKNOWN INPUT" << std::endl;


        }


    } while (input != EXITIN);

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
 * https://cplusplus.com/forum/beginner/123439/
 * above website used as a source to limit inputs to only whole numbers
 */
Point getPoint() {
    Point point;//Calls default constructor, makes empty point (0,0)l
    bool validInput = false;
    int xInput, yInput;

    while (!validInput) {
        std::cout << "Type X then Y coord separated by a space\n>";
        char c;
        if (!(std::cin >> xInput >> yInput) || (std::cin.get(c) && !std::isspace(c))) {
            std::cout << "Entry must be a valid integer! Try again: \n";
            std::cin.clear();
            std::cin.ignore(500, '\n');

        } else validInput = true; // ends the loop
    }

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
    int dimension;
    bool validInput = false;

    while (!validInput) {
        std::cout << "Enter " + dimName + "\n";
        char c;
        if (!(std::cin >> dimension) || (std::cin.get(c) && !std::isspace(c))) {
            std::cout << "Entry must be a valid integer! Try again: \n";
            std::cin.clear();
            std::cin.ignore(500, '\n');

        } else validInput = true; //end loop
    }

    return dimension;
}//end getDimension

int getIntInput(){
    bool validInput = false;
    int intInput;
    while (!validInput) {

        char c;

        std::cout << "\n-------------------------Shapes.cpp-------------------------";
        std::cout << "\nEnter number next to chosen command:" << std::endl;
        std::cout << "1) Line" << std::endl;
        std::cout << "2) Rectangle" << std::endl;
        std::cout << "3) Circle" << std::endl;
        std::cout << "4) Print" << std::endl;
        std::cout << "5) Exit" << std::endl;
        std::cout << ">";
        if (!(std::cin >> intInput) || (std::cin.get(c) && !std::isspace(c))) {
            std::cout << "Entry must be a valid integer! Try again: \n";
            std::cin.clear();
            std::cin.ignore(500, '\n');

        } else validInput = true; //end loop
    }
    return intInput;
}
