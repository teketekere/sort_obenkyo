#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>

#include "sort/is_sorted.hpp"
#include "sort/sort_factory.hpp"

namespace {

std::vector<int> create_test_input() {
    // tekito
    return std::vector<int>{5, 2, 3, 4, 1, 6, -1, 0, 0, 2, 3, 3, 3, 10, 1, 7, 5, 4};
}

void test_sort(const std::string& sort_name) {
    auto test_input = create_test_input();
    auto sorter = sort::create_sort<int>(sort_name, test_input, &sort::ascending_compare<int>);
    sorter();
    for (const auto& v : test_input) std::cout << v << " ";
    EXPECT_NO_THROW(sort::is_sorted(test_input.begin(), test_input.end(), [](int i1, int i2) { return i1 <= i2; }));
    std::cout << sort_name << " passed." << std::endl;
}

}  // namespace

TEST(SortTest, ShouldNotFail) {
    test_sort("insertion");
    test_sort("stdsort");
}
