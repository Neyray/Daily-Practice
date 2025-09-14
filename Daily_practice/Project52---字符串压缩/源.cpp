#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string compressed = "";
    int count = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            compressed += s[i - 1];
            if (count > 1) {
                compressed += to_string(count);
            }
            count = 1;
        }
    }

    compressed += s.back();
    if (count > 1) {
        compressed += to_string(count);
    }

    cout << compressed << endl;
    return 0;
}
