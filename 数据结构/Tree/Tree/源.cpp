#include <iostream>
#include <vector>

struct TreeNode {
    char data;
    int parent;
};

class ParentTree {
    std::vector<TreeNode> nodes;
public:
    void addNode(char data, int parent) {
        nodes.push_back({ data, parent });
    }

    void printTree() {
        for (size_t i = 0; i < nodes.size(); ++i) {
            std::cout << "Node: " << nodes[i].data << ", Parent Index: " << nodes[i].parent << std::endl;
        }
    }
};

int main() {
    ParentTree tree;
    tree.addNode('A', -1);  // 根节点
    tree.addNode('B', 0);   // B的父节点是A，索引为0
    tree.addNode('C', 0);   // C的父节点是A，索引为0
    tree.addNode('D', 0);   // D的父节点是A，索引为0
    tree.addNode('E', 1);   // E的父节点是B，索引为1
    tree.addNode('F', 2);   // F的父节点是C，索引为2
    tree.addNode('G', 3);   // G的父节点是D，索引为3

    tree.printTree();
    return 0;
}
