#ifndef DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5
#define DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5

#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <vector>

namespace sort {

template <class Engine, typename T, class Distribution>
std::vector<T> generate(std::size_t size, Distribution dist) {
    std::random_device rd{};
    std::array<std::seed_seq::result_type, Engine::state_size> seed_data{};
    std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    auto engine = Engine{seq};

    std::vector<T> result{};
    result.reserve(size);
    for (std::size_t i = 0; i < size; ++i) {
        result.push_back(dist(engine));
    }

    return result;
}

}  // namespace sort

#endif /* DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5 */
