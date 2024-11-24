#include "Plant.h"

Plant::Plant(string plantName, double plantCost) : name(plantName), cost(plantCost) {}

string Plant::getName() const { return name; }
double Plant::getCost() const { return cost; }

void Plant::display(ostream& out) const {
    out << name << " $" << cost;
}

bool Plant::operator==(const string& pName) const {
    return name == pName;
}

ostream& operator<<(ostream& out, const Plant& p) {
    p.display(out);
    return out;
}

Plant::~Plant() {}

