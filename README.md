# ソートのお勉強

![C++ unittest](https://github.com/teketekere/sort_obenkyo/workflows/C++%20unittest/badge.svg)

Introduction to algorithms [(Amazon link)](https://www.amazon.co.jp/Introduction-Algorithms-Press-Thomas-Cormen/dp/0262533057)のお勉強。

## Requirements

- Compiler: C++17

## Build

```shell
mkdir build
cd build
cmake -G Ninja ..
ninja -j4
./sort -i 10000 -d uniform_small -s stdsort
```

### Unittest

```shell
git submodule update --init --recursive
mkdir build
cd build
cmake -G Ninja -D BUILD_SORT_UNITTEST=ON ..
ninja -j4
ctest -V
```
