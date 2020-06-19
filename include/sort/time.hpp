#ifndef AF93876A_328C_4D84_9A7B_FA87F153FAAE
#define AF93876A_328C_4D84_9A7B_FA87F153FAAE

#include <chrono>
#include <iostream>
#include <string>

namespace sort {

template <class Duration, class Function>
void time(Function f, const std::string &suffix) {
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<Duration>(end - start).count()
              << suffix << std::endl;
}

}  // namespace sort

#endif /* AF93876A_328C_4D84_9A7B_FA87F153FAAE */
