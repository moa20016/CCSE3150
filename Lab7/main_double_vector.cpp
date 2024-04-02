#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "double_vector.h"
#include "distance.h"

int main() {
    std::ifstream infile("vectors_kD.txt"); //modify this text file for different k
    if (!infile.is_open()) {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    std::vector<double_vector> vectors;
    std::string line;
    int id = 0;
    while (getline(infile, line)) {
        std::stringstream ss(line);
        double value;
        std::vector<double> vals;
        while (ss >> value) {
            vals.push_back(value);
        }
        vectors.push_back(double_vector(vals, id));
        id++;
    }
    infile.close();

    std::vector<my_distance> distances;
    for (size_t i = 0; i < vectors.size(); ++i) {
        for (size_t j = i + 1; j < vectors.size(); ++j) {
            double distance = cosine_distance(vectors[i], vectors[j]);
            distances.push_back(my_distance(i, j, distance));
        }
    }

    for (const auto &dist : distances) {
        std::cout << "Vectors " << dist.id_1 << " " << dist.id_2 << " dist = " << dist.cos_distance << std::endl;
    }

    std::sort(distances.begin(), distances.end(), [](const my_distance &a, const my_distance &b) {
        return a.cos_distance < b.cos_distance;
    });

    for (const auto &dist : distances) {
        std::cout << "Sorted Vectors " << dist.id_1 << " " << dist.id_2 << " dist = " << dist.cos_distance << std::endl;
    }

    

    return 0;
}
