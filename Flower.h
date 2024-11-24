#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant {
private:
    string color;
    bool isAnnual;

public:
    Flower(string plantName, double plantCost, string flowerColor, bool flowerType);
    ~Flower() override = default; // Use default destructor
    void display(ostream& out) const override;
    friend ostream& operator<<(ostream& out, const Flower& f);
};

#endif