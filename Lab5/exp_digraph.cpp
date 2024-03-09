#include <iostream>
#include <vector>
#include "exp_digraph.h"
#include <sstream>

using namespace std;

void expensiveDigraphExactPaths(vector<vector<int>>& DNeg1, vector<vector<int>>& DZero, vector<vector<int>>& DPos1) {
    int n = DZero.size();
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (DZero[i][k] == 0 && DPos1[k][j] == 0) {
                        DZero[i][j] = 0;
                    }
                    if (DPos1[i][k] == 1 && DPos1[k][j] == 1) {
                        DPos1[i][j] = 1;
                    }
                    if (DNeg1[i][k] == -1 && DZero[k][j] == -1) {
                        DNeg1[i][j] = -1;
                    }
                }
            }
        }
    }
}



vector<int> read_ints(istream& in_stream) {
    vector<int> res;
    int i;
    while (in_stream >> i) {
        res.push_back(i);
    }
    return res;
}

vector<vector<int>> read_matrix(istream& in_stream) {
    vector<vector<int>> matrix;
    string line;
    while (getline(in_stream, line)) {
        istringstream is(line);
        matrix.push_back(read_ints(is));
    }
    return matrix;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& my_vector) {
    for (size_t i = 0; i < my_vector.size(); ++i) {
        os << my_vector[i];
        if (i != my_vector.size() - 1) {
            os << " ";
        }
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<int>>& my_matrix) {
    for (size_t i = 0; i < my_matrix.size(); ++i) {
        os << my_matrix[i];
        if (i != my_matrix.size() - 1) {
            os << "\n";
        }
    }
    return os;
}