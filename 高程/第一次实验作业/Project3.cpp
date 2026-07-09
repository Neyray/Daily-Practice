/*【问题描述】

编写程序，从当前目录下的in.txt文件中读入一无符号浮点数（也可以是整数）和格式控制字符串，按照格式控制要求输出该浮点数。要求：
1、格式控制字符串的形式为：%[-][width][.precision]f，其中必有字符%和f；字符"-"表示输出时右对齐，若没有该字符表示默认左对齐；width和precision为大于等于1的整数，分别表示输出所占字段宽度和精度，若无width或width小于数据的实际宽度时，输出以实际宽度为准；precision若小于实际小数位数，则对小数部分直接截断（不进行四舍五入），若省略，则默认小数点后保留10位，若实际位数不够，则补0。
2、上述格式控制字符串中只有字符"%"、"-"、"."、"f"和数字字符，不会出现其它字符。
3、width和precision最大为50。
4、输入的浮点数最多不超过100个字符，若有小数点，则小数点前后都有数字。
5、输出时，为了表示左对齐或右对齐，当width大于输出数据的实际宽度时，用英文字符"*"填充空白处。
6、输出格式控制时，小数点本身占一个字符宽度。

【输入形式】

待读入的无符号浮点数和格式控制字符串分行保存在当前目录下的in.txt文件中，格式控制字符串末尾也有一回车换行。

【输出形式】

按照格式控制字符串的要求，在标准输出上输出浮点数，注意要用英文字符"*"填充空白处
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// 解析格式控制字符串
void parseFormat(const string& formatStr, bool& leftAlign, int& width, int& precision) {
    leftAlign = true; // 默认左对齐
    width = -1;       // -1 表示没有指定width
    precision = -1;   // -1 表示没有指定precision

    int i = 1; // 跳过开头的 '%'

    // 检查对齐方式
    if (i < formatStr.length() && formatStr[i] == '-') {
        leftAlign = false; // '-' 表示右对齐
        i++;
    }

    // 解析width
    while (i < formatStr.length() && isdigit(formatStr[i])) {
        if (width == -1) width = 0;
        width = width * 10 + (formatStr[i] - '0');
        i++;
    }

    // 解析precision
    if (i < formatStr.length() && formatStr[i] == '.') {
        i++;
        precision = 0;
        while (i < formatStr.length() && isdigit(formatStr[i])) {
            precision = precision * 10 + (formatStr[i] - '0');
            i++;
        }
    }
}

// 截断小数部分，不进行四舍五入
string truncateDecimal(const string& numStr, int precision) {
    size_t dotPos = numStr.find('.');
    if (dotPos == string::npos) {
        // 没有小数点，当作整数处理
        if (precision > 0) {
            return numStr + "." + string(precision, '0');
        }
        else {
            return numStr;
        }
    }

    string integerPart = numStr.substr(0, dotPos);
    string decimalPart = numStr.substr(dotPos + 1);

    if (precision == 0) {
        return integerPart;
    }
    else if (precision < (int)decimalPart.length()) {
        // 直接截断，不四舍五入
        return integerPart + "." + decimalPart.substr(0, precision);
    }
    else if (precision > (int)decimalPart.length()) {
        // 补0
        return integerPart + "." + decimalPart + string(precision - decimalPart.length(), '0');
    }
    else {
        return numStr;
    }
}

int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        cerr << "无法打开文件 in.txt" << endl;
        return 1;
    }

    string numStr, formatStr;
    getline(fin, numStr);      // 读取浮点数
    getline(fin, formatStr);   // 读取格式控制字符串

    fin.close();

    // 解析格式控制字符串
    bool leftAlign;
    int width, precision;
    parseFormat(formatStr, leftAlign, width, precision);

    // 如果没有指定precision，默认为10
    if (precision == -1) {
        precision = 10;
    }

    // 处理浮点数
    string formattedNum = truncateDecimal(numStr, precision);

    // 计算实际宽度（包括小数点）
    int actualWidth = formattedNum.length();

    // 输出结果
    if (width == -1 || width <= actualWidth) {
        // width小于等于实际宽度，直接输出
        cout << formattedNum;
    }
    else {
        // 需要填充
        int padding = width - actualWidth;
        if (leftAlign) {
            // 左对齐：数字在左边，右边填充*
            cout << formattedNum;
            for (int i = 0; i < padding; i++) {
                cout << "*";
            }
        }
        else {
            // 右对齐：左边填充*，数字在右边
            for (int i = 0; i < padding; i++) {
                cout << "*";
            }
            cout << formattedNum;
        }
    }

    cout << endl;

    return 0;
}