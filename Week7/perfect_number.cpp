#include "perfect_number.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

bool isPerfect(int num) {
    std::vector<int> divisors;
    std::vector<int> repeats(num-1, num);

    int indx = 1;
    std::for_each(repeats.begin(), repeats.end(), [&divisors, &indx, num](int &x) {
        if (num % indx == 0) {
            divisors.push_back(indx);
        }
        indx++;
    });

    int sum = std::accumulate(divisors.begin(), divisors.end(), 0);

    return sum == num;
}

