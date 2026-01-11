/*
输入方式：完全二叉树的存储方式，在一行之内输入，每个数字之间是空格，如2 3 4 -1 5 -1 6，-1表示节点不存在
现要求构造二叉链，求二叉树的最大宽度
输出方式：输出宽度即可。
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& s) {
    if (s.empty() || s[0] == '#') return nullptr;
    TreeNode* root = new TreeNode(s[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < s.size()) {
        TreeNode* current = q.front();
        q.pop();
        // 处理左子节点
        if (i < s.size()) {
            if (s[i] != '#') {
                current->left = new TreeNode(s[i]);
                q.push(current->left);
            }
            i++;
        }
        // 处理右子节点
        if (i < s.size()) {
            if (s[i] != '#') {
                current->right = new TreeNode(s[i]);
                q.push(current->right);
            }
            i++;
        }
    }
    return root;
}

int maxWidth(TreeNode* root) {
    // 处理空树情况：若根节点为空，返回宽度0
    if (!root) return 0;

    // 创建队列用于层序遍历，并初始化队列和最大宽度变量
    queue<TreeNode*> q;
    q.push(root);       // 将根节点加入队列
    int max_width = 0;  // 记录最大宽度，初始为0

    // 外层循环处理每一层，直到队列为空（所有层处理完毕）
    while (!q.empty()) {
        int size = q.size();        // 当前层的节点数
        max_width = max(max_width, size);  // 更新最大宽度

        // 内层循环遍历当前层的所有节点
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();  // 取出队首节点
            q.pop();                     // 弹出已取节点

            // 将当前节点的左右子节点加入队列（下一层节点）
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    // 返回遍历过程中记录的最大宽度
    return max_width;
}

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string nodes;
    char num;
    while (iss >> num) {
        nodes.push_back(num);
    }

    TreeNode* root = buildTree(nodes);
    cout << maxWidth(root) << endl;

    return 0;
}


/*
用户的DFS方法在统计每层节点数时逻辑正确，但可能由于题目中最大宽度的定义不同导致错误。
例如，若题目要求的是同一层节点间的最大跨度（包含中间的空节点），
则DFS方法不适用。否则，需检查以下可能问题：

构建树的方式：确保输入的完全二叉树数组正确转换为树结构。例如，父节点索引为i时，左子为2i+1，右子为2i+2，若对应位置存在且非-1才创建节点。

递归深度导致栈溢出：极端深度的树可能导致栈溢出，但通常表现为运行时错误而非答案错误。

OJ测试用例的特殊性：如输入中存在冗余空格或特殊字符，但代码中的输入处理已妥善处理。

正确性分析：

BFS方法：逐层遍历，直接统计每层节点数，正确性明确。

DFS方法：递归遍历每个节点，累加所在层计数。逻辑正确，适用于节点数统计的最大宽度。

问题可能出在测试用例的宽度定义不同，如LeetCode 662的宽度定义需考虑节点位置而非数量。若题目要求后者，需调整算法，否则当前DFS代码应正确。
建议检查题目定义或提供错误测试用例进一步排查。
*/