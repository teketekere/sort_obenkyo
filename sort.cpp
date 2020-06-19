#include <unistd.h>

#include <cstdio>
#include <random>
#include <string>
#include <vector>

#include "distribution_factory.hpp"
#include "generate_instance.hpp"
#include "is_sorted.hpp"
#include "sort_factory.hpp"
#include "time.hpp"

int main(int argc, char** argv) {
    int opt;
    std::size_t input_size = 0;
    std::string distribution_name;
    std::vector<std::string> sort_names;
    while ((opt = getopt(argc, argv, "i:d:s:")) != -1) {
        switch (opt) {
            case 'i':
                input_size = static_cast<std::size_t>(std::atoi(optarg));
                break;

            case 'd':
                distribution_name = std::string(optarg);
                break;

            case 's':
                sort_names.push_back(std::string{optarg});
                break;

            default:
                printf(
                    "Usage: %s [-i Input size] [-d Distribution name] "
                    "[-s Sort name, ...]\n",
                    argv[0]);
                exit(1);
        }
    }

    // Create distribution.
    auto dist = sort::crate_distribution<std::mt19937>(distribution_name);

    // Create sort target.
    auto input_original = sort::generate<std::mt19937, int>(input_size, dist);

    // Execute each algorithms.
    for (const auto& name : sort_names) {
        // Create sort algorithm.
        auto input = input_original;
        auto sorter = sort::create_sort(name, input);

        // Measure this algorithm.
        std::cout << "Sort by " << name << ": ";
        sort::time<std::chrono::milliseconds>(sorter, " [msec]");

        // Check this algorithm works?
        sort::is_sorted(input.begin(), input.end(),
                        [](auto i1, auto i2) { return i1 <= i2; });
    }
}
