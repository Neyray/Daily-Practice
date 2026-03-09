#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// 函数：在二进制文件的每一行前加行号
void addLineNumbersToBinaryFile(const string& inputFilename, const string& outputFilename) {
    // 以二进制模式打开输入文件
    ifstream inputFile(inputFilename, ios::binary);
    if (!inputFile) {
        cerr << "错误：无法打开输入文件 '" << inputFilename << "'" << endl;
        return;
    }

    // 以二进制模式打开输出文件
    ofstream outputFile(outputFilename, ios::binary);
    if (!outputFile) {
        cerr << "错误：无法创建输出文件 '" << outputFilename << "'" << endl;
        inputFile.close();
        return;
    }

    int lineNumber = 1;
    string line;
    char ch;
    string currentLine;

    cout << "正在处理文件: " << inputFilename << endl;
    cout << "输出文件: " << outputFilename << endl;

    // 逐个字符读取，保留原始换行符
    while (inputFile.get(ch)) {
        // 将字符添加到当前行
        currentLine += ch;

        // 检查是否为换行符（Unix/Linux: \n, Windows: \r\n, Mac: \r）
        if (ch == '\n') {
            // 将行号添加到输出文件
            outputFile << setw(4) << lineNumber << ": ";

            // 写入原始行内容（包括换行符）
            outputFile.write(currentLine.c_str(), currentLine.size());

            // 重置当前行，增加行号
            currentLine.clear();
            lineNumber++;
        }
        // 对于Mac格式的回车换行
        else if (ch == '\r') {
            // 先保存当前位置
            streampos pos = inputFile.tellg();
            char nextChar;

            // 查看下一个字符是否为\n
            if (inputFile.get(nextChar)) {
                if (nextChar == '\n') {
                    // Windows格式：\r\n
                    currentLine += nextChar;
                    outputFile << setw(4) << lineNumber << ": ";
                    outputFile.write(currentLine.c_str(), currentLine.size());
                }
                else {
                    // Mac格式：\r
                    outputFile << setw(4) << lineNumber << ": ";
                    outputFile.write(currentLine.c_str(), currentLine.size());

                    // 将读取的字符放回缓冲区
                    inputFile.seekg(pos);
                }
            }
            else {
                // 文件结束
                outputFile << setw(4) << lineNumber << ": ";
                outputFile.write(currentLine.c_str(), currentLine.size());
            }

            currentLine.clear();
            lineNumber++;
        }
    }

    // 处理最后一行（如果没有以换行符结尾）
    if (!currentLine.empty()) {
        outputFile << setw(4) << lineNumber << ": ";
        outputFile.write(currentLine.c_str(), currentLine.size());
    }

    inputFile.close();
    outputFile.close();

    cout << "处理完成！共添加了 " << lineNumber << " 行的行号。" << endl;
    cout << "==================================" << endl;
}

// 显示文件内容
void displayFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "错误：无法打开文件 '" << filename << "'" << endl;
        return;
    }

    cout << "\n文件 '" << filename << "' 内容：" << endl;
    cout << "==================================" << endl;

    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        lineCount++;
        cout << line << endl;
    }

    file.close();
    cout << "==================================" << endl;
    cout << "总行数: " << lineCount << endl;
}

int main() {
    // 示例：处理一个文本文件
    string inputFile = "example.txt";
    string outputFile = "example_with_line_numbers.txt";

    // 先创建一个示例文件
    ofstream createExample(inputFile);
    if (createExample) {
        createExample << "这是第一行文本\n";
        createExample << "这是第二行文本\n";
        createExample << "这是第三行文本\n";
        createExample << "最后一行";
        createExample.close();
        cout << "已创建示例文件: " << inputFile << endl;
    }

    // 显示原始文件内容
    cout << "\n原始文件内容：" << endl;
    displayFile(inputFile);

    // 为文件添加行号
    addLineNumbersToBinaryFile(inputFile, outputFile);

    // 显示处理后的文件内容
    cout << "\n处理后文件内容：" << endl;
    displayFile(outputFile);

    return 0;
}