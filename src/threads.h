#pragma once
#include "struct.h"
#include "timing.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

void executeCommands(const std::string& path, DataStorage& data) {
    std::ifstream input(path);
    if (!input) {
        std::cout << "Error: Cannot open " << path << std::endl;
        return;
    }
    
    std::string cmd;
    int field, val;
    
    while (input >> cmd) {
        if (cmd == "write") {
            input >> field >> val;
            (field == 0) ? data.setField0(val) : data.setField1(val);
        }
        else if (cmd == "read") {
            input >> field;
            (field == 0) ? data.getField0() : data.getField1();
        }
        else if (cmd == "string") {
            std::string s = data;
        }
    }
}

std::chrono::milliseconds runSingle(const std::string& path) {
    DataStorage data;
    return timeit([&]() {
        executeCommands(path, data);
    });
}

std::chrono::milliseconds runParallel(const std::vector<std::string>& paths) {
    DataStorage data;
    std::vector<std::thread> workers;
    
    return timeit([&]() {
        for (const auto& p : paths) {
            workers.emplace_back(executeCommands, std::cref(p), std::ref(data));
        }
        for (auto& w : workers) {
            w.join();
        }
    });
}

void runAllTests(const std::string& f1,
                 const std::vector<std::string>& f2,
                 const std::vector<std::string>& f3) {
    
    std::cout << "1 thread:  ";
    std::cout << runSingle(f1).count() / 1000.0 << " s" << std::endl;
    
    std::cout << "2 threads: ";
    std::cout << runParallel(f2).count() / 1000.0 << " s" << std::endl;
    
    std::cout << "3 threads: ";
    std::cout << runParallel(f3).count() / 1000.0 << " s" << std::endl;
}