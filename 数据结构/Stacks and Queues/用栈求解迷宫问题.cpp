#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 4

int mg[MAX][MAX] = { {0,1,0,0},{0,0,1,1},{0,1,0,0},{0,0,0,0} };
int m = 4, n = 4;

int dx[] = { -1,0,1,0 };//x方向上的偏移量
int dy[] = { 0,1,0,-1 };//y方向上的偏移量 

struct Box {
	int i;//行号
	int j;//列号
	int di;//下一可走相邻方块的的方位号
	Box() {}
	Box(int i1, int j1, int d1) :i(i1), j(j1), di(d1) {}
};

bool mgpath(int xi, int yi, int xe, int ye) {
	int i, j, di, i1, j1;
	bool find;
	Box b, b1;

	stack<Box>st;
	//入口方块进栈
	b = Box(xi, yi, -1);
	st.push(b);
	mg[xi][yi] = -1;

	while (!st.empty()) {
		b = st.top();
		if (b.i == xe && b.j == ye) {
			disppath(st);
			return true;
		}
		find = false;
		di = b.di;
		while (di < 3 && find == false) {
			di++;
			i = b.i + dx[di];
			j = b.j + dy[di];
			if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0)
				find = true;
		}
		if (find) {
			st.top().di = di;
			b1 = Box(i, j, -1);
			st.push(b1);
			mg[i][j] = -1;
		}
		else {
			mg[b.i][b.j] = 0;
			st.pop();
		}
	}
	return false;
}

void disppath(stack <Box>& st) {
	Box b;
	vector<Box>apath;
	while (!st.empty()) {
		b = st.top();
		st.pop();
		apath.push_back(b);
	}
	reverse(apath.begin(), apath.end());
	for (int i = 0; i < apath.size(); i++)
		cout << "[" << apath[i].i << "," << apath[i].j << "]";
	cout << endl;
}

int main() {
	int xi = 0, yi = 0, xe = 3, ye = 3;
	if (!mgpath(xi, yi, xe, ye))
		cout << "不存在迷宫路径" << endl;
	return 0;
}