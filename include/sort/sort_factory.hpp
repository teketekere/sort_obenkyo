#ifndef B964AB51_EF08_4C5D_A8D6_BE49112AE921
#define B964AB51_EF08_4C5D_A8D6_BE49112AE921

#include <algorithm>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "sort/algorithms/insertion_sort.hpp"

namespace sort {
using SortFunc = std::function<void(void)>;

template <typename T>
using Comparable = std::function<bool(T, T)>;

template <typename T>
bool ascending_compare(T i1, T i2) {
    return i1 < i2;
}

template <typename T>
SortFunc create_insertion_sort(std::vector<T> &input, const Comparable<T> &compare) {
    return [&input, compare]() { insertion_sort(input.begin(), input.end(), compare); };
}

template <typename T>
SortFunc create_std_sort(std::vector<T> &input, const Comparable<T> &compare) {
    return [&input, compare]() { std::sort(input.begin(), input.end(), compare); };
}

template <typename T>
std::function<void(void)> create_sort(const std::string &type, std::vector<T> &input, const Comparable<T> &compare) {
    using Map = std::unordered_map<std::string, std::function<SortFunc()>>;
    static auto &map =
        *(new Map{{"insertion", [&input, &compare]() { return create_insertion_sort<T>(input, compare); }},
                  {"stdsort", [&input, &compare]() { return create_std_sort<T>(input, compare); }}});

    auto it = map.find(type);
    if (it == map.end()) {
        std::stringstream ss;
        for (const auto &item : map) {
            ss << item.first << ", ";
        }

        throw std::runtime_error("Unavailable sort algorithm: " + type + ". Available: " + ss.str());
    }

    return it->second();
}

}  // namespace sort

#endif /* B964AB51_EF08_4C5D_A8D6_BE49112AE921 */
