#include <iostream>
#include <vector>
#include <ctime>
#include <functional> // for greater
using namespace std;

template<typename T, class Compare = less<T>>
void insertSort(vector<T>& nums, Compare cmp = less<T>());

template<typename T>
void printVector(vector<T>& nums);

void generateIntVector(vector<int>& nums, int n);

class Base {
    int x;
public:
    Base() :x(-1) {}
    explicit Base(int m_x) :x(m_x) {}
    friend bool operator< (const Base& b1, const Base& b2);
    friend class cmp1;
    friend ostream& operator<<(ostream& os, const Base& b);
    int getX() { return x; }
};

bool operator<(const Base& b1, const Base& b2) {
    return b1.x < b2.x;
}

ostream& operator<<(ostream& os, const Base& b) {
    os << b.x;
    return os;
}

struct cmp1 {
    bool operator()(Base& b1, Base& b2) {
        return b1.x < b2.x;
    }
};

int main() {
    srand((int)(time(0)));
    vector<int> nums1;
    generateIntVector(nums1, 10);
    cout << "Initial value of nums1: ";
    printVector<int>(nums1);
    insertSort<int>(nums1, greater<int>());
    cout << "Sorted value of nums1: ";
    printVector<int>(nums1);

    vector<Base> baseArr;
    for (int i = 0; i < 15; i++) {
        int tmpVal = rand() % 100;
        Base tmpBase(tmpVal);
        baseArr.push_back(tmpBase);
    }
    cout << "Initial value of baseArr: ";
    printVector<Base>(baseArr);
    insertSort<Base>(baseArr, [](Base b1, Base b2) -> bool { return b1.getX() < b2.getX(); });
    cout << "Sorted value of baseArr: ";
    printVector<Base>(baseArr);
    return 0;
}

template<typename T>
void printVector(vector<T>& nums) {
    if (nums.empty()) {
        cout << "The vector is empty!" << endl;
        return;
    }
    cout << nums[0];
    for (int i = 1; i < nums.size(); i++) {
        cout << " " << nums[i];
    }
    cout << endl;
}

void generateIntVector(vector<int>& nums, int n) {
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp = rand() % 100;
        nums.push_back(tmp);
    }
}

template<typename T, class Compare>
void insertSort(vector<T>& nums, Compare cmp) {
    int n = nums.size();
    int i = 1, j;
    T tmp;
    for (; i < n; i++) {
        tmp = nums[i];
        for (j = i - 1; j >= 0 && cmp(tmp, nums[j]); j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = tmp;
    }
}