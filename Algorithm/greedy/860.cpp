// 柠檬水找零
// 贪心策略：遇到20时，优先选择10+5的策略，因为5更加灵活
#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            ++five;
        } else if (bill == 10) {
            if (five == 0) return false;

            --five;
            ++ten;
        } else {
            if (ten > 0 && five > 0) {
                --ten;
                --five;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}