#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Student {
private:
	string name;
	int ID;
	float grades;
public:
	//无参构造函数
	Student() = default;
	//Student():name(""),ID(0),grades(0){}

	//有参构造函数
	Student(string n, int i, float gra) :name(n), ID(i), grades(gra) {}
};
//主函数部分
int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	for (int i = 0; i < 10 - 1; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}


