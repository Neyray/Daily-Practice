#include <iostream>
using namespace std;

class DataType {
public:
    DataType(char c) : type('c'), ch(c) {}
    DataType(int i) : type('i'), in(i) {}
    DataType(float f) : type('f'), fl(f) {}

    void show() const {
        switch (type) {
        case 'c': cout << "字符型: " << ch << endl; break;
        case 'i': cout << "整型: " << in << endl; break;
        case 'f': cout << "浮点型: " << fl << endl; break;
        }
    }

private:
    char type;
    union {
        char ch;
        int in;
        float fl;
    };
};

int main() {
    DataType a('A');
    DataType b(123);
    DataType c(45.67f);

    a.show();
    b.show();
    c.show();
    return 0;
}


