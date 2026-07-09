// 大数加法
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? (num1[i--] - '0') : 0;
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result += char(sum % 10 + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << add(num1, num2) << endl;
    return 0;
}