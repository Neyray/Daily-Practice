// 区间调度问题 - 贪心算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int end;
    int id;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].end;
        activities[i].id = i + 1;
    }

    sort(activities.begin(), activities.end(), compare);

    vector<int> selected;
    selected.push_back(activities[0].id);
    int lastEnd = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            selected.push_back(activities[i].id);
            lastEnd = activities[i].end;
        }
    }

    cout << selected.size() << endl;
    for (int id : selected) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}