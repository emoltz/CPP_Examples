#include <iostream>
#include <vector>
using namespace std;

//Q5
class Base{
public:
    Base(){}
    virtual void f(){
        cout << "BASE ";
    }
};

class Derived: public Base{
public:
    Derived(): Base(){}

    virtual void f(){
        cout << "Derived ";
    }
};

void q5(){
    vector<Base> base_objs;
    Base obj1 = Derived();
    Derived obj2 = Derived();
    Base obj3 = Base();

    base_objs.push_back(obj1);
    base_objs.push_back(obj2);
    base_objs.push_back(obj3);

    for (auto base_obj : base_objs){
        base_obj.f();
    }

    obj1.f();
    obj2.f();
    obj3.f();
}

class Person{
public:
    virtual void move() = 0;
};


class A{
private:
    int x;
    int y;
public:
    A(): x(0), y(0){
        cout << "Default constructor" << endl;
    }

    A(int x, int y): x(x), y(y){
        cout << "Constructor with two values" << endl;
    }

    A(const A& other){
        cout << "Copy constructor" << endl;
        x = other.x;
        y = other.y;
    }

};

void q8(){
    A a(1, 2);
    A b = a;
}



int main(){
    q8();
    return 0;
}