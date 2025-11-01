#include <iostream>
#include <cmath>
#include <vector>

//num代表原数,digits代表位数
bool isArmstrong(int num, int digits) {
    int sum = 0, temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += std::pow(digit, 3); // 这里假设水仙花数是三次幂
        temp /= 10;
    }
    return sum == num;
}

std::vector<int> findArmstrongNumbers(int N) {
    std::vector<int> armstrongNumbers;
    int lowerBound = std::pow(10, N - 1);
    int upperBound = std::pow(10, N) - 1;

    for (int i = lowerBound; i <= upperBound; ++i) {
        if (isArmstrong(i, N)) {
            armstrongNumbers.push_back(i);
        }
    }

    return armstrongNumbers;
}

int main() {
    int N;
    std::cout << "请输入一个整数N：";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "请输入一个正整数。" << std::endl;
        return 1;
    }

    std::vector<int> armstrongNumbers = findArmstrongNumbers(N);

    std::cout << N << "位的水仙花数有：" << std::endl;
    for (int num : armstrongNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
