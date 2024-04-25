#include <iostream>
#include "Hybrid.h"

int main() {
    Hybrid hybrid;

    hybrid.setCostPerGallon(3.4);
    hybrid.setMpg(25);

    hybrid.setCostPerkWh(.18);
    hybrid.setMpge(120);

    double totalMiles = 100;

    double electricCost = hybrid.Electric::calculateCostofTrip(totalMiles);
    double gasolineCost = hybrid.Gasoline::calculateCostofTrip(totalMiles);

    std::cout << "Electric cost: " << electricCost << std::endl;
    std::cout << "Gasoline cost: " << gasolineCost << std::endl;
    std::cout << "Hybrid cost: " << hybrid.calculateCostofTrip(totalMiles) << std::endl;

    return 0;
}
