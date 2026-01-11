/*【问题描述】


一堆n根木棍，每个木棍的长度和重量是预先已知的。这些木棒将由木工机械加工。机器预处理木棍需要一些时间，称为设置时间。设置时间与清理操作以及更换机器中的工具和形状有关。加工机器的设置时间规定如下：

（a）第一个木棍的设置时间为1分钟。

（b）在加工（l，w）木棍（表示长度为l和重量为w的木棍）之后，如果遇到（l'，w'）木棍，并且有l≤l'，w≤w'，则机器加工（l'，w'）木棍不需要设置时间，否则，需要1分钟进行设置时间。

你要找到加工给定的n根木棍的最短设置时间。例如，如果你有5个长度和重量对分别为（9，4），（2，5），（1、2），（5、3）和（4, 1）的木棍，则最小设置时间应该是2分钟，因为正确的加工顺序是（4，1），（5，3），（9，4），（1，2），（2，5）。



【输入形式】


每个测试用例由两行组成，第一行是整数n（1≤n≤5000），表示木棍的数量，第二行包含2n个正整数l1，w1，l2，w2，…，ln，wn，每个整数最大为10000，其中li和wi分别是第i个木棍的长度和重量。2n个整数由一个或多个空格分隔。



【输出形式】


每行以分钟为单位输出最短设置时间。



【样例输入】


5

4 9 5 2 2 1 3 5 1 4





【样例输出】

2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 木棍结构体，包含长度和重量
struct Stick {
    int length, weight;
    // 重载小于运算符，用于排序
    // 按长度递增排序，长度相同则按重量递增排序
    bool operator<(const Stick& other) const {
        if (length != other.length) {
            return length < other.length;
        }
        return weight < other.weight;
    }
};

int main() {
    // 打开输入文件
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        cout << "无法打开文件 in.txt" << endl;
        return -1;
    }

    int n;
    fin >> n;
    vector<Stick> sticks(n);

    // 读取木棍信息：交替读取长度和重量
    for (int i = 0; i < n; i++) {
        fin >> sticks[i].length >> sticks[i].weight;
    }

    // 排序：按长度递增，长度相同时按重量递增
    sort(sticks.begin(), sticks.end());

    int setupTime = 0;
    vector<bool> used(n, false);

    // 每次寻找一个非递减的长度重量序列
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        // 开始一个新的设置时间
        setupTime++;
        used[i] = true;
        int lastLength = sticks[i].length;
        int lastWeight = sticks[i].weight;

        // 寻找后续可以连续加工的木棍（长度和重量都非递减）
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && sticks[j].length >= lastLength && sticks[j].weight >= lastWeight) {
                used[j] = true;
                lastLength = sticks[j].length;
                lastWeight = sticks[j].weight;
            }
        }
    }

    cout << setupTime << endl;

    // 关闭文件
    fin.close();
    return 0;
}