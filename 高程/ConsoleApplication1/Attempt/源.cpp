#include <iostream>
#include <vector>
using namespace std;

int main() {
	float a, b = 4.8f;

	int i;

	i = b / 3;

	a = b / 3;

	cout << "i=" << i << ",a=" << a << endl;

	


	int score;
	if (score >= 85) {
		cout << "ÓÅ";
	}
	else if (score < 85 && score >= 75) {
		cout << "Á¼";
	}
	else if (score < 75 && score >= 60) {
		cout << "ÖÐ";
	}
	else {
		cout << "²î";
	}

	return 0;
}