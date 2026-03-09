#include <iostream>
#include <vector>

struct ChildNode {
    int childIndex;
    ChildNode* next;
    ChildNode(int index) : childIndex(index), next(nullptr) {}
};

struct TreeNode {
    char data;
    ChildNode* firstChild;
    TreeNode(char data) : data(data), firstChild(nullptr) {}
};

class ChildTree {
    std::vector<TreeNode> nodes;
public:
    void addNode(char data) {
        nodes.push_back(TreeNode(data));
    }

    void addChild(int parentIndex, int childIndex) {
        ChildNode* newChild = new ChildNode(childIndex);
        if (nodes[parentIndex].firstChild == nullptr) {
            nodes[parentIndex].firstChild = newChild;
        }
        else {
            ChildNode* current = nodes[parentIndex].firstChild;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newChild;
        }
    }

    void printTree() {
        for (size_t i = 0; i < nodes.size(); ++i) {
            std::cout << "Node: " << nodes[i].data << ", Children: ";
            ChildNode* current = nodes[i].firstChild;
            while (current != nullptr) {
                std::cout << nodes[current->childIndex].data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    ChildTree tree;
    tree.addNode('A');  // 根节点
    tree.addNode('B');
    tree.addNode('C');
    tree.addNode('D');
    tree.addNode('E');
    tree.addNode('F');
    tree.addNode('G');

    tree.addChild(0, 1);  // A的孩子是B
    tree.addChild(0, 2);  // A的孩子是C
    tree.addChild(0, 3);  // A的孩子是D
    tree.addChild(1, 4);  // B的孩子是E
    tree.addChild(2, 5);  // C的孩子是F
    tree.addChild(3, 6);  // D的孩子是G

    tree.printTree();
    return 0;
}
