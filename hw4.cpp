#include <iostream>
using namespace std;

void whileLoop(int n){
    //reads positive int n and prints first n even numbers
    int outputNum = 2;
    while(n > 0){
        cout << outputNum << endl;
        n--;
        outputNum += 2;
    }
}

void forLoop(int n){
    int outputNum = 2;
    for(int i = 0; i < n; i++){
        cout << outputNum << endl;
        outputNum += 2;
    }
}

void Q1(){
    int n;

    cout << "Enter n" << endl;
    cin >> n;

//    whileLoop(n);
    forLoop(n);
}

int main(){
    


}