//折半查找，输出查找序列
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int BinSearch(vector<int>& R, int k, vector<int>& ans) {
	int n = R.size();
	int low = 0, high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		ans.push_back(R[mid]);//放在return前面

		if (k == R[mid]) {
			//注意：！！！如果不能直接返回，一定要设置high/low的变化，不然就会卡在这里
			return mid;
		}
		else if (k < R[mid]) {
			high = mid - 1;
		}
		else if (k > R[mid]) {
			low = mid + 1;
		}
	}

	return -1;//没找到
}

int main() {
	int n;
	ifstream in("in.txt");
	ofstream out("out.txt");

	in >> n;
	vector<int>R, ans;
	
	int num;
	while (in >> num) {
		R.push_back(num);
	}

	int result = BinSearch(R, n, ans);
	if (result == -1)out << "False" << endl;
	else out << "True" << endl;

	for (int s : ans)out << s << " ";

	return 0;
}