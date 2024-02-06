#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "well_balanced.h"
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int n = 3; 
    int totalRuns = 100000;  
    int wellBalancedCount = 0;

    for (int run = 0; run < totalRuns; ++run) {
        std::vector<int> sequence = generateRandomParentheses(n);
        if (isWellBalanced(sequence)) {
            wellBalancedCount++;
        }
    }

    double proportionWellBalanced = static_cast<double>(wellBalancedCount) / totalRuns;

    std::cout << "Total runs: " << totalRuns << std::endl;
    std::cout << "Well-balanced count: " << wellBalancedCount << std::endl;
    std::cout << "Proportion of well-balanced lists: " << proportionWellBalanced << std::endl;

    return 0;
}
