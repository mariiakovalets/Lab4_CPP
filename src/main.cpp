#include "threads.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string fileA = "../demo/inputa1.txt";
    std::vector<std::string> filesA2{"../demo/inputa1.txt", "../demo/inputa2.txt"};
    std::vector<std::string> filesA3{"../demo/inputa1.txt", "../demo/inputa2.txt", "../demo/inputa3.txt"};
    
    std::string fileB = "../demo/inputb1.txt";
    std::vector<std::string> filesB2{"../demo/inputb1.txt", "../demo/inputb2.txt"};
    std::vector<std::string> filesB3{"../demo/inputb1.txt", "../demo/inputb2.txt", "../demo/inputb3.txt"};
    
    std::string fileC = "../demo/inputc1.txt";
    std::vector<std::string> filesC2{"../demo/inputc1.txt", "../demo/inputc2.txt"};
    std::vector<std::string> filesC3{"../demo/inputc1.txt", "../demo/inputc2.txt", "../demo/inputc3.txt"};
    

    std::cout << "A)requencies match variant 1:" << std::endl;
    runAllTests(fileA, filesA2, filesA3);
    
    std::cout << "\nB All frequencies equal:" << std::endl;
    runAllTests(fileB, filesB2, filesB3);
    
    std::cout << "\nС Frequencies opposite to variant:" << std::endl;
    runAllTests(fileC, filesC2, filesC3);
    
    return 0;
}