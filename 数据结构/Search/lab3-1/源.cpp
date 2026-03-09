/*【问题描述】

设计一个系统，首先对一组包含多个关键字的记录进行快速排序（按主关键字升序），然后支持对次关键字的折半查找。具体要求如下：

输入：包含n条记录，每条记录有主关键字id（唯一）和次关键字score（可能重复）。

排序：按id升序快速排序。

查找：输入一个score值，使用折半查找找到第一个score等于该值的记录id（假设排序后score按id有序）。

【输入形式】

从文件输入：

第一行为记录数n。

接下来n行，每行格式为id score（id唯一，score为整数）。

最后一行为一个待查找的score值。

【输出形式】

输出到文件：

第一行为排序后的所有记录（按id升序），每行格式为id score。

第二行为查找结果：若存在，输出第一个匹配的id；否则输出NOT FOUND。

【样例输入】(in.txt)

5

3 85

1 90

4 85

2 78

5 90

85

【样例输出】(out.txt)

1 90

2 78

3 85

4 85

5 90

3

【要求】

1. 必须手动实现快速排序和折半查找。

2. 折半查找需利用排序后的id有序性，找到第一个满足score条件的记录。

3. 时间复杂度要求：排序 O(nlog⁡n)，查找 O(log⁡n)。

*/
#include <iostream>
#include <fstream>
using namespace std;

struct Record {
    int id;
    int score;
};

// 比较函数：按id升序
bool compareById(const Record& a, const Record& b) {
    return a.id < b.id;
}

// 比较函数：按score升序，score相同时按id升序
bool compareByScore(const Record& a, const Record& b) {
    if (a.score != b.score)
        return a.score < b.score;
    return a.id < b.id;
}

// 快速排序实现
void quickSort(Record arr[], int left, int right, bool (*cmp)(const Record&, const Record&)) {
    if (left >= right) return;

    int i = left, j = right;
    Record pivot = arr[(left + right) / 2]; // 取中间元素为基准

    while (i <= j) {
        while (cmp(arr[i], pivot)) i++; // 找到左侧不小于基准的元素
        while (cmp(pivot, arr[j])) j--; // 找到右侧不大于基准的元素
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // 递归排序左右子数组
    quickSort(arr, left, j, cmp);
    quickSort(arr, i, right, cmp);
}

// 折半查找：在按score排序的数组中查找第一个score等于x的记录id
int binarySearch(Record arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].score < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    // low是第一个>=x的位置
    if (low < n && arr[low].score == x) {
        return arr[low].id; // 返回第一个匹配记录的id
    }
    return -1; // 未找到
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int n;
    fin >> n;
    Record* A = new Record[n]; // 用于按id排序
    Record* B = new Record[n]; // 用于按score排序

    // 读取记录
    for (int i = 0; i < n; i++) {
        fin >> A[i].id >> A[i].score;
    }
    int targetScore;
    fin >> targetScore; // 读取待查找的score

    // 1. 按id升序排序数组A
    quickSort(A, 0, n - 1, compareById);

    // 2. 复制A到B，并按score排序（score相同则按id）
    for (int i = 0; i < n; i++) {
        B[i] = A[i];
    }
    quickSort(B, 0, n - 1, compareByScore);

    // 输出排序后的记录（按id升序）
    for (int i = 0; i < n; i++) {
        fout << A[i].id << " " << A[i].score << endl;
    }

    // 在数组B中折半查找目标score
    int result = binarySearch(B, n, targetScore);
    if (result >= 0) {
        fout << result << endl;
    }
    else {
        fout << "NOT FOUND" << endl;
    }

    delete[] A;
    delete[] B;
    fin.close();
    fout.close();
    return 0;
}