/*从一个文件中读取数据，并划分好数据类型
* 然后将其输入到另一个文件中
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

//不能加分号，否则会出错
#define Speed_Light 299792458
const double frequency_BDS = 1561.098;
const double frequency_GPS = 1575.42;
const double frequency_Galileo = 1589.74;

struct SatObs {
	string prn;
	string system;
	double L1_observations;
	double L1_wavelength;
	double L1_distance;

	SatObs() = default;
	//有参构造函数
	SatObs(string p, string s, double obs) :
		prn(p), system(s), L1_observations(obs) {
		if (s == "BDS") {
			L1_wavelength = Speed_Light / frequency_BDS;
			L1_distance = L1_wavelength * obs;
		}
		else if (s == "GPS") {
			L1_wavelength = Speed_Light / frequency_GPS;
			L1_distance = L1_wavelength * obs;
		}
		else if (s == "Galileo") {
			L1_wavelength = Speed_Light / frequency_Galileo;
			L1_distance = L1_wavelength * obs;
		}
	}
};

bool compareByDistance(const SatObs& a, const SatObs& b) {
	return a.L1_distance < b.L1_distance;
}

//主函数部分
int main() {
	ifstream inFiles("obs.txt", ios::in);
	if (!inFiles) {
		cerr << "找不到输入文件" << endl;
	}
	ofstream outFiles("newObs.txt", ios::out);
	if (!outFiles) {
		cerr << "找不到输出文件" << endl;
	}

	//建立一个vector对象
	vector <SatObs>satobslist;

	//从文件中读取数据
	string line;
	while (getline(inFiles, line)) {
		istringstream iss(line);
		string sys;
		string pr;
		double observs;

		iss >> pr >> observs;
		if (pr[0] == 'C')sys = "BDS";
		else if (pr[0] == 'G')sys = "GPS";
		else if (pr[0] == 'E')sys = "Galileo";
		else continue;

		//调用构造函数，并建立一个对象，将其添加到动态空间中
		SatObs satObs = { pr, sys, observs };
		satobslist.push_back(satObs);
	}

	sort(satobslist.begin(), satobslist.end(), compareByDistance);

	//输出结果
	for (const auto& satobs : satobslist) {
		outFiles << satobs.prn << "," << satobs.system
			<< "," << fixed << setprecision(3) << satobs.L1_distance << endl;
	}

	inFiles.close();
	outFiles.close();

	return 0;
}
