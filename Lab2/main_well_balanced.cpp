#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "well_balanced.h"
int main() {
    std::srand(std::time(0));
    int iterations = 50000;
    int wellBalancedCount = 0;

    for (int i = 0; i < iterations; ++i) {
        std::vector<int> sequence = generateWellBalancedList(3);
        if (isWellBalanced(sequence)) {
            wellBalancedCount++;
            }
    }
    double proportion = static_cast<double>(wellBalancedCount) / iterations;
    std::cout << "Proportion of well-balanced lists: " << proportion << std::endl;

    return 0;
}