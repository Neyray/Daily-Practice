#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// ���������ڵ�ṹ
struct BTNode {
    char ch;           // ������ַ�����Ҷ�ӽڵ�Ϊ '\0'
    int data;          // Ȩֵ
    BTNode* lchild;    // ������ָ��
    BTNode* rchild;    // ������ָ��
};

// �ݹ����ɹ���������
void generateCodes(BTNode* root, const string& code, unordered_map<char, string>& codes) {
    if (!root) return;

    // Ҷ�ӽڵ�
    if (!root->lchild && !root->rchild) {
        codes[root->ch] = code.empty() ? "0" : code;  // ֻ��һ���ַ�ʱ����Ϊ"0"
        return;
    }

    // �ݹ鴦��������������0��1��
    generateCodes(root->lchild, code + "0", codes);
    generateCodes(root->rchild, code + "1", codes);
}

// ������������
BTNode* buildHuffmanTree(const vector<pair<char, int>>& inputs) {
    int n = inputs.size();
    if (n == 0) return nullptr;

    // ���������ֻ��һ���ַ�
    if (n == 1) {
        BTNode* root = new BTNode{ '\0', inputs[0].second, nullptr, nullptr };
        root->lchild = new BTNode{ inputs[0].first, inputs[0].second, nullptr, nullptr };
        return root;
    }

    int totalNodes = 2 * n - 1;
    vector<BTNode> ht(totalNodes);
    vector<bool> hasParent(totalNodes, false);

    // ��ʼ��Ҷ�ӽڵ�
    for (int i = 0; i < n; i++) {
        ht[i].ch = inputs[i].first;
        ht[i].data = inputs[i].second;
        ht[i].lchild = ht[i].rchild = nullptr;
    }

    // ��ʼ���ڲ��ڵ�
    for (int i = n; i < totalNodes; i++) {
        ht[i].ch = '\0';
        ht[i].data = 0;
        ht[i].lchild = ht[i].rchild = nullptr;
    }

    // ������������������ n-1 �κϲ�
    for (int i = n; i < totalNodes; i++) {
        // �ҵ�һ����СȨֵ�ڵ�
        int s1 = -1, min1 = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (!hasParent[j] && ht[j].data < min1) {
                min1 = ht[j].data;
                s1 = j;
            }
        }

        // �ҵڶ�����СȨֵ�ڵ�
        int s2 = -1, min2 = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (!hasParent[j] && j != s1 && ht[j].data < min2) {
                min2 = ht[j].data;
                s2 = j;
            }
        }

        // �ϲ� s1 �� s2 ���½ڵ� i
        ht[i].data = ht[s1].data + ht[s2].data;
        ht[i].lchild = &ht[s1];
        ht[i].rchild = &ht[s2];

        // ����Ѻϲ�
        hasParent[s1] = hasParent[s2] = true;
    }

    // ���ظ��ڵ�
    return &ht[totalNodes - 1];
}

int main() {
    int n;
    cout << "�������ַ�����: ";
    cin >> n;

    vector<pair<char, int>> inputs(n);
    cout << "������ÿ���ַ�����Ȩֵ:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "�ַ� " << (i + 1) << ": ";
        cin >> inputs[i].first >> inputs[i].second;
    }

    // ������������
    BTNode* root = buildHuffmanTree(inputs);
    if (!root) {
        cout << "����ʧ�ܣ�" << endl;
        return 1;
    }

    // ���ɱ���
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    // ��ʾ�����
    cout << "\n=== ����������� ===" << endl;
    for (int i = 0; i < n; i++) {
        char ch = inputs[i].first;
        cout << "�ַ� '" << ch << "' -> " << codes[ch] << endl;
    }

    // ������˳��������루��ĿҪ���ʽ��
    cout << "\n������˳��ı���: ";
    for (int i = 0; i < n; i++) {
        cout << codes[inputs[i].first];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}

