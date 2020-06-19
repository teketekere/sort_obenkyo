# ソートのお勉強

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
