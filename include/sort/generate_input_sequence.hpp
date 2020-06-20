#ifndef DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5
#define DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5

#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <vector>

namespace sort {

template <class Engine>
Engine create_engine() {
    std::random_device rd{};
    std::array<std::seed_seq::result_type, Engine::state_size> seed_data{};
    std::generate(seed_data.begin(), seed_data.end(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    return Engine{seq};
}

template <class Engine, class Container, class Distribution>
Container generate_input_sequence(std::size_t size, Distribution dist) {
    auto engine = create_engine<Engine>();
    Container input_sequence{};
    input_sequence.reserve(size);
    for (std::size_t i = 0; i < size; ++i) {
        input_sequence.push_back(dist(engine));
    }

    return input_sequence;
}

}  // namespace sort

#endif /* DE57AFB4_BBD9_4B50_8ABD_BE069BF221A5 */
