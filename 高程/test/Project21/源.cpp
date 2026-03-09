/*
【问题描述】
编写程序，从当前目录下的in.txt文件中读入一无符号浮点数（也可以是整数）和格式控制字符串，
按照格式控制要求输出该浮点数。

要求：
1. 格式控制字符串的形式为：%[-][width][.precision]f
   其中必有字符%和f；字符"-"表示输出时右对齐，若没有该字符表示默认左对齐；
   width和precision为大于等于1的整数，分别表示输出所占字段宽度和精度，
   若无width或width小于数据的实际宽度时，输出以实际宽度为准；
   precision若小于实际小数位数，则对小数部分直接截断（不进行四舍五入），
   若省略，则默认小数点后保留10位，若实际位数不够，则补0。
2. 格式控制字符串中只有字符"%"、"-"、"."、"f"和数字字符，不会出现其它字符。
3. width和precision最大为50。
4. 输入的浮点数最多不超过100个字符，若有小数点，则小数点前后都有数字。
5. 输出时，为了表示左对齐或右对齐，当width大于输出数据的实际宽度时，用英文字符"*"填充空白处。
6. 输出格式控制时，小数点本身占一个字符宽度。

【输入形式】
待读入的无符号浮点数和格式控制字符串分行保存在当前目录下的in.txt文件中，
格式控制字符串末尾也有一回车换行。

【输出形式】
按照格式控制字符串的要求，在标准输出上输出浮点数，注意要用英文字符"*"填充空白处
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void parseFormat(const string& formatStr, bool& leftAlign, int& width, int& precision) {
    leftAlign = true;
    width = -1;
    precision = -1;

    int i = 1;

    if (i < formatStr.length() && formatStr[i] == '-') {
        leftAlign = false;
        i++;
    }

    while (i < formatStr.length() && isdigit(formatStr[i])) {
        if (width == -1) width = 0;
        width = width * 10 + (formatStr[i] - '0');
        i++;
    }

    if (i < formatStr.length() && formatStr[i] == '.') {
        i++;
        precision = 0;
        while (i < formatStr.length() && isdigit(formatStr[i])) {
            precision = precision * 10 + (formatStr[i] - '0');
            i++;
        }
    }
}

string truncateDecimal(const string& numStr, int precision) {
    int dotPos = -1;
    for (int i = 0; i < numStr.length(); i++) {
        if (numStr[i] == '.') {
            dotPos = i;
            break;
        }
    }

    if (dotPos == -1) {
        if (precision > 0) {
            string result = numStr + ".";
            for (int i = 0; i < precision; i++) {
                result += "0";
            }
            return result;
        }
        return numStr;
    }

    string integerPart = numStr.substr(0, dotPos);
    string decimalPart = numStr.substr(dotPos + 1);

    if (precision == 0) {
        return integerPart;
    }
    else if (precision < decimalPart.length()) {
        return integerPart + "." + decimalPart.substr(0, precision);
    }
    else if (precision > decimalPart.length()) {
        string result = integerPart + "." + decimalPart;
        for (int i = decimalPart.length(); i < precision; i++) {
            result += "0";
        }
        return result;
    }
    else {
        return numStr;
    }
}

int main() {
    ifstream fin("in.txt");

    string numStr, formatStr;
    getline(fin, numStr);
    getline(fin, formatStr);
    fin.close();

    bool leftAlign;
    int width, precision;
    parseFormat(formatStr, leftAlign, width, precision);

    if (precision == -1) {
        precision = 10;
    }

    string formattedNum = truncateDecimal(numStr, precision);
    int actualWidth = formattedNum.length();

    if (width == -1 || width <= actualWidth) {
        cout << formattedNum << endl;
    }
    else {
        int padding = width - actualWidth;
        if (leftAlign) {
            cout << formattedNum;
            for (int i = 0; i < padding; i++) {
                cout << "*";
            }
        }
        else {
            for (int i = 0; i < padding; i++) {
                cout << "*";
            }
            cout << formattedNum;
        }
        cout << endl;
    }

    return 0;
}