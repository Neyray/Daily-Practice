/*【问题描述】

年度学校自行车比赛开始了，ZL是这所学校的学生，他太无聊了，因为他不能骑自行车！因此，他决定干预比赛，他通过以前的比赛视频获得了选手的信息，一个选手第一秒可以跑F米，然后每秒跑S米。每个选手有一条直线跑道，ZL每秒向跑的最远的运动员跑道扔一个钉子，在自行车胎爆炸之后，该选手将被淘汰。如果有多个选手是NO.1，则他总是选择ID最小的选手扔钉子。

【输入形式】

每个测试用例的第一行包含一个整数n（1≤n≤50000），表示选手人数，然后跟随n行，每行包含第i个选手的两个整数Fi（0≤Fi≤500），Si（0<Si≤100），表示该选手第一秒可以跑Fi米，然后每秒跑Si米，i是玩家从1开始的ID。

【输出形式】

    输出n个数字，以空格分隔，第i个数字是选手的ID，该选手将在第i秒结束时被淘汰。

【样例输入】

 3

100 1

100 2

3 100

【样例输出】

1 3 2

【样例说明】

测试数据的文件名为in.txt*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Player {
    int ID;    // 选手ID
    int F;     // 第一秒跑的距离
    int S;     // 每秒增加的距离

    Player() : ID(0), F(0), S(0) {}
    Player(int i, int f, int s) : ID(i), F(f), S(s) {}
};

// 创建一个队列
class Squeue {
public:
    Player* data;  // 存储选手的数组
    int front, rear;  // 队列的头和尾
    int maxSize;  // 队列的最大容量

    Squeue(int ms) : maxSize(ms) {
        data = new Player[maxSize];
        front = rear = -1;
    }

    ~Squeue() {
        delete[] data;
    }

    bool empty() {
        return (rear == front);  // 如果队列为空，front == rear
    }

    // 从尾部入队
    bool push(int i, int f, int s) {
        if (rear == maxSize - 1)  // 如果队列已满
            return false;
        rear++;
        data[rear] = Player(i, f, s);  // 入队
        return true;
    }

    // 从头部出队
    bool pop(Player& e) {
        if (front == rear)  // 如果队列为空
            return false;
        front++;
        e = data[front];  // 出队
        return true;
    }

    // 获取队列中的最大距离并更新
    int get_max_distance(int second) {
        int max_distance = -1;
        for (int i = front + 1; i <= rear; ++i) {
            int distance = data[i].F + data[i].S * (second - 1);
            if (distance > max_distance) {
                max_distance = distance;
            }
        }
        return max_distance;
    }

    // 查找最大距离的选手ID
    int get_eliminated_player_id(int max_distance, int second) {
        for (int i = front + 1; i <= rear; ++i) {
            int distance = data[i].F + data[i].S * (second - 1);
            if (distance == max_distance) {
                return data[i].ID;
            }
        }
        return -1;  // 如果没有找到
    }

    // 清除已淘汰选手
    void remove_eliminated_player(int eliminated_id) {
        for (int i = front + 1; i <= rear; ++i) {
            if (data[i].ID == eliminated_id) {

                // 删除元素：将剩余元素前移
                for (int j = i; j < rear; ++j) {
                    data[j] = data[j + 1];
                }
                rear--;  
                break;
            }
        }
    }
};

int main() {
    // 构造一个队列对象，必须要有大小!!!
    Squeue sq(50000);  // 假设最大选手数为50000
    ifstream inFiles("in.txt");
    if (!inFiles) {
        cerr << "error!" << endl;
        return 1;
    }

    // 输入数据
    int n;
    inFiles >> n;
    for (int i = 0; i < n; ++i) {
        int F, S;
        inFiles >> F >> S;
        sq.push(i + 1, F, S);  // 将选手信息加入队列
    }

    // 每秒开始模拟
    int second = 1;
    while (!sq.empty()) {
        // 获取当前秒数的最大距离
        int max_distance = sq.get_max_distance(second);

        // 获取淘汰的选手ID
        int eliminated_id = sq.get_eliminated_player_id(max_distance, second);

        // 输出淘汰选手的ID
        cout << eliminated_id << " ";

        // 淘汰该选手
        sq.remove_eliminated_player(eliminated_id);

        // 增加秒数
        second++;
    }

    return 0;
}

