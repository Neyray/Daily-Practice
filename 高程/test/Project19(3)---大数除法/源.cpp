// 大数除法（除以小整数）
#include <iostream>
#include <string>
using namespace std;

string divide(string num, int divisor) {
    string result = "";
    int remainder = 0;

    for (char digit : num) {
        remainder = remainder * 10 + (digit - '0');
        result += to_string(remainder / divisor);
        remainder %= divisor;
    }

    size_t pos = result.find_first_not_of('0');
    if (pos == string::npos) return "0";
    return result.substr(pos);
}

int main() {
    string num;
    int divisor;
    cin >> num >> divisor;
    cout << divide(num, divisor) << endl;
    return 0;
}