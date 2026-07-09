#include <iostream>
using namespace std;

class Tree {
public:
    Tree(int a = 1) : age(a) {}
    void grow(int years) {
        age += years;
    }
    void showAge() const {
        cout << "Ê÷ÁäÎª: " << age << " Äê" << endl;
    }
private:
    int age;
};

int main() {
    Tree t(3);
    t.showAge();

    t.grow(5);
    t.showAge();
    return 0;
}
