#ifndef CONVEX_HULL_INPUT_GENERATOR_H
#define CONVEX_HULL_INPUT_GENERATOR_H

#include <string>
#include <random>

#define DEFAULT_INPUT_SIZE 10

class input_generator {
public:
    explicit input_generator(size_t seed);

    bool generate_input_file(const std::string &path, int number_of_lines);

private:
    std::uniform_real_distribution<double> dist{0, 500};

    std::mt19937_64 rng;

    std::string generate_point();
};

#endif //CONVEX_HULL_INPUT_GENERATOR_H
