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

template <class RandomAccessIterator, class Comparable>
using SortFunc = std::function<void(RandomAccessIterator, RandomAccessIterator, Comparable)>;

template <typename T>
bool ascending_compare(T i1, T i2) {
    return i1 < i2;
}

template <class RandomAccessIterator, class Comparable>
SortFunc<RandomAccessIterator, Comparable> create_insertion_sort() {
    return [](RandomAccessIterator begin, RandomAccessIterator end, Comparable compare) {
        insertion_sort(begin, end, compare);
    };
}

template <class RandomAccessIterator, class Comparable>
SortFunc<RandomAccessIterator, Comparable> create_std_sort() {
    return [](RandomAccessIterator begin, RandomAccessIterator end, Comparable compare) {
        std::sort(begin, end, compare);
    };
}

template <class RandomAccessIterator, class Comparable>
SortFunc<RandomAccessIterator, Comparable> create_sort(const std::string &type) {
    using Map = std::unordered_map<std::string, std::function<SortFunc<RandomAccessIterator, Comparable>()>>;

    static auto &map = *(new Map{{"insertion", &create_insertion_sort<RandomAccessIterator, Comparable>},
                                 {"stdsort", &create_std_sort<RandomAccessIterator, Comparable>}});

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
