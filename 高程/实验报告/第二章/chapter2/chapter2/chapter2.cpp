#include <iostream>
using namespace std;

int main() {
    int number = 42; // 预设数字

    //while循环
    int guess;
    cout << "猜数字游戏开始！数字在1~100之间。" << endl;

    while (true) {
        cout << "请输入你猜的数字: ";
        cin >> guess;
        if (guess == number) {
            cout << "恭喜你猜对了！" << endl;
            break;
        }
        else if (guess < number) {
            cout << "猜小了！" << endl;
        }
        else {
            cout << "猜大了！" << endl;
        }
    }


    //for循环
    for (;;) {
        cout << "请输入你猜的数字: ";
        cin >> guess;
        if (guess == number) {
            cout << "恭喜你猜对了！" << endl;
            break;
        }
        else if (guess < number) {
            cout << "猜小了！" << endl;
        }
        else {
            cout << "猜大了！" << endl;
        }
    }

    //do_while循环
    do {
        cout << "请输入你猜的数字: ";
        cin >> guess;
        if (guess == number) {
            cout << "恭喜你猜对了！" << endl;
            break;
        }
        else if (guess < number) {
            cout << "猜小了！" << endl;
        }
        else {
            cout << "猜大了！" << endl;
        }
    } while (true);


    return 0;
}

