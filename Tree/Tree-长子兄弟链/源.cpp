#include <iostream>

struct TreeNode {
    char data;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(char data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}
};

class SiblingTree {
    TreeNode* root;
public:
    SiblingTree() : root(nullptr) {}

    TreeNode* addNode(TreeNode* parent, char data) {
        TreeNode* newNode = new TreeNode(data);
        if (parent == nullptr) {
            root = newNode;
        }
        else if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        }
        else {
            TreeNode* sibling = parent->firstChild;
            while (sibling->nextSibling != nullptr) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = newNode;
        }
        return newNode;
    }

    void printTree(TreeNode* node, int depth = 0) {
        if (node == nullptr) return;

        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << node->data << std::endl;

        printTree(node->firstChild, depth + 1);
        printTree(node->nextSibling, depth);
    }

    TreeNode* getRoot() {
        return root;
    }
};

int main() {
    SiblingTree tree;
    TreeNode* nodeA = tree.addNode(nullptr, 'A');  // ¸ù½Úµã
    TreeNode* nodeB = tree.addNode(nodeA, 'B');
    TreeNode* nodeC = tree.addNode(nodeA, 'C');
    TreeNode* nodeD = tree.addNode(nodeA, 'D');
    tree.addNode(nodeB, 'E');
    tree.addNode(nodeC, 'F');
    tree.addNode(nodeD, 'G');

    tree.printTree(tree.getRoot());
    return 0;
}
