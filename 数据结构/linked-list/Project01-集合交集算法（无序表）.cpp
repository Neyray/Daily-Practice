#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    int a[100000];
    int b[100000];
    int num;
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss1(line1);
    stringstream ss2(line2);
    int i = 0;
    while (ss1 >> num) {
        a[i] = num;
        i++;
    }
    int j = 0;
    while (ss2 >> num) {
        b[j] = num;
        j++;
    }
    int c[100000];
    int k = 0;
    for (int m = 0; m < i; m++) {
        for (int n = 0; n < j; n++) {
            if (a[m] == b[n]) {
                c[k] = a[m];
                k++;
                break; // 保证不重复匹配相同元素
            }
        }
    }
    for (int p = 0; p < k; p++) {
        cout << c[p] << " ";
    }
    return 0;
}