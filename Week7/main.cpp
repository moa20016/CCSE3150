#include <iostream>
#include <vector>
#include <algorithm>
#include "perfect_number.h"
#include <string>

int main() {
    std::string line;
    int given_int;

    std::cout << "Enter an integer: ";
    std::cin >> line;
    given_int = std::stoi(line);

    if (isPerfect(given_int)) {
        std::cout << given_int << " is a perfect number." << std::endl;
    } else {
        std::cout << given_int << " is not a perfect number." << std::endl;
    }

    return 0;
}
