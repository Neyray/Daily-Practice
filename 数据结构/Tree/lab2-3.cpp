/*������������

�ӱ�׼�����ж���һ�������������ʽ���� ����ʽΪ��(a+3)*2/(b-A)����������ʽ���������ݱ���ʽ���������ʽ��ֵ��ͬʱ�������ʽ����α����ĵ��������ٰ���α����������������ʽ��ֵ��

��������ʽ��

����������������ʽ��

�������ʽ�� 

����Ļ��������У���һ���Ǹ��ݱ���ʽ��������ı���ʽ��ֵ���ڶ����ǲ�α�����������򣩣���������ͨ����α����������������ֵ��

��ʵ��Ҫ��

ÿһ������ʽ������20���ַ�������ʽ�л����Բ���ţ����ſ���Ƕ�ף�������ִ���ı���ʽ��

����ʽ���������+��-��*��/������������һλ���ֻ򵥸���ĸ��A~Z��a~z��)�Լ���ȷƥ�������������ɡ�

���ֳ���/ʱ������������������㣬�����Ϊ���������磺5/3���ӦΪ1��

�����ʽΪ(c+3)*2/(b-A)

�����ɵı���ʽ��Ϊ��

 blob.png

 

���������롿                        

(c+3)*2/(b-A)

�����������

6

3cAb2+-

6
*/
#include <iostream>
#include <stack>
#include <queue>
#include <cctype>
#include <map>
#include <string>
#include <vector>
using namespace std;

// ����ʽ���ڵ㶨��
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : val(c), left(nullptr), right(nullptr) {}
};

// ��ȡ���������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ��������ʽ��
TreeNode* buildExpressionTree(const string& expr) {
    stack<TreeNode*> nodes;
    stack<char> ops;

    for (size_t i = 0; i < expr.length(); ++i) {
        char c = expr[i];
        if (c == ' ') continue;
        if (isalnum(c)) {
            nodes.push(new TreeNode(c));
        }
        else if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();
                TreeNode* opNode = new TreeNode(ops.top()); ops.pop();
                opNode->left = left;
                opNode->right = right;
                nodes.push(opNode);
            }
            if (!ops.empty()) ops.pop(); // ���� '('
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();
                TreeNode* opNode = new TreeNode(ops.top()); ops.pop();
                opNode->left = left;
                opNode->right = right;
                nodes.push(opNode);
            }
            ops.push(c);
        }
    }

    while (!ops.empty()) {
        TreeNode* right = nodes.top(); nodes.pop();
        TreeNode* left = nodes.top(); nodes.pop();
        TreeNode* opNode = new TreeNode(ops.top()); ops.pop();
        opNode->left = left;
        opNode->right = right;
        nodes.push(opNode);
    }

    return nodes.top();
}

// ��ȡ�ַ���Ӧֵ��a/A=1, ..., z/Z=26������ֱ�ӷ���
int getValue(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 1;
    return 0;
}

// ����ʽ����ֵ�����������
int evaluate(TreeNode* root) {
    if (!root) return 0;

    // �����Ҷ�ӽڵ㣨��������
    if (!root->left && !root->right) {
        return getValue(root->val);
    }

    // �ݹ������������
    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    // �����������������
    switch (root->val) {
    case '+': return leftVal + rightVal;
    case '-': return leftVal - rightVal;
    case '*': return leftVal * rightVal;
    case '/': return rightVal != 0 ? leftVal / rightVal : 0;
    }

    return 0;
}


// ��α����������
void levelOrderReverse(TreeNode* root, string& out) {
    if (!root) return;
    queue<TreeNode*> q;
    vector<char> result;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        result.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        out += *it;
    }
}

// ����������ɺϷ���׺����ʽ
void postorder(TreeNode* root, string& postfix) {
    if (!root) return;
    postorder(root->left, postfix);
    postorder(root->right, postfix);
    postfix += root->val;
}

// ���沨������ʽ��ֵ
int evaluatePostfix(const string& expr) {
    stack<int> s;
    for (char c : expr) {
        if (isalnum(c)) {
            s.push(getValue(c));
        }
        else {
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            int res = 0;
            switch (c) {
            case '+': res = left + right; break;
            case '-': res = left - right; break;
            case '*': res = left * right; break;
            case '/': res = right != 0 ? left / right : 0; break;
            }
            s.push(res);
        }
    }
    return s.top();
}

// ������
int main() {
    string expr;
    getline(cin, expr); // �������ʽ

    TreeNode* root = buildExpressionTree(expr);

    // ��һ�У�����ʽ������ֵ
    cout << evaluate(root) << endl;

    // �ڶ��У���α�������
    string reversedLevel;
    levelOrderReverse(root, reversedLevel);
    cout << reversedLevel << endl;

    // �����У��Ϸ���׺����ʽ��ֵ
    string postfix;
    postorder(root, postfix); // ���ɺ�׺����ʽ
    cout << evaluatePostfix(postfix) << endl;

    return 0;
}
