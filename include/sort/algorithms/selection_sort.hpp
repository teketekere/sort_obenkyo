#ifndef B81AF5FE_F9E8_40E9_8120_C3E0C6179581
#define B81AF5FE_F9E8_40E9_8120_C3E0C6179581

#include <algorithm>
#include <iterator>

namespace sort {

template <class RandomAccessIterator, class Comparable>
RandomAccessIterator find_extreme_value_iterator(RandomAccessIterator begin, RandomAccessIterator end,
                                                 Comparable compare) {
    auto extreme_value_iterator = begin;
    for (auto it = begin + 1; it != end; ++it) {
        if (!compare(*extreme_value_iterator, *it)) {
            extreme_value_iterator = it;
        }
    }

    return extreme_value_iterator;
}

template <class RandomAccessIterator, class Comparable>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end, Comparable compare) {
    auto prev_end = end - 1;
    for (auto it = begin; it != prev_end; ++it) {
        auto extreme_value_iterator = find_extreme_value_iterator(it, end, compare);
        std::iter_swap(it, extreme_value_iterator);
    }
}

}  // namespace sort

#endif /* B81AF5FE_F9E8_40E9_8120_C3E0C6179581 */
