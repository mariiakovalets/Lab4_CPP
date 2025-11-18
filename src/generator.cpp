#include "generator.h"
#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void generateFile(const string& filename, const OperationConfig& config, int totalOperations) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Cannot create file " << filename << endl;
        return;
    }

    random_device r;
    seed_seq seeds{r(), r(), r(), r(), r(), r()};
    mt19937 engine(seeds);
    uniform_int_distribution<int> operationDist(1, 100);
    uniform_int_distribution<int> valueDist(1, 1000);
    
    cout << "Generating " << filename << " with " << totalOperations << " operations..." << endl;
    
    for (int i = 0; i < totalOperations; ++i) {
        int random = operationDist(engine);
        int cumulative = 0;
        
        cumulative += config.read0_percent;
        if (random <= cumulative) {
            file << "read 0\n";
            continue;
        }
        
        cumulative += config.write0_percent;
        if (random <= cumulative) {
            int value = valueDist(engine);
            file << "write 0 " << value << "\n";
            continue;
        }
        
        cumulative += config.read1_percent;
        if (random <= cumulative) {
            file << "read 1\n";
            continue;
        }
        
        cumulative += config.write1_percent;
        if (random <= cumulative) {
            int value = valueDist(engine);
            file << "write 1 " << value << "\n";
            continue;
        }
        
        file << "string\n";
    }
    
    file.close();
    cout << "  -> " << filename << " created successfully!" << endl;
}

int main() {
    cout << "Input Files Generator for Variant #1" << endl;
    
    const int OPERATIONS_PER_FILE = 100000;
    
    OperationConfig configA = {10, 5, 50, 5, 30, "A (Variant #1)"};
    
    OperationConfig configB = {20, 20, 20, 20, 20, "B (Uniform)"};
    
    OperationConfig configC = {5, 45, 5, 40, 5, "C (Opposite)"};
    
    cout << "Config A: read0=" << configA.read0_percent << "%, write0=" << configA.write0_percent 
         << "%, read1=" << configA.read1_percent << "%, write1=" << configA.write1_percent 
         << "%, string=" << configA.string_percent << "%" << endl;
    
    cout << "Config B: read0=" << configB.read0_percent << "%, write0=" << configB.write0_percent 
         << "%, read1=" << configB.read1_percent << "%, write1=" << configB.write1_percent 
         << "%, string=" << configB.string_percent << "%" << endl;
    
    cout << "Config C: read0=" << configC.read0_percent << "%, write0=" << configC.write0_percent 
         << "%, read1=" << configC.read1_percent << "%, write1=" << configC.write1_percent 
         << "%, string=" << configC.string_percent << "%" << endl;
    
    cout << "\n--- Generating Config A files ---" << endl;
    generateFile("../demo/inputa1.txt", configA, OPERATIONS_PER_FILE);
    generateFile("../demo/inputa2.txt", configA, OPERATIONS_PER_FILE);
    generateFile("../demo/inputa3.txt", configA, OPERATIONS_PER_FILE);
    
    cout << "\n--- Generating Config B files ---" << endl;
    generateFile("../demo/inputb1.txt", configB, OPERATIONS_PER_FILE);
    generateFile("../demo/inputb2.txt", configB, OPERATIONS_PER_FILE);
    generateFile("../demo/inputb3.txt", configB, OPERATIONS_PER_FILE);
    
    cout << "\n--- Generating Config C files ---" << endl;
    generateFile("../demo/inputc1.txt", configC, OPERATIONS_PER_FILE);
    generateFile("../demo/inputc2.txt", configC, OPERATIONS_PER_FILE);
    generateFile("../demo/inputc3.txt", configC, OPERATIONS_PER_FILE);
    
    
    return 0;
}