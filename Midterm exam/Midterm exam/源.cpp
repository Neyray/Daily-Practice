/*【问题描述】
小明的键盘坏了，每次按下字符时会随机多输入一个退格符 #（例如输入 a#b 实际显示为 b）。现给定一个字符串 s，其中 # 表示退格符，它会删除其前一个有效字符。请编写程序，模拟键盘输出最终显示的字符串。
【输入形式】
输入一行字符串 s（仅包含小写字母和 # 符号）。
【输出形式】
输出处理后的字符串。若结果为空，则输出空行。
【样例输入1】
a#b#c
【样例输出1】
c
【样例输入2】
ab#c##
【样例输出2】（说明：空行）

【评分标准】
10个测试用例，按通过比例评分。
【评分标准】
10个测试用例，按通过比例评分。
【样例说明】
样例的输入只有1行，样例输出只有1行，请忽略为阅读方便而插入的空白行。
【类库使用要求】
不可以使用STL中的stack、queue、deque、vector等库函数，可以使用字符串STL处理输入。
【说明】
要求自己设计实现栈或队列类*/

#include <iostream>
#include <string>
using namespace std;

// 定义一个简单的栈类
class Stack {
private:
    char* data;
    int top;
    int capacity;

public:
    Stack(int size) {
        data = new char[size];
        top = -1;
        capacity = size;
    }

    ~Stack() {
        delete[] data;
    }

    // 入栈操作
    void push(char ch) {
        if (top < capacity - 1) {
            data[++top] = ch;
        }
    }

    // 出栈操作
    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    // 获取栈顶元素
    char peek() {
        if (top >= 0) {
            return data[top];
        }
        return '\0';
    }

    // 判断栈是否为空
    bool isEmpty() {
        return top == -1;
    }

    // 获取栈中的字符数
    int size() {
        return top + 1;
    }

    // 获取栈中的所有字符
    string getString() {
        string result = "";
        for (int i = 0; i <= top; ++i) {
            result += data[i];
        }
        return result;
    }
};

// 主函数
int main() {
    string s;
    cin >> s;

    Stack stack(s.length());

    for (char ch : s) {
        if (ch == '#') {
            stack.pop(); // 退格，弹出栈顶元素
        }
        else {
            stack.push(ch); // 正常字符，入栈
        }
    }

    // 输出最终结果
    cout << stack.getString() << endl;

    return 0;
}
