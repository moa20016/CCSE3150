#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "well_balanced.h"

void fisherYatesShuffle(std::vector<int>& sequence) {
    int n = sequence.size();
    for (int i = n - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(sequence[i], sequence[j]);
    }
}

bool isWellBalanced(const std::vector<int>& sequence) {
    int sum = 0;
    for (int num : sequence) {
        sum += num;
        if (sum < 0) {
            return false;
        }
    }
    return sum == 0;
}

std::vector<int> generateWellBalancedList(int n) {
    std::vector<int> sequence(2 * n, 0);
    for (int i = 0; i < n; ++i) {
        sequence[i] = 1;
        sequence[i + n] = -1;
    }
    fisherYatesShuffle(sequence);
    while (!isWellBalanced(sequence)) {
        fisherYatesShuffle(sequence);
    }
    return sequence;
}   
