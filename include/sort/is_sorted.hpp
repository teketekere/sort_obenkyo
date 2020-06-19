#ifndef DE6DD28B_6C5D_4E1A_AF27_E7F1BB4E7FFD
#define DE6DD28B_6C5D_4E1A_AF27_E7F1BB4E7FFD

#include <stdexcept>

namespace sort {

template <class RandomAccessIterator, class Checker>
void is_sorted(RandomAccessIterator begin, RandomAccessIterator end,
               Checker checker) {
    auto prev_end = end - 1;
    for (auto it = begin; it != prev_end; ++it) {
        if (!checker(*it, *(it + 1))) {
            throw std::runtime_error("Not sorted.");
        }
    }
}

}  // namespace sort

#endif /* DE6DD28B_6C5D_4E1A_AF27_E7F1BB4E7FFD */
