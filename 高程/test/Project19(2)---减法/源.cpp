// ´óÊý¼õ·¨
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string subtract(string num1, string num2) {
    string result = "";
    int borrow = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0) {
        int digit1 = num1[i--] - '0';
        int digit2 = (j >= 0) ? (num2[j--] - '0') : 0;

        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result += char(diff + '0');
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << subtract(num1, num2) << endl;
    return 0;
}