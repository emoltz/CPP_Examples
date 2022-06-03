#include <iostream>
using namespace std;


class classA;

class classB{
private:
    int attribute;
    classA* a;
public:
    classB(int newAtt):attribute(newAtt){}
    void anotherClass(classA* a){

    }

};
class classA{
private:
    int firstAttribute;
public:
    int accessor(){
        return firstAttribute;
    }
    classA(int newAtt): firstAttribute(newAtt){}
    void test(classA other){
        int temp = other.firstAttribute;
    }
    void test2(classB b){
        b.attribute;
    }
};





int main(){

}