#ifndef HYBRID_H
#define HYBRID_H

#include <iostream>

class Vehicle {
public:
    Vehicle() : milesInTrip(0.0) {}
    virtual ~Vehicle() {}
protected:
    virtual double calculateCostofTrip(double miles) = 0;
private:
    double milesInTrip;
};

class Electric : public virtual Vehicle {
public:
    double calculateCostofTrip(double miles) override;
    virtual ~Electric() {}
    void setMpge(double m) { mpge = m; }
    double getMpge() { return mpge; }
    void setCostPerkWh(double c) { costPerkWh = c; }
    double getCostPerkWh() { return costPerkWh; }
private:
    double mpge;
    double costPerkWh;
};

class Gasoline : public virtual Vehicle {
public:
    double calculateCostofTrip(double miles) override;
    virtual ~Gasoline() {}
    void setMpg(double m) { mpg = m; }
    double getMpg() { return mpg; }
    void setCostPerGallon(double c) { costPerGallon = c; }
    double getCostPerGallon() { return costPerGallon; }
private:
    double mpg;
    double costPerGallon;
};

class Hybrid : public Electric, public Gasoline {
public:
    double calculateCostofTrip(double miles) override;
    Hybrid() {}
    virtual ~Hybrid() {}
};

#endif /* HYBRID_VEHICLE_H */
