#pragma once
#include <chrono>
#include <iostream>

using namespace std::chrono;

template <class F>
auto timeit(F&& func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start);
}
