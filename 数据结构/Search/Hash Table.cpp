#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

/**
 * 哈希表（Hash Table）实现
 * 使用链地址法解决哈希冲突
 * 平均时间复杂度：O(1) 查找、插入、删除
 * 最坏时间复杂度：O(n) - 所有元素哈希到同一位置
 */

 // 键值对结构
template<typename K, typename V>
struct KeyValuePair {
    K key;
    V value;

    KeyValuePair(const K& k, const V& v) : key(k), value(v) {}
};

template<typename K, typename V>
class HashTable {
private:
    static const int DEFAULT_CAPACITY = 16;  // 默认容量
    static const double LOAD_FACTOR_THRESHOLD; // 负载因子阈值

    vector<list<KeyValuePair<K, V>>> table;  // 哈希表（使用链表处理冲突）
    int capacity;     // 当前容量
    int size;         // 当前元素数量

    // 哈希函数（针对整数）
    int hashFunction(int key) {
        return abs(key) % capacity;
    }

    // 哈希函数（针对字符串）
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % capacity;
        }
        return abs(hash);
    }

    // 通用哈希函数模板
    template<typename T>
    int hash(const T& key) {
        if constexpr (is_same_v<T, int>) {
            return hashFunction(key);
        }
        else if constexpr (is_same_v<T, string>) {
            return hashFunction(key);
        }
        else {
            // 对于其他类型，使用简单的模运算
            return abs(static_cast<int>(key)) % capacity;
        }
    }

    // 重新哈希（扩容时使用）
    void rehash() {
        cout << "触发重新哈希，容量从 " << capacity << " 扩展到 " << capacity * 2 << endl;

        vector<list<KeyValuePair<K, V>>> oldTable = table;
        int oldCapacity = capacity;

        // 扩容
        capacity *= 2;
        table.clear();
        table.resize(capacity);
        size = 0;

        // 重新插入所有元素
        for (int i = 0; i < oldCapacity; i++) {
            for (const auto& pair : oldTable[i]) {
                insert(pair.key, pair.value);
            }
        }
    }

    // 计算当前负载因子
    double getLoadFactor() {
        return static_cast<double>(size) / capacity;
    }

public:
    // 构造函数
    HashTable(int cap = DEFAULT_CAPACITY) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    // 插入键值对
    void insert(const K& key, const V& value) {
        // 检查是否需要扩容
        if (getLoadFactor() >= LOAD_FACTOR_THRESHOLD) {
            rehash();
        }

        int index = hash(key);

        // 检查键是否已存在，如果存在则更新值
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }

        // 插入新的键值对
        table[index].emplace_back(key, value);
        size++;
    }

    // 查找键对应的值
    bool search(const K& key, V& value) {
        int index = hash(key);

        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                value = pair.value;
                return true;
            }
        }

        return false;
    }

    // 检查键是否存在
    bool contains(const K& key) {
        int index = hash(key);

        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return true;
            }
        }

        return false;
    }

    // 删除键值对
    bool remove(const K& key) {
        int index = hash(key);

        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                size--;
                return true;
            }
        }

        return false;
    }

    // 获取元素数量
    int getSize() const {
        return size;
    }

    // 检查是否为空
    bool isEmpty() const {
        return size == 0;
    }

    // 打印哈希表状态
    void printTable() {
        cout << "\n=== 哈希表状态 ===" << endl;
        cout << "容量: " << capacity << ", 大小: " << size << endl;
        cout << "负载因子: " << getLoadFactor() << endl;

        for (int i = 0; i < capacity; i++) {
            cout << "桶 " << i << ": ";
            if (table[i].empty()) {
                cout << "空" << endl;
            }
            else {
                cout << "[";
                bool first = true;
                for (const auto& pair : table[i]) {
                    if (!first) cout << ", ";
                    cout << "(" << pair.key << ":" << pair.value << ")";
                    first = false;
                }
                cout << "]" << endl;
            }
        }
        cout << "==================" << endl;
    }

    // 获取所有键
    vector<K> getKeys() {
        vector<K> keys;
        for (int i = 0; i < capacity; i++) {
            for (const auto& pair : table[i]) {
                keys.push_back(pair.key);
            }
        }
        return keys;
    }

    // 获取所有值
    vector<V> getValues() {
        vector<V> values;
        for (int i = 0; i < capacity; i++) {
            for (const auto& pair : table[i]) {
                values.push_back(pair.value);
            }
        }
        return values;
    }
};

// 静态成员定义
template<typename K, typename V>
const double HashTable<K, V>::LOAD_FACTOR_THRESHOLD = 0.75;

// 开放地址法哈希表实现（线性探测）
template<typename K, typename V>
class HashTableOpenAddressing {
private:
    struct Entry {
        K key;
        V value;
        bool deleted;  // 标记删除状态
        bool empty;    // 标记空状态

        Entry() : deleted(false), empty(true) {}
        Entry(const K& k, const V& v) : key(k), value(v), deleted(false), empty(false) {}
    };

    static const int DEFAULT_CAPACITY = 16;
    vector<Entry> table;
    int capacity;
    int size;

    // 哈希函数
    int hashFunction(const K& key) {
        if constexpr (is_same_v<K, int>) {
            return abs(key) % capacity;
        }
        else if constexpr (is_same_v<K, string>) {
            int hash = 0;
            for (char c : key) {
                hash = (hash * 31 + c) % capacity;
            }
            return abs(hash);
        }
        return abs(static_cast<int>(key)) % capacity;
    }

    // 线性探测找到下一个位置
    int probe(int index) {
        return (index + 1) % capacity;
    }

public:
    HashTableOpenAddressing(int cap = DEFAULT_CAPACITY) : capacity(cap), size(0) {
        table.resize(capacity);
    }

    // 插入
    void insert(const K& key, const V& value) {
        if (size >= capacity * 0.7) {  // 负载因子达到0.7时扩容
            cout << "开放地址法哈希表需要扩容" << endl;
            return;  // 简化实现，不进行扩容
        }

        int index = hashFunction(key);

        // 线性探测找到合适位置
        while (!table[index].empty && !table[index].deleted) {
            if (table[index].key == key) {
                // 更新已存在的键
                table[index].value = value;
                return;
            }
            index = probe(index);
        }

        // 插入新元素
        table[index] = Entry(key, value);
        size++;
    }

    // 查找
    bool search(const K& key, V& value) {
        int index = hashFunction(key);
        int originalIndex = index;

        do {
            if (table[index].empty && !table[index].deleted) {
                return false;  // 遇到真正空的位置，说明不存在
            }

            if (!table[index].deleted && table[index].key == key) {
                value = table[index].value;
                return true;
            }

            index = probe(index);
        } while (index != originalIndex);

        return false;
    }

    // 删除（懒删除）
    bool remove(const K& key) {
        int index = hashFunction(key);
        int originalIndex = index;

        do {
            if (table[index].empty && !table[index].deleted) {
                return false;
            }

            if (!table[index].deleted && table[index].key == key) {
                table[index].deleted = true;
                size--;
                return true;
            }

            index = probe(index);
        } while (index != originalIndex);

        return false;
    }

    void printTable() {
        cout << "\n=== 开放地址法哈希表 ===" << endl;
        for (int i = 0; i < capacity; i++) {
            cout << "位置 " << i << ": ";
            if (table[i].empty) {
                cout << "空";
            }
            else if (table[i].deleted) {
                cout << "已删除";
            }
            else {
                cout << "(" << table[i].key << ":" << table[i].value << ")";
            }
            cout << endl;
        }
        cout << "=====================" << endl;
    }
};

// 测试函数
void testHashTable() {
    cout << "=== 链地址法哈希表测试 ===" << endl;
    HashTable<int, string> ht(8);

    // 插入测试
    ht.insert(1, "Apple");
    ht.insert(9, "Banana");   // 可能与1冲突
    ht.insert(17, "Cherry");  // 可能与1、9冲突
    ht.insert(2, "Date");
    ht.insert(10, "Elderberry");

    ht.printTable();

    // 查找测试
    string value;
    if (ht.search(9, value)) {
        cout << "找到键9: " << value << endl;
    }

    // 删除测试
    ht.remove(1);
    cout << "\n删除键1后:" << endl;
    ht.printTable();

    // 触发扩容
    cout << "\n继续插入元素触发扩容:" << endl;
    ht.insert(3, "Fig");
    ht.insert(4, "Grape");
    ht.insert(5, "Honeydew");
    ht.printTable();

    cout << "\n=== 开放地址法哈希表测试 ===" << endl;
    HashTableOpenAddressing<int, string> htOpen(8);

    htOpen.insert(1, "Apple");
    htOpen.insert(9, "Banana");
    htOpen.insert(17, "Cherry");
    htOpen.insert(2, "Date");

    htOpen.printTable();

    // 查找测试
    if (htOpen.search(17, value)) {
        cout << "找到键17: " << value << endl;
    }

    // 删除测试
    htOpen.remove(9);
    cout << "\n删除键9后:" << endl;
    htOpen.printTable();
}

int main() {
    testHashTable();
    return 0;
}