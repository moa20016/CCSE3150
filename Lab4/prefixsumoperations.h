#ifndef PREFIXSUMOPERATIONS_H
#define PREFIXSUMOPERATIONS_H

#include <vector>
#include <utility>

void fisherYatesShuffle(std::vector<int>& sequence);
std::vector<int> fillWithOnesAndNegOnes(int n);
std::vector<int> calculatePrefixSum(const std::vector<int>& array);
int findLowestPrefixSumIndex(const std::vector<int>& prefixSum);
std::pair<std::vector<int>, std::vector<int>> splitAtIndex(const std::vector<int>& array, int index);
void p1p2(std::vector<int>& p1, std::vector<int>& p2);
std::vector<int> concatenateArrays(const std::vector<int>& p1, const std::vector<int>& p2);
std::vector<int> createNonCrossingPrefixSum(int n);

#endif // PREFIXSUMOPERATIONS_H
