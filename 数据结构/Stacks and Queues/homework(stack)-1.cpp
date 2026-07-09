/*现有一个以英文字母组成的字符序列，序列的元素个数为N（3<N<26），该序列通过一个顺序栈可以得到多种出栈序列，设计一个算法判断输入的序列str是否为一个合适的出栈序列。
【输入形式】

第一行输入序列的元素个数N（3<N<26）

第二行按顺序输入该序列的所有元素，输入顺序即为进栈的顺序

第三行输入一个不知道是否正确的出栈序列
【输出形式】

判断第三行输入的是否为可能的出栈序列，如果是则输出true，如果不是则输出false。
【样例输入】

5

a b c d e

a b c d e
【样例输出】

true
【样例说明】

字符之间有空格*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;  // 输入栈的元素个数
    vector<char> inputSeq(N);  // 存储进栈的序列
    vector<char> outputSeq(N);  // 存储待检查的出栈序列

    // 读取入栈序列
    for (int i = 0; i < N; i++) {
        cin >> inputSeq[i];
    }

    // 读取出栈序列
    for (int i = 0; i < N; i++) {
        cin >> outputSeq[i];
    }

    stack<char> st;  // 用于模拟栈
    int inputIndex = 0;  // 输入序列的索引
    bool isPossible = true;

    // 尝试模拟栈操作
    for (int i = 0; i < N; i++) {
        // 将进栈序列中的元素依次压入栈中
        while (inputIndex < N && (st.empty() || st.top() != outputSeq[i])) {
            st.push(inputSeq[inputIndex]);
            inputIndex++;
        }

        // 如果栈顶元素和当前出栈序列的元素相同，就可以出栈
        if (st.top() == outputSeq[i]) {
            st.pop();
        }
        else {
            // 如果不相同，则说明该出栈序列不可能
            isPossible = false;
            break;
        }
    }

    // 输出结果
    if (isPossible) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
