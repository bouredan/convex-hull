#ifndef CONVEX_HULL_INPUT_OUTPUT_H
#define CONVEX_HULL_INPUT_OUTPUT_H

#include <string>
#include <random>
#include <set>

#define point std::pair<double, double>
#define DEFAULT_INPUT_SIZE 10

std::set<point> read_input_file(const std::string &path);

bool write_points_to_file(const std::set<point > &points, const std::string &path);

class input_generator {
public:
    explicit input_generator(size_t seed);

    bool generate_input_file(const std::string &path, int number_of_lines);

private:
    std::uniform_real_distribution<double> dist{0, 500};

    std::mt19937_64 rng;

    point generate_point();
};

#endif //CONVEX_HULL_INPUT_OUTPUT_H
