#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int countCows(int n) {
	if (n == 1)return 1;
	if (n == 2)return 2;
	if (n == 3)return 3;

	return countCows(n - 1) + countCows(n - 3);
}

int main() {
	ifstream inFiles("in.txt");
	if (!inFiles) {
		cerr << "error!" << endl;
		return -1;
	}

	int n;
	inFiles >> n;

	cout << countCows(n);

	return 0;
}