// 水仙花数
#include <iostream>
#include <cmath>
using namespace std;

bool isNarcissistic(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;

    //求出该数的位数
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    //求出每一位的指数并进行累加
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int start, end;
    cin >> start >> end;

    for (int i = start; i <= end; i++) {
        if (isNarcissistic(i)) {
            cout << i << endl;
        }
    }

    return 0;
}