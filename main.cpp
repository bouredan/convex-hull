#include "src/input_output.h"
#include "src/convex_hull.h"

#include <iostream>
#include <ctime>

#define GENERATE_INPUT_OPTION_LENGTH 17;

void print_usage(std::string const &exe_name) {
    std::clog << "Usage: " << exe_name << " num_iterations\n";
}

bool is_help(std::string const &argument) {
    return argument == "--help" || argument == "-h";
}

bool is_generate_input(std::string const &arg) {
    return arg.find("--generate-input=") == 0;
}

bool convex_hull(const std::string &input_file, const std::string &output_file) {
    std::cout << "INPUT FILE: " << input_file
              << "\nOUTPUT FILE: " << output_file << "\n\n";
    const std::set<point > points = read_input_file(input_file);
    const std::set<point > convex_hull = quickhull(points);
    save_points_to_file(convex_hull, output_file);
    return true;
}

int main(int argc, char *argv[]) {
    std::time_t time_now = std::time(nullptr);
    input_generator generator = input_generator(time_now);
    if (argc == 1) {
        std::string input_file = "convex_hull_" + std::to_string(time_now) + ".input";
        std::cout << "No arguments given, will generate own input.\n";
        std::string output_file = "convex_hull_" + std::to_string(time_now) + ".out";
        generator.generate_input_file(input_file, DEFAULT_INPUT_SIZE);
        convex_hull(input_file, output_file);
        return 0;
    } else {
        for (int i = 1; i < argc; i++) {
            if (is_help(argv[i])) {
                print_usage(argv[0]);
                return 0;
            } else if (is_generate_input(argv[i])) {
                const std::string path = argv[i] + GENERATE_INPUT_OPTION_LENGTH;
                generator.generate_input_file(path, DEFAULT_INPUT_SIZE);
            } else { // argument is considered to be an input file path
                const std::string input_file = argv[i];
                convex_hull(input_file, input_file + ".out");
            }
        }
    }
    return 0;
}
