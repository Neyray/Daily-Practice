#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Player {
    int id;
    int F;
    int S;
    bool eliminated = false;
    Player(int id, int F, int S) : id(id), F(F), S(S) {}
};

// 计算选手在第t秒的跑步距离
int getDistance(const Player& player, int t) {
    return player.F + player.S * (t - 1);
}

int main() {
    ifstream inFiles("in.txt");
    if (!inFiles)
        cerr << "error!";
    int n;
    inFiles >> n;

    //存入各个运动员的数据
    vector<Player> players;
    for (int i = 0; i < n; i++) {
        int F, S;
        inFiles >> F >> S;
        players.push_back(Player(i + 1, F, S));
    }

    inFiles.close();

    vector<int> eliminationOrder;

    for (int t = 1; t <= n; t++) {
        //初始化各个数据
        int maxDistance = -1;
        int selectedPlayer = -1;

        for (int i = 0; i < n; i++) {
            if (!players[i].eliminated) {
                int distance = getDistance(players[i], t);
                if (distance > maxDistance) {
                    maxDistance = distance;
                    selectedPlayer = i;
                }
                // 如果距离相同，选择ID最小的
                else if (distance == maxDistance && players[i].id < players[selectedPlayer].id) {
                    selectedPlayer = i;
                }
            }
        }

        players[selectedPlayer].eliminated = true;
        eliminationOrder.push_back(players[selectedPlayer].id);
    }

    // 输出 
    for (int i = 0; i < n; i++) {
        cout << eliminationOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
