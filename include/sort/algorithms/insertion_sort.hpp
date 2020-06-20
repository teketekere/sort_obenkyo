#ifndef E783D069_B829_4BF8_A744_C2A8F494080B
#define E783D069_B829_4BF8_A744_C2A8F494080B

namespace sort {

template <class RandomAccessIterator, class Comparable>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end, Comparable compare) {
    auto rend = begin - 1;
    for (auto it = begin + 1; it != end; ++it) {
        auto key = *it;
        auto jt = it - 1;
        while (jt != rend && !compare(*jt, key)) {
            *(jt + 1) = *jt;
            --jt;
        }

        *(jt + 1) = key;
    }
}

}  // namespace sort

#endif /* E783D069_B829_4BF8_A744_C2A8F494080B */
