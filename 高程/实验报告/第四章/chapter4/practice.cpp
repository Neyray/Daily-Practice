/*设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类型人
员都具有的属性：编号、性别、出生日期、身份证号等。其中“出生日期”声明为一个内嵌子对象“日期”。用成员函数
实现对人员信息的录入和显示。要求包括：构造函数和析构函数、复制 构造函数、内联成员函数、带默认形参值的成
员函数、类的组合。*/
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) :year(y), month(m), day(d) {}

	void show()const {
		cout << year << "-" << month << "-" << day;
	}
};

class Person {
private:
	string ID;
	string gender;
	Date birthday;
	string idNumber;
public:
	//构造函数
	Person(string id, string gender, Date birth, string idN) :
		ID(id), gender(gender), birthday(birth), idNumber(idN) {
		cout << "Constructing Person:" << ID;
	}
	//析构函数
	~Person() {
		cout << "Destructing Person:" << ID << endl;
	}
	//复制构造函数
	Person(Person& p) :ID(p.ID), gender(p.gender), birthday(p.birthday), idNumber(p.idNumber) {
		cout << "Copy Constructing Person:" << ID;
	}
	void show() const {
		cout << "编号: " << ID << ", 性别: " << gender << ", 出生日期: ";
		birthday.show();
		cout << ", 身份证号: " << idNumber << endl;
	}
};



int main() {
	Person p1("001", "male", Date(2001, 01, 27), "11111");
	p1.show();

	Person p2(p1);
	p2.show();
}