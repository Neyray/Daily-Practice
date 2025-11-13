#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 0)return false;
	if (n == 1)return true;

	int i = 1;
	while (i * i <= n) {
		if (n % i == 0 && i != 1) {
			return true;
		}
		i++;
	}

	return false;
}

int main() {
	int n;
	cin >> n;


	bool result = isPrime(n);
	cout << result << endl;

	return 0;
}