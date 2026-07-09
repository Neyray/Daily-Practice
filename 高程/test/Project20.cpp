/*
【问题描述】
编写一个程序，根据给定的输入绘制三种不同类型的图形：三角形、矩形和平行四边形。

【输入形式】
1. 第一行包含一个整数 T，表示测试用例的数量。
2. 接下来有 T 行，对于每个测试用例：
   2.1 仅一行，包含一个字符 choice 和两个整数 h 和 w。
   2.2 choice 可以是 'a'、'b' 或 'c'，分别代表绘制三角形、矩形或平行四边形。
   2.3 h 和 w 分别表示图形的高度和宽度（对于三角形，w 不适用，测试数据采用以 0 占位的方式）。

【输出形式】
1. 根据 choice 的值绘制相应的图形。
   1.1 如果 choice 是 'a'，则绘制高度为 h 的三角形。
   1.2 如果 choice 是 'b'，则绘制高度为 h、宽度为 w 的矩形。
   1.3 如果 choice 是 'c'，则绘制高度为 h、宽度为 w 的平行四边形。
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        char choice;
        int h, w;
        cin >> choice >> h >> w;

        if (choice == 'a') {
            // 绘制三角形
            for (int i = 1; i <= h; i++) {
                for (int j = 0; j < h - i; j++) {
                    cout << " ";
                }
                for (int j = 0; j < 2 * i - 1; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 'b') {
            // 绘制矩形
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        else if (choice == 'c') {
            // 绘制平行四边形
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < h - 1 - i; j++) {
                    cout << " ";
                }
                for (int j = 0; j < w; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }

    return 0;
}