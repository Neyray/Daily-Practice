#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
using namespace std;

// 题目给定的二叉链表结点类型
struct BTNode {
    char ch;       // 编码的字符，非叶子节点置为 '\0'
    int data;      // 权值
    BTNode* lchild;
    BTNode* rchild;
};

// 从根到叶子递归生成编码
void buildCodes(BTNode* root, const string& path, unordered_map<char, string>& codes) {
    if (!root) return;
    // 叶子节点
    if (root->lchild == nullptr && root->rchild == nullptr) {
        // 只有一个节点时，约定编码 "0"
        codes[root->ch] = path.empty() ? "0" : path;
        return;
    }
    // 左子树加 '0'
    buildCodes(root->lchild, path + '0', codes);
    // 右子树加 '1'
    buildCodes(root->rchild, path + '1', codes);
}

int main() {
    int N;
    cin >> N;
    vector<pair<char, int>> inputs(N);
    for (int i = 0; i < N; i++) {
        cin >> inputs[i].first >> inputs[i].second;
    }

    // 哈夫曼树总节点数：2N-1
    int M = 2 * N - 1;

    // 用数组存储所有节点，前 N 个是叶子，后面是新创建的内部节点
    vector<BTNode> ht(M);
    // 标记每个下标节点是否已被合并（有父节点）
    vector<bool> hasParent(M, false);

    // 1. 初始化叶子节点
    for (int i = 0; i < N; i++) {
        ht[i].ch = inputs[i].first;
        ht[i].data = inputs[i].second;
        ht[i].lchild = ht[i].rchild = nullptr;
    }
    // 初始化内部节点位置
    for (int i = N; i < M; i++) {
        ht[i].ch = '\0';
        ht[i].data = 0;
        ht[i].lchild = ht[i].rchild = nullptr;
    }

    // 2. 构造哈夫曼树：做 N-1 次合并
    for (int i = N; i < M; i++) {
        // 在 [0..i-1] 中找两个最小且 hasParent==false 的节点 s1, s2
        int s1 = -1, s2 = -1;
        // 第一次遍历找 s1
        int min1 = numeric_limits<int>::max();
        for (int j = 0; j < i; j++) {
            if (!hasParent[j] && ht[j].data < min1) {
                min1 = ht[j].data;
                s1 = j;
            }
        }
        // 第二次遍历找 s2
        int min2 = numeric_limits<int>::max();
        for (int j = 0; j < i; j++) {
            if (!hasParent[j] && j != s1 && ht[j].data < min2) {
                min2 = ht[j].data;
                s2 = j;
            }
        }
        // 合并 s1, s2 到新节点 i
        ht[i].data = ht[s1].data + ht[s2].data;
        ht[i].lchild = &ht[s1];
        ht[i].rchild = &ht[s2];
        // 标记 s1, s2 已有父节点
        hasParent[s1] = hasParent[s2] = true;
    }

    // 根节点：最后一个合并得到的节点
    BTNode* root = (M == 1 ? &ht[0] : &ht[M - 1]);

    // 3. 生成每个字符的哈夫曼编码
    unordered_map<char, string> codes;
    buildCodes(root, "", codes);

    // 4. 按输入顺序输出编码，用空格分隔
    for (int i = 0; i < N; i++) {
        cout << codes[inputs[i].first];
        if (i != N - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}
