#include "point.h" // Include the header file point.h
#include <cmath>   // Include for math functions like sqrt and pow

// Default constructor
Point::Point() : x(0), y(0) {}

// Parameterized constructor
Point::Point(int x, int y) : x(x), y(y) {}

// Conversion constructor to initialize the point with a single integer value (yyxx)
Point::Point(int yyxx) {
    if (yyxx < 100) {
        x = yyxx % 10;
        y = yyxx / 10;
    } else {
        x = yyxx % 100;
        y = yyxx / 100;
    }
}

// Set the coordinates of the point
void Point::setCoordinates(int x, int y) {
    this->x = x;
    this->y = y;
}

// Calculate the distance of the point from the origin
double Point::distanceFromOrigin() const {
    return sqrt(pow(x, 2) + pow(y, 2)); // Return the distance from origin
}

// Determine the quadrant or position of the point
int Point::determineQuadrant() const {
    if (x == 0 && y == 0) return 0;       // Origin
    if (x == 0) return 6;                 // Y-axis
    if (y == 0) return 5;                 // X-axis
    if (x > 0 && y > 0) return 1;         // Quadrant 1
    if (x < 0 && y > 0) return 2;         // Quadrant 2
    if (x < 0 && y < 0) return 3;         // Quadrant 3
    return 4;                             // Quadrant 4
}

// Overload > to compare distances from origin between two points
bool Point::operator>(const Point& other) const {
    return this->distanceFromOrigin() > other.distanceFromOrigin();
}

// Overload > to compare the point’s distance from origin with a double value
bool Point::operator>(double distance) const {
    return this->distanceFromOrigin() > distance;
}

// Friend function to overload > for comparing double with a point's distance
bool operator>(double distance, const Point& point) {
    return distance > point.distanceFromOrigin();
}

// Overload - to calculate the distance between two points
double Point::operator-(const Point& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

// Overload << for outputting coordinates as an ordered pair (x, y)
std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}
