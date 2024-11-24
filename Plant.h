#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
using namespace std;

class Plant {
protected:
    string name;
    double cost;

public:
    Plant(string plantName, double plantCost);
    virtual ~Plant(); // Virtual destructor
    string getName() const;
    double getCost() const;
    virtual void display(ostream& out) const;
    bool operator==(const string& pName) const;
    friend ostream& operator<<(ostream& out, const Plant& p);
};

#endif
