#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void processText(std::string& inputText) {
    std::istringstream iss(inputText);
    std::ostringstream oss;

    std::string word;
    while (iss >> word) {
        oss << word << ' ';
    }

    inputText = oss.str();
}

int main() {
    std::ifstream inputFile("input.txt"); // Thay "input.txt" bằng tên file cần xử lý
    std::ofstream outputFile("output.txt"); // Thay "output.txt" bằng tên file kết quả

    if (!inputFile.is_open()) {
        std::cerr << "Không thể mở file đầu vào." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Không thể mở file đầu ra." << std::endl;
        inputFile.close();
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string inputText = buffer.str();

    processText(inputText);

    outputFile << inputText;

    std::cout << "DONE" << std::endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
