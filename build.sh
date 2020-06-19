#!/bin/sh -e

c++ -std=c++1z -I. -o sort -O3 -DNDEBUG -Weverything -Werror -Wno-c++98-c++11-compat -Wno-c++98-compat sort.cpp
