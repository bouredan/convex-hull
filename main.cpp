#include "src/input_generator.h"

#include <iostream>
#include <ctime>

#define GENERATE_INPUT_LENGTH 17;

void print_usage(std::string const &exe_name) {
    std::clog << "Usage: " << exe_name << " num_iterations\n";
}

bool is_help(std::string const &argument) {
    return argument == "--help" || argument == "-h";
}

bool is_generate_input(std::string const &arg) {
    return arg.find("--generate-input=") == 0;
}

int main(int argc, char *argv[]) {
    std::time_t time_now = std::time(nullptr);
    input_generator generator = input_generator(time_now);
    if (argc == 1) {
        std::cout << "No arguments given, will generate own input.\n";
        std::string generated_file_name = "convex_hull_input_" + std::to_string(time_now) + ".txt";
        generator.generate_input_file(generated_file_name, DEFAULT_INPUT_SIZE);
        // TODO process generated input
        return 0;
    } else {
        for (int i = 1; i < argc; i++) {
            if (is_help(argv[i])) {
                print_usage(argv[0]);
                return 0;
            } else if (is_generate_input(argv[i])) {
                const std::string path = argv[i] + GENERATE_INPUT_LENGTH;
                generator.generate_input_file(path, DEFAULT_INPUT_SIZE);
            } else { // argument is considered to be an input file path
                // TODO process input
            }
        }
    }
    return 0;
}
