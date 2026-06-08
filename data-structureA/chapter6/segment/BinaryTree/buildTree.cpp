#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

//1.给定先序和中序构造二叉树
// 辅助函数，携带数组边界索引
Node* helper1(const vector<int>& preorder, int preStart, int preEnd, 
              const vector<int>& inorder, int inStart, int inEnd) {
    // 递归终止条件：区间无效
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }
    
    // 先序的第一个元素就是根节点
    int rootVal = preorder[preStart];
    Node* root = new Node(rootVal);
    
    // 在中序序列中找到根节点的位置
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != rootVal) {
        rootIndex++;
    }
    
    // 计算左子树的节点数量
    int leftSize = rootIndex - inStart;
    
    // 递归构造左右子树
    root->left = helper1(preorder, preStart + 1, preStart + leftSize, 
                         inorder, inStart, rootIndex - 1);
    root->right = helper1(preorder, preStart + leftSize + 1, preEnd, 
                          inorder, rootIndex + 1, inEnd);
                          
    return root;
}

Node* buildTree1(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty() || inorder.empty()) return nullptr;
    return helper1(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}


//！！！注意：是先序序列
//2.给定包含空节点（-1）的先序序列构造二叉树
// 辅助函数，使用引用类型传递索引，保证全局向前推进
Node* helper2(const vector<int>& preorder, int& idx) {
    // 数组越界保护
    if (idx >= preorder.size()) {
        return nullptr;
    }
    
    // 如果遇到 -1，说明是空节点，索引前移并返回空
    if (preorder[idx] == -1) {
        idx++;
        return nullptr;
    }
    
    // 创建当前根节点
    Node* root = new Node(preorder[idx]);
    idx++; // 消费掉当前值
    
    // 严格按照先序的“根-左-右”顺序递归
    root->left = helper2(preorder, idx);
    root->right = helper2(preorder, idx);
    
    return root;
}

Node* buildTree2(vector<int>& preorder) {
    int idx = 0; // 从第 0 个元素开始扫描
    return helper2(preorder, idx);
}


//2.2根据完全二叉树遍历序列构造二叉树（完全二叉树）
Node* createTree(string str, int i) {
	if (i >= str.size()) return NULL;

	if (str[i] == '#') return NULL;

	Node* root = new Node(str[i]);

	root->left = createTree(str, 2 * i + 1);
	root->right = createTree(str, 2 * i + 2);

	return root;
}

//2.3根据层序序列建树，-1 表示空结点
Node* buildTree(vector<int>& nums) {
    if (nums.empty() || nums[0] == -1) {
        return NULL;
    }

    Node* root = new Node(nums[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < nums.size()) {
        Node* cur = q.front();
        q.pop();

        if (i < nums.size() && nums[i] != -1) {
            cur->left = new Node(nums[i]);
            q.push(cur->left);
        }
        i++;

        if (i < nums.size() && nums[i] != -1) {
            cur->right = new Node(nums[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}


//3.给定后序和中序构造二叉树
// 辅助函数，携带数组边界索引
Node* helper3(const vector<int>& inorder, int inStart, int inEnd, 
              const vector<int>& postorder, int postStart, int postEnd) {
    // 递归终止条件
    if (inStart > inEnd || postStart > postEnd) {
        return nullptr;
    }
    
    // 后序的最后一个元素是根节点
    int rootVal = postorder[postEnd];
    Node* root = new Node(rootVal);
    
    // 在中序序列中找到根节点的位置
    int rootIndex = inStart;
    while (rootIndex <= inEnd && inorder[rootIndex] != rootVal) {
        rootIndex++;
    }
    
    // 计算左子树的节点数量
    int leftSize = rootIndex - inStart;
    
    // 递归构造左右子树
    // 注意：后序数组的左子树区间是 [postStart, postStart + leftSize - 1]
    // 后序数组的右子树区间是 [postStart + leftSize, postEnd - 1]
    root->left = helper3(inorder, inStart, rootIndex - 1, 
                         postorder, postStart, postStart + leftSize - 1);
    root->right = helper3(inorder, rootIndex + 1, inEnd, 
                          postorder, postStart + leftSize, postEnd - 1);
                          
    return root;
}

Node* buildTree3(vector<int>& postorder, vector<int>& inorder) {
    if (postorder.empty() || inorder.empty()) return nullptr;
    return helper3(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}



//4.括号表示法
Node* buildTree4(const string& s) {
    stack<Node*> st;
    Node* root = nullptr;
    Node* p = nullptr;
    int k = 0; 
    int i = 0, n = s.length();
    
    while (i < n) {
        if (s[i] == ' ') { i++; continue; }
        if (s[i] == '(') {
            st.push(p);
            k = 1;
            i++;
        } else if (s[i] == ',') {
            k = 2;
            i++;
        } else if (s[i] == ')') {
            st.pop();
            i++;
        } else {
            int sign = 1;
            if (s[i] == '-') { sign = -1; i++; }
            int val = 0;
            while (i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            val *= sign;
            
            p = new Node(val);
            if (root == nullptr) {
                root = p;
            } else {
                if (k == 1) st.top()->left = p;
                else if (k == 2) st.top()->right = p;
            }
        }
    }
    return root;
}



//5.连续几行输入A B C（根左右）的形式，#表示空节点
Node* createTree() {
	int n;
	cin >> n;
	cin.ignore();

    //！！！需要访问之前的节点或者数据的时候，通常使用map容器
	map<char, Node*>nodes;

	Node* root = NULL;
	int i = 1;

	//遍历n次
	while (i <= n) {
		string str;
		getline(cin, str);
		stringstream ss(str);
		char ch1, ch2, ch3;
		ss >> ch1 >> ch2 >> ch3;

		if (nodes.find(ch1) == nodes.end()) {
			nodes[ch1] = new Node(ch1);
		}
		Node* curr = nodes[ch1];

		if (ch2 != '#') {
			if (nodes.find(ch2) == nodes.end()) {
				nodes[ch2] = new Node(ch2);
			}
			curr->left = nodes[ch2];
		}

		if (ch3 != '#') {
			if (nodes.find(ch3) == nodes.end()) {
				nodes[ch3] = new Node(ch3);
			}
			curr->right = nodes[ch3];
		}

		if (i == 1)root = curr;
		i++;
	}
	return root;
}


//6.根据层序遍历和中序遍历建树
//之所以不能直接切分是因为层次遍历左右子树是混在一起的，所以只能存入数组处理
Node* buildTree(vector<char> level, vector<char> in) {
    if (level.empty() || in.empty()) {
        return NULL;
    }

    // 1. 层次遍历的第一个结点一定是根
    char rootVal = level[0];
    Node* root = new Node(rootVal);

    // 2. 在中序遍历中找到根的位置
    int rootIndex = -1;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == rootVal) {
            rootIndex = i;
            break;
        }
    }

    // 3. 划分左、右子树的中序序列
    vector<char> leftIn, rightIn;

    for (int i = 0; i < rootIndex; i++) {
        leftIn.push_back(in[i]);
    }
    for (int i = rootIndex + 1; i < in.size(); i++) {
        rightIn.push_back(in[i]);
    }

    // 4. 为了判断某个结点属于左子树还是右子树，建立集合
    set<char> leftSet;
    set<char> rightSet;

    for (int i = 0; i < leftIn.size(); i++) {
        leftSet.insert(leftIn[i]);
    }
    for (int i = 0; i < rightIn.size(); i++) {
        rightSet.insert(rightIn[i]);
    }

    // 5. 根据中序划分结果，从层次序列中筛出左、右子树的层次序列
    vector<char> leftLevel, rightLevel;

    for (int i = 1; i < level.size(); i++) {
        if (leftSet.find(level[i]) != leftSet.end()) {
            leftLevel.push_back(level[i]);
        }
        else if (rightSet.find(level[i]) != rightSet.end()) {
            rightLevel.push_back(level[i]);
        }
    }

    // 6. 递归构造左右子树
    root->left = buildTree(leftLevel, leftIn);
    root->right = buildTree(rightLevel, rightIn);

    return root;
}

// 根据先序序列建树，-1 表示空节点
Node* buildTree() {
    int x;
    if (!(cin >> x)) {
        return NULL;
    }

    if (x == -1) {
        return NULL;
    }

    Node* root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}