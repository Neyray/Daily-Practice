//将链表后面的元素一个一个插入链表中
//输入形式是：Address,Data,next
//第一行是第一个节点的地址+接下来输入的数据个数
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    string addr, addr_next;
    int data;
    Node(string a, string an, int d) : addr(a), addr_next(an), data(d) {}
    Node() : addr(""), addr_next(""), data(0) {}
};

int main() {
    string addr0;
    int n;
    cin >> addr0 >> n;

    //使用cin和getline的时候一定要注意cin.ignore()!!!

    unordered_map<string, Node*> mp;
    for (int i = 0; i < n; i++) {
        string addr, addr_next;
        int data;
        cin >> addr >> data >> addr_next;
        mp[addr] = new Node(addr, addr_next, data);
    }

    // 按链表顺序还原
    vector<Node*> arr;
    string curr = addr0;
    while (curr != "-1") {
        arr.push_back(mp[curr]);
        curr = mp[curr]->addr_next;
    }

    // 双指针交替取节点，存入 result
    vector<Node*> result;
    //一定要注意同一变量的使用，可能值已经变了！！！
    int i = 0, j = (int)arr.size() - 1;
    while (i <= j) {
        result.push_back(arr[j--]);  // 先取右端
        if (i <= j)
            result.push_back(arr[i++]);  // 再取左端（注意 i<=j 还成立才取）
        else
            i++;
    }

    // 统一输出：每行的 next 就是 result 里的下一个节点
    for (int k = 0; k < (int)result.size(); k++) {
        string next = (k + 1 < (int)result.size()) ? result[k+1]->addr : "-1";
        cout << result[k]->addr << " " << result[k]->data << " " << next << "\n";
    }

    return 0;
}
