#include <string>
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> mymap;
    mymap.insert(pair<string, string>("Rachel", "123456"));
    mymap.insert(pair<string, string>("Ross", "234567"));
    mymap.insert(pair<string, string>("Joey", "345678"));
    mymap.insert(pair<string, string>("Monica", "456789"));


    string s;
    cout << "input name:";
    cin >> s;


    map<string, string>::iterator p;
    p = mymap.find(s);
    if (p != mymap.end())
        cout << "the phone number:" << p->second << endl;
    else
        cout << " the name does not exist" << endl;
    return 0;
}