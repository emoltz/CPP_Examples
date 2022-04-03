#include <iostream>
using namespace std;

typedef class myClass{
    int i;
    double f;
} myClassTypeDefName;

class AnotherClass{
    int i;
    double f;
};
typedef AnotherClass AnotherClassTypeDef;

int main(){

    myClassTypeDefName f;

    return 0;
}