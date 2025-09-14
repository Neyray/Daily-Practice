#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

bool isPrime(int x) {
	if (x <= 1)return false;
	for (int i = 2; i < sqrt(x); ++i) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int maxPrime(int num) {
	int max_prime = -1;
	for (int i = 2; i < sqrt(num); ++i) {
		while (num % i == 0) {
			if (isPrime(i)) {
				max_prime = max(i, max_prime);
			}
			num /= i;
		}
	}
	if (num > 1 && isPrime(num)) {
		max_prime = max(num, max_prime);
	}
	return max_prime;
}

int main() {
	ifstream inFiles("in.txt");
	if (!inFiles) {
		cerr << "error!";
	}

	//输出文件中整数的个数！！！
	int n;
	inFiles >> n;

	vector<int>numbers(n);
	for (int i = 0; i < n; ++i) {
		inFiles >> numbers[i];
	}

	int max_prime = -1;
	int result = -1;

	for (int i = 0; i < n; ++i) {
		int currentMaxPrime = maxPrime(numbers[i]);
		if (currentMaxPrime > max_prime) {
			max_prime = currentMaxPrime;
			result = numbers[i];
		}
	}

	cout << result << endl;

	inFiles.close();

	return 0;

}