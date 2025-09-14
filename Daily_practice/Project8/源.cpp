#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 以写模式打开文件
    std::ofstream outFile("example.txt", std::ios::out | std::ios::trunc);
    if (!outFile) {
        std::cerr << "Error opening file for writing" << std::endl;
        return 1;
    }
    outFile << "Initial content" << std::endl;
    outFile.close();

    // 以追加模式打开文件
    outFile.open("example.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file for appending" << std::endl;
        return 1;
    }
    outFile << "Appending more content" << std::endl;
    outFile.close();

    // 以读模式打开文件
    std::ifstream inFile("example.txt", std::ios::in);
    if (!inFile) {
        std::cerr << "Error opening file for reading" << std::endl;
        return 1;
    }

    std::string content;
    while (std::getline(inFile, content)) {
        std::cout << content << std::endl;
    }

    inFile.close();
    return 0;
}
