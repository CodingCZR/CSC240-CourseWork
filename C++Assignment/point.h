#include <iostream> // Header file for input output functions
#include <cmath>    // Header file for math functions

class Point {

private:
    int x; // x-coordinate
    int y; // y-coordinate

public:
    // Constructors
    Point();  // Default constructor
    Point(int x, int y); // Parameterized constructor
    Point(int yyxx);  // Conversion constructor for 4-digit integer input

    // Member functions
    void setCoordinates(int x, int y); // Set the coordinates of the point
    double distanceFromOrigin() const; // Calculate and return distance from origin
    int determineQuadrant() const;     // Determine and return the quadrant

    // Operator overloading
    bool operator>(const Point& other) const;    // Compare distance from origin with another Point
    bool operator>(double distance) const;       // Compare distance from origin with a double
    friend bool operator>(double distance, const Point& point);  // Compare a double with a Point's distance

    double operator-(const Point& other) const;  // Calculate distance between two points
    friend std::ostream& operator<<(std::ostream& out, const Point& point); // Overload << to display (x, y)
};
