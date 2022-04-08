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

vector<myClass> sortClasses(vector<myClass> myVector){
    vector<myClass> sorted;
    //Bubble Sort O(n^2)
    //Insertion Sort O(n^2)
    //Selection O(n^2)


    return sorted;

}

bool comparator(const myClass& lhs, const myClass& rhs){
    return lhs.j < rhs.j;
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

    // sort( BEGIN, END, COMPARATOR)

    vector<myClass> sortedArray = sortClasses(myVector);


    sort(myVector.begin(), myVector.end(), &comparator);





    return 0;
}