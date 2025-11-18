#pragma once
#include <string>

struct OperationConfig {
    int read0_percent;
    int write0_percent;
    int read1_percent;
    int write1_percent;
    int string_percent;
    std::string name;
};

void generateFile(const std::string& filename, const OperationConfig& config, int totalOperations);