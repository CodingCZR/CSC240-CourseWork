#include <iostream> // Header file for input output functions
#include <string> // Header file for string functions
#include <cmath> // Header file for math functions


class Point {

private:
    int x; // Private variable
    int y; // Private variable

public:
    // All contructors
    Point();  // Default constructor
    Point(int x, int y); // Parameterized constructor
    Point(int yyxx); 

    // All member functions
    void setCoordinates(int x, int y); // Set the coordinates of the point
    void distanceFromOrigin(); // Calculate the distance of the point from the origin
    void determineQuadrant(); // Determine the quadrant of the point


};