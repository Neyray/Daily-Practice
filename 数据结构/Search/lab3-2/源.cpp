/*【问题描述】

从一段文本中统计词频，使用哈希表（链地址法）存储词及其频率，最后通过堆排序输出频率最高的K个词（若频率相同，按字典序升序）。

【输入形式】

从文件输入（in.txt）：  

- 第一行为文本内容（仅包含小写字母和空格，单词间可能有多余空格）。  

- 第二行为整数K（K ≥ 1）。

【输出形式】

输出到文件（out.txt）：  

- 按频率降序（同频时按字典序升序）输出前K个词及其频率，格式为word freq。

- 若不同单词总数不足K，输出所有单词（仍按上述规则排序）。

- 若文本无有效单词（空文本或全空格），输出为空。

【样例输入】

apple banana apple cherry banana apple  

3 

【样例输出】

apple 3  

banana 2  

cherry 1

【要求】

1. 必须手动实现哈希表（链地址法）和堆排序。  

2. 堆排序需构建最大堆，但最终输出需按频率降序（同频字典序升序）。  

3. 哈希表需处理冲突，且词频统计区分大小写（本题输入保证小写）。

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

const int HASH_SIZE = 1009; // 哈希表大小（质数）

// 哈希表节点结构
struct HashNode {
    string word;
    int freq;
    HashNode* next;
    HashNode(string w, int f) : word(w), freq(f), next(nullptr) {}
};

// 用于堆排序的节点结构
struct HeapNode {
    string word;
    int freq;
    HeapNode(string w, int f) : word(w), freq(f) {}
};

// 哈希表类
class HashTable {
private:
    HashNode* table[HASH_SIZE]; // 哈希表数组

    // 哈希函数：计算字符串的哈希值
    int hashFunction(const string& word) {
        unsigned long hash = 0;
        for (char c : word) {
            hash = (hash * 131 + c) % HASH_SIZE;
        }
        return hash % HASH_SIZE;
    }

public:
    // 构造函数：初始化哈希表
    HashTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // 析构函数：释放内存
    ~HashTable() {
        for (int i = 0; i < HASH_SIZE; i++) {
            HashNode* node = table[i];
            while (node) {
                HashNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    // 插入单词到哈希表
    void insert(const string& word) {
        int index = hashFunction(word);
        HashNode* node = table[index];

        // 检查单词是否已存在
        while (node) {
            if (node->word == word) {
                node->freq++;
                return;
            }
            node = node->next;
        }

        // 创建新节点并插入到链表头部
        HashNode* newNode = new HashNode(word, 1);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // 提取所有节点到数组
    void getAllNodes(HeapNode**& arr, int& size) {
        // 先计算节点总数
        size = 0;
        for (int i = 0; i < HASH_SIZE; i++) {
            HashNode* node = table[i];
            while (node) {
                size++;
                node = node->next;
            }
        }

        // 分配数组内存
        arr = new HeapNode * [size];
        int idx = 0;

        // 填充数组
        for (int i = 0; i < HASH_SIZE; i++) {
            HashNode* node = table[i];
            while (node) {
                arr[idx++] = new HeapNode(node->word, node->freq);
                node = node->next;
            }
        }
    }
};

// 堆排序类
class HeapSort {
private:
    // 比较函数：a是否应该排在b前面（用于堆排序）
    static bool compare(const HeapNode* a, const HeapNode* b) {
        if (a->freq != b->freq) {
            return a->freq > b->freq; // 频率降序
        }
        return a->word < b->word; // 字典序升序
    }

    // 调整堆
    static void heapify(HeapNode** arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && compare(arr[left], arr[largest])) {
            largest = left;
        }
        if (right < n && compare(arr[right], arr[largest])) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    // 堆排序
    static void sort(HeapNode** arr, int n) {
        // 构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 提取元素
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    // 读取文本内容
    string line;
    getline(fin, line);

    // 读取K值
    int K;
    fin >> K;

    // 分割单词
    stringstream ss(line);
    string word;
    HashTable hashTable;

    // 统计词频
    while (ss >> word) {
        hashTable.insert(word);
    }

    // 从哈希表提取数据
    HeapNode** nodes = nullptr;
    int totalWords = 0;
    hashTable.getAllNodes(nodes, totalWords);

    // 如果没有有效单词，直接返回
    if (totalWords == 0) {
        return 0;
    }

    // 堆排序
    HeapSort::sort(nodes, totalWords);

    // 计算实际输出数量
    int outputCount = min(K, totalWords);

    // 输出结果（从后往前输出，因为堆排序后数组是升序的）
    for (int i = 0; i < outputCount; i++) {
        int idx = totalWords - 1 - i;
        fout << nodes[idx]->word << " " << nodes[idx]->freq << endl;
    }

    // 释放内存
    for (int i = 0; i < totalWords; i++) {
        delete nodes[i];
    }
    delete[] nodes;

    fin.close();
    fout.close();
    return 0;
}