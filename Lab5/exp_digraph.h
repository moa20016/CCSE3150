#ifndef _EXP_DIGRAPH_H
#define _EXP_DIGRAPH_H

#include <vector>
#include <string>

using namespace std;

void expensiveDigraphExactPaths(vector<vector<int>>& DNeg1, vector<vector<int>>& DZero, vector<vector<int>>& DPos1);
vector<vector<int>> read_matrix(istream & in_stream);
std::ostream &operator<<(std::ostream &os, const std::vector<int> & my_vector);
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> & my_matrix);
vector<int> read_ints(istream& in_stream);

#endif