#include <fstream>
#include <random>
#include "input_generator.h"

input_generator::input_generator(size_t seed) : rng(seed) {}

bool input_generator::generate_input_file(const std::string &path, int number_of_lines) {
    std::ofstream input_file;
    // TODO handle exceptions/errors
    input_file.open(path);
    for (int i = 0; i < number_of_lines; i++) {
        input_file << generate_point() << "\n";
    }
    input_file.close();
    return true;
}

std::string input_generator::generate_point() {
    return std::to_string(dist(rng)) + " " + std::to_string(dist(rng));
}
