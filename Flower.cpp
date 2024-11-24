#include "Flower.h"

Flower::Flower(string plantName, double plantCost, string flowerColor, bool flowerType)
    : Plant(plantName, plantCost), color(flowerColor), isAnnual(flowerType) {}

void Flower::display(ostream& out) const {
    Plant::display(out);
    out << " " << color << " " << (isAnnual ? "annual" : "perennial");
}

ostream& operator<<(ostream& out, const Flower& f) {
    f.display(out);
    return out;
}

