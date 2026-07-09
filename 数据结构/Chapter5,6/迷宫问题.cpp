#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
//对应左上右下
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int mg[MAX][MAX] = { {0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0} };
int m = 4, n = 4;
//累计迷宫路径数
int cnt = 0;

class Box {
public:
	int i;
	int j;
	Box(int i, int j) :i(i), j(j) {}
};

void mgpath(int xi, int yi, int xe, int ye, vector<Box>path) {
	//将当前坐标加入路径中
	Box b(xi, yi);
	path.push_back(b);

	//标记当前位置已访问
	mg[xi][yi] = -1;

	if (xi == xe && yi == ye) {
		cnt++;
		cout << "迷宫路径" << cnt << ":";
		for (int k = 0; k < path.size(); k++) {
			cout << "(" << path[k].i << "," << path[k].j << ")";
		}
		//标志着一条路径的输出完毕
		cout << endl;
		mg[xi][yi] = 0;
		return;
	}
	else {
		//di代表方向
		int di = 0;
		//遍历四个方向
		while (di < 4) {
			int i = xi + dx[di];
			int j = yi + dy[di];
			if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0) {
				mgpath(i, j, xe, ye, path);
			}
			di++;
		}
		mg[xi][yi] = 0;
	}
}

int main() {
	int xi = 0, yi = 0, xe = 3, ye = 3;
	cout << "所有迷宫路径：" << endl;

	vector<Box>path;
	mgpath(xi, yi, xe, ye, path);
	return 0;
}