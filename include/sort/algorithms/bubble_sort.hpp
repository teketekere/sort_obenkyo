#ifndef CD2B5B20_9492_42BD_9F40_7C21721CF509
#define CD2B5B20_9492_42BD_9F40_7C21721CF509

#include <algorithm>
#include <iterator>

namespace sort {

template <class RandomAccessIterator, class Comparable>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end, Comparable compare) {
    auto prev_end = end - 1;
    for (auto it = begin; it != prev_end; ++it) {
        for (auto jt = begin, jtend = prev_end - std::distance(begin, it); jt != jtend; ++jt) {
            if (!compare(*jt, *(jt + 1))) {
                std::iter_swap(jt, jt + 1);
            }
        }
    }
}

}  // namespace sort

#endif /* CD2B5B20_9492_42BD_9F40_7C21721CF509 */
