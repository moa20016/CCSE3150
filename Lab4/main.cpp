#include <iostream>
#include "prefixsumoperations.h"

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> result = createNonCrossingPrefixSum(n);

    std::cout << "Non-crossing prefix sum array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
