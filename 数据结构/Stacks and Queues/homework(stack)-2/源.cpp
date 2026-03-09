/*本题单测试点内有多组数据。
输入第一行是一个整数 T，表示数据组数。对于每组数据，格式如下：
每组数据第一行是一个整数，表示操作的次数 n。
接下来 n 行，每行首先由一个字符串，为 push，pop，query 和 size 之一。若为 push，则其后有一个整数 x，表示要被加入的数，x 和字符串之间用空格隔开；若不是 push，则本行没有其它内容。

输出格式
对于每组数据，按照「题目描述」中的要求依次输出。每次输出占一行。*/
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;  // 读取数据组数
    cin.ignore();  // 忽略残留的换行符

    while (T--) {
        int n;
        cin >> n;  // 读取操作次数
        cin.ignore();  // 忽略换行符

        stack<int> st;  // 创建栈
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);  // 读取每行操作
            istringstream iss(line);
            string command;
            iss >> command;  // 提取命令

            if (command == "push") {
                int x;
                iss >> x;  // 提取要加入栈的数字
                st.push(x);  // 执行 push 操作
            }
            else if (command == "pop") {
                if (st.empty()) {
                    cout << "Empty" << endl;  // 栈为空时输出 Empty
                }
                else {
                    st.pop();  // 执行 pop 操作
                }
            }
            else if (command == "query") {
                if (st.empty()) {
                    cout << "Anguei!" << endl;  // 栈为空时输出 Anguei!
                }
                else {
                    cout << st.top() << endl;  // 输出栈顶元素
                }
            }
            else if (command == "size") {
                cout << st.size() << endl;  // 输出栈的大小
            }
        }
    }
    return 0;
}
