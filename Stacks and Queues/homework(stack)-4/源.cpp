/*栈是一种具有后进先出的数据结构。可合并栈是支持“merge”操作的栈。三种操作的说明如下：

① push A x：将x插入栈A中。

② pop A：删除栈A的顶部元素。

③ merge A B：合并栈A和B。

其中，“merge A B”操作后栈A包含A和B之前的所有元素，B变为空，新栈中的元素根据先前的进栈时间重新排列，就像在一个栈中重复"push"操作一样。给定两个可合并栈A和B，请执行上述操作。

【输入形式】

     测试用例的第一行包含一个整数n（0<n≤10^5）表示操作个数，接下来的n行每行包含一条指令push、pop或merge，栈元素是32位整数。A和B最初都是空的，并且保证不会对空栈执行pop操作。以n=0表示输入结束。

【输出形式】

     对于每个pop操作，在一行中输出对应的出栈元素。
     */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    stack<int>A, B;
    vector<int>C;

    ifstream inFiles("in.txt");
    if (!inFiles) {
        cerr << "error";
    }

    int n;
    while (inFiles >> n && n != 0) {  // 关键修改：从文件读取n
        inFiles.ignore();  // 清除换行符 
        for (int i = 0; i < n; ++i) {
            string str;
            getline(inFiles, str);
            istringstream iss(str);
            string command;

            //重点，一定要去读
            iss >> command;

            if (command == "push") {
                char ch;
                int num;
                iss >> ch >> num;

                if (ch == 'A')
                    A.push(num);
                else if (ch == 'B')
                    B.push(num);

                //将这个数字储存到第三方容器中
                C.push_back(num);
            }

            else if (command == "pop") {
                char ch;
                iss >> ch;
                if (ch == 'A') {
                    if (!A.empty()) {
                        char a = A.top();

                        //输出
                        cout << a << endl;
                        A.pop();

                        //在第三方容器中删除该元素
                        auto it = find(C.begin(), C.end(), a);
                        if (it != C.end())
                            C.erase(it);
                    }
                }
                else if (ch == 'B') {
                    if (!B.empty()) {
                        char a = B.top();
                        B.pop();

                        //输出
                        cout << a << endl;

                        //在第三方容器中删除该元素
                        auto it = find(C.begin(), C.end(), a);
                        if (it != C.end())
                            C.erase(it);
                    }
                }
            }

            else if (command == "merge") {
                if (!B.empty()) {
                    while (!A.empty())
                        A.pop();
                    while (!B.empty())
                        B.pop();
                    for (size_t i = 0; i < C.size(); ++i) {
                        A.push(C[i]);
                    }
                }
            }
        }
    }
    inFiles.close();
    return 0;
}