//两个大数相乘
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int m = num1.size(), n = num2.size();
    vector<int> res(m + n, 0);

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    string ans = "";
    for (int num : res) {
        if (!(ans.empty() && num == 0)) {
            ans += to_string(num);
        }
    }

    return ans.empty() ? "0" : ans;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiply(num1, num2) << endl;
    return 0;
}