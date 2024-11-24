#include <iostream>
#include <vector>
#include <algorithm>  // For sort()
#include "Plant.h"    // Include Plant class header
#include "Flower.h"   // Include Flower class header

using namespace std;

// Function prototypes
void addPlant(vector<Plant*>& garden);
void removePlant(vector<Plant*>& garden);
void displayPlants(const vector<Plant*>& garden);
void calculateTotalCost(const vector<Plant*>& garden);
void sortByName(vector<Plant*>& garden);
void sortByCost(vector<Plant*>& garden);

int main() {
    vector<Plant*> garden; // Vector to store Plant and Flower pointers
    int choice;

    do {
        // Display the menu
        cout << "\n***MY GARDEN MENU***" << endl;
        cout << "1. Add a new plant" << endl;
        cout << "2. Remove a plant" << endl;
        cout << "3. Display plants" << endl;
        cout << "4. Total cost" << endl;
        cout << "5. Sort by plant name" << endl;
        cout << "6. Sort by plant cost" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your selection: ";
        cin >> choice;

        // Handle menu selection
        switch (choice) {
            case 1:
                addPlant(garden);
                break;
            case 2:
                removePlant(garden);
                break;
            case 3:
                displayPlants(garden);
                break;
            case 4:
                calculateTotalCost(garden);
                break;
            case 5:
                sortByName(garden);
                break;
            case 6:
                sortByCost(garden);
                break;
            case 7:
                cout << "Program complete. Goodbye!" << endl;
                break;
            default:
                cout << "ERROR – Invalid selection." << endl;
        }
    } while (choice != 7);

    // Free allocated memory before exiting
    for (Plant* plant : garden) {
        delete plant;
    }

    return 0;
}

// Adds a new Plant or Flower to the garden
void addPlant(vector<Plant*>& garden) {
    char type;
    cout << "Enter plant type ('P' for Plant, 'F' for Flower): ";
    cin >> type;

    string name;
    double cost;
    cout << "Enter plant name: ";
    cin >> name;
    cout << "Enter plant cost: ";
    cin >> cost;

    if (type == 'P') {
        garden.push_back(new Plant(name, cost));
    } else if (type == 'F') {
        string color;
        char isAnnual;
        cout << "Enter flower color: ";
        cin >> color;
        cout << "Is it annual (Y/N)? ";
        cin >> isAnnual;

        garden.push_back(new Flower(name, cost, color, (isAnnual == 'Y' || isAnnual == 'y')));
    } else {
        cout << "Invalid plant type!" << endl;
    }
}

// Removes a Plant or Flower from the garden
void removePlant(vector<Plant*>& garden) {
    string name;
    cout << "Enter plant name to remove: ";
    cin >> name;

    auto it = garden.begin();
    for (; it != garden.end(); ++it) {
        if ((**it) == name) {
            delete *it;  // Free memory
            garden.erase(it);  // Remove from vector
            cout << name << " has been removed from the garden." << endl;
            return;
        }
    }
    cout << "ERROR – " << name << " is not in the garden." << endl;
}

// Displays all Plants and Flowers in the garden
void displayPlants(const vector<Plant*>& garden) {
    if (garden.empty()) {
        cout << "The garden is empty!" << endl;
        return;
    }

    cout << "\nPlants in the garden:\n";
    for (const Plant* plant : garden) {
        cout << *plant << endl;  // Calls the `<<` operator for each object
    }
}

// Calculates and displays the total cost of all plants and flowers
void calculateTotalCost(const vector<Plant*>& garden) {
    double totalCost = 0.0;

    for (const Plant* plant : garden) {
        totalCost += plant->getCost();
    }

    cout << "The total cost of all plants and flowers is $" << totalCost << endl;
}

// Helper function to sort by name
bool compareByName(Plant* a, Plant* b) {
    return a->getName() < b->getName();
}

// Sorts plants and flowers by name
void sortByName(vector<Plant*>& garden) {
    sort(garden.begin(), garden.end(), compareByName);
    cout << "Plants sorted by name." << endl;
}

// Helper function to sort by cost
bool compareByCost(Plant* a, Plant* b) {
    return a->getCost() < b->getCost();
}

// Sorts plants and flowers by cost
void sortByCost(vector<Plant*>& garden) {
    sort(garden.begin(), garden.end(), compareByCost);
    cout << "Plants sorted by cost." << endl;
}