#ifndef __WELL_BALANCED_H
#define __WELL_BALANCED_H

bool isWellBalanced(const std::vector<int>& sequence);
std::vector<int> generateRandomParentheses(int n);
void fisherYatesShuffle(std::vector<int>& sequence);
void swap(int* a, int* b);
void showData(const std::vector<int>& array);
void fisher_yates(int array[], const int length, int (* random_fcn)());

#endif
