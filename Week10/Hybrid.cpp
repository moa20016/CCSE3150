#include "Hybrid.h"

double Electric::calculateCostofTrip(double miles) {
    return (miles / mpge * costPerkWh);
}

double Gasoline::calculateCostofTrip(double miles) {
    return (miles / mpg * costPerGallon);
}

double Hybrid::calculateCostofTrip(double miles) {
    return (Electric::calculateCostofTrip(miles / 2) + Gasoline::calculateCostofTrip(miles / 2));
}
