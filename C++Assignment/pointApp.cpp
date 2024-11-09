#include "point.h" // Include the header file point.h
#include <iostream> // Include for input and output
//file used for testing 

int main() {
    // Test default constructor
    Point p1;
    std::cout << "Default constructor: " << p1 << std::endl;

    // Test parameterized constructor
    Point p2(3, 4);
    std::cout << "Parameterized constructor (3, 4): " << p2 << std::endl;

    // Test conversion constructor with a 4-digit integer
    Point p3(3412); // Expected: y = 34, x = 12
    std::cout << "Conversion constructor (3412): " << p3 << std::endl;

    // Test setCoordinates
    p1.setCoordinates(-5, 7);
    std::cout << "After setting coordinates of p1 to (-5, 7): " << p1 << std::endl;

    // Test distanceFromOrigin
    std::cout << "Distance of " << p2 << " from origin: " << p2.distanceFromOrigin() << std::endl;

    // Test determineQuadrant
    std::cout << "Quadrant of " << p1 << ": " << p1.determineQuadrant() << std::endl;
    std::cout << "Quadrant of " << p2 << ": " << p2.determineQuadrant() << std::endl;

    // Test > operator with another Point
    std::cout << "Is " << p2 << " farther from origin than " << p3 << "? " 
              << (p2 > p3 ? "Yes" : "No") << std::endl;

    // Test > operator with a double
    std::cout << "Is " << p2 << " farther from origin than 5.0? " 
              << (p2 > 5.0 ? "Yes" : "No") << std::endl;

    // Test friend > operator with double
    std::cout << "Is 10.0 greater than the distance of " << p3 << " from the origin? " 
              << (10.0 > p3 ? "Yes" : "No") << std::endl;

    // Test - operator to find distance between two points
    std::cout << "Distance between " << p2 << " and " << p3 << ": " << (p2 - p3) << std::endl;

    return 0;
}
// Output