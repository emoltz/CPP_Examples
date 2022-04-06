#include <iostream>
#include <vector>
using namespace std;

class myClass{
public:
    int j;
    int i;
    myClass(){
        j = 0;
        i = 0;
    }

};

bool comparator(const myClass& lsh, const myClass& rhs){
    return lsh.j < rhs.j;
}

int main(){
    vector<myClass> myVector;
    myClass one;
    one.j = 3;
    one.i = 1;
    myClass two;
    two.j = 5;
    two.i = 1;
    myClass three;
    three.j = 2;
    three.i = 1;

    myVector.push_back(one);
    myVector.push_back(two);
    myVector.push_back(three);


    std::sort(myVector.begin(), myVector.end(), &comparator);

    for (auto & i : myVector) {
        cout << i.j << endl;
    }





    return 0;
}