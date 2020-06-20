#include <unistd.h>

#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "sort/distribution_factory.hpp"
#include "sort/generate_input_sequence.hpp"
#include "sort/is_sorted.hpp"
#include "sort/sort_factory.hpp"
#include "sort/time.hpp"

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

    using engine = std::mt19937;
    using container = std::vector<int>;

    auto dist = sort::crate_distribution<engine>(distribution_name);
    auto input_original = sort::generate_input_sequence<engine, container>(input_size, dist);

    for (const auto& name : sort_names) {
        // Copy input per loop (Cuz of in-place sorting)
        auto input = input_original;

        auto compare = [](int i1, int i2) { return sort::ascending_compare<int>(i1, i2); };
        auto sorter = sort::create_sort<decltype(input)::iterator, decltype(compare)>(name);

        auto elapsed_time = sort::time<std::chrono::milliseconds>(
            [&input, &compare, &sorter]() { sorter(input.begin(), input.end(), compare); });
        std::cout << "Sort by " << name << ": " << elapsed_time << " [msec]" << std::endl;

        // Check this algorithm works?
        sort::is_sorted(input.begin(), input.end(), [](auto i1, auto i2) { return i1 <= i2; });
    }
}
