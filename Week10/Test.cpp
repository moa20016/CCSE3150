#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Hybrid.h"

TEST_CASE("Electric class test") {
    Electric electric;
    electric.setMpge(120);
    electric.setCostPerkWh(0.18);

    CHECK(electric.calculateCostofTrip(100) == doctest::Approx(.15));
}

TEST_CASE("Gasoline class test") {
    Gasoline gasoline;
    gasoline.setMpg(25);
    gasoline.setCostPerGallon(3.4);

    CHECK(gasoline.calculateCostofTrip(100) == doctest::Approx(13.6));
}

TEST_CASE("Hybrid class test") {
    Hybrid hybrid;
    hybrid.setMpge(120);
    hybrid.setCostPerkWh(0.18);
    hybrid.setMpg(25);
    hybrid.setCostPerGallon(3.4);

    CHECK(hybrid.calculateCostofTrip(100) == doctest::Approx(6.875));
}
