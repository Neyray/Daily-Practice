//编写一个程序，读入一段话，将第一个单词改为大写，并去掉标点符号
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
using std::vector;

int main() {
	string str("hello world,my friends!!!!!!");
	
	
	//先把字符一个一个输出
	for (auto c : str) {
		cout << c << " ";
	}

	//统计标点符号的个数
	decltype(str.size())punct_cnt = 0;
	for (auto c : str) {
		if (ispunct(c))
			punct_cnt++;
	}
	cout << "标点符号的个数为：" << punct_cnt << endl;

	//全部转化为大写字母
	/*for (auto& c : str) {
		c = toupper(c);
	}
	cout << str;*/

	//将第一个字母转化成大写字母，下标法
	if (!str.empty())
		str[0] = toupper(str[0]);

	//将第一个字母转化为大写字母，迭代法
	if (str.begin() != str.end()) {
		auto it = str.begin();
		*it = toupper(*it);
	}


	//将第一个单词转化为大写字母,string::size_type
	for (decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); ++index) {
		str[index] = toupper(str[index]);
	}
	cout << str << endl;

	/*使用迭代器将第一个单词转化为大写字母,string::iterator
	for(auto it=str.begin();it!=str.end()&&!isspace(*it);++it){
	  *it=toupper(*it);
	  }
	
	for(auto it=str.begin();it!=str.end()&&!it->empty();++it)
	
	*/


	vector <int> its{ 1,2,3,4,5,6,7,8,9,10 };
	//输出原来的内容
	for (auto c : its) {
		cout << c << " ";
	}
	cout << endl;

	//向其中添加元素，最好用push_back，少用下标法，容易出错
	for (decltype(its.size())index = 10; index != 20; ++index) {
		its.push_back(index);
	}
	//输出添加后的内容
	for (auto c : its) {
		cout << c << " ";
	}

	return 0;
}

/*总结：1.用auto做前缀时，一般都是指对象
        2.用decltype(str.size()) 做前缀时，一般是用于下标法，指代数量
		3.使用迭代器对数据进行处理时，应使用解引用，即*it，只有指向的时候使用it
		4.对于全部更改string对象的情况，使用引用，即auto & c:str，使用时直接用c，即c=toupper(c)
		5.输出方法：无论是string,vector,数组，都有两种输出方法：
		（1）for(auto c:str)
		cout<<c<<" ";
		 (2)下标法
		 cout<<str[0]<<str[1];

*/