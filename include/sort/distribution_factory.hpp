#ifndef FE7E17AE_28A4_48F5_89F8_635F664C4372
#define FE7E17AE_28A4_48F5_89F8_635F664C4372

#include <functional>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>

namespace sort {

template <class Engine, typename T>
using DistributionFunc = std::function<T(Engine&)>;

template <class Engine, typename T, typename... Ts>
DistributionFunc<Engine, T> create_uniform();

template <class Engine, typename T = int, int Lower, int Upper>
DistributionFunc<Engine, int> create_uniform() {
    return [](Engine& engine) {
        auto dist = std::uniform_int_distribution<>(Lower, Upper);
        return dist(engine);
    };
}

template <class Engine, typename T>
DistributionFunc<Engine, T> crate_distribution(const std::string& type) {
    using Map = std::unordered_map<std::string, std::function<DistributionFunc<Engine, T>()>>;
    static auto& map = *(new Map{{"uniform_small", &create_uniform<Engine, int, 0, 10>},
                                 {"uniform_middle", &create_uniform<Engine, int, 0, 100>},
                                 {"uniform_large", &create_uniform<Engine, int, 0, 1000>}});

    auto it = map.find(type);
    if (it == map.end()) {
        std::stringstream ss;
        for (const auto& item : map) {
            ss << item.first << ", ";
        }

        throw std::runtime_error("Unavailable distribution: " + type + ". Avairable: " + ss.str());
    }

    return it->second();
}

}  // namespace sort

#endif /* FE7E17AE_28A4_48F5_89F8_635F664C4372 */
