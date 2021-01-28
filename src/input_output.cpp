#include <fstream>
#include <random>
#include <iostream>
#include "input_output.h"

std::set<point > read_input_file(const std::string &path) {
    std::ifstream input_file(path);
    std::set<point > points;
    double x, y;
    while (input_file >> x >> y) {
        points.emplace(x, y);
    }
    return points;
}

bool save_points_to_file(const std::set<point > &points, const std::string &path) {
    try {
        std::ofstream input_file(path);
        for (point p: points) {
            input_file << p.first << " " << p.second << "\n";
        }
        input_file.close();
    } catch (...) {
        std::cerr << "Exception when saving points to file " << path << ".\n";
        return false;
    }
    return true;
}

input_generator::input_generator(size_t seed) : rng(seed) {}

bool input_generator::generate_input_file(const std::string &path, int number_of_lines) {
    std::ofstream input_file(path);
    // TODO handle exceptions/errors
    for (int i = 0; i < number_of_lines; i++) {
        point generated_point = generate_point();
        input_file << generated_point.first << " " << generated_point.second << "\n";
    }
    input_file.close();
    return true;
}

point input_generator::generate_point() {
    return point(dist(rng), dist(rng));
}
