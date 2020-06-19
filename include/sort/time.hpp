#ifndef AF93876A_328C_4D84_9A7B_FA87F153FAAE
#define AF93876A_328C_4D84_9A7B_FA87F153FAAE

#include <chrono>

namespace sort {

template <class Duration, class Function>
double time(Function f) {
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<Duration>(end - start).count();
}

}  // namespace sort

#endif /* AF93876A_328C_4D84_9A7B_FA87F153FAAE */
