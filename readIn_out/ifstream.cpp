#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream file;
    file.open("employees.txt");
    char c;
    int numChars = 0;
    vector<char> v;

    for (int i = 0; i < 64; i++) {
        c = file.get();
        cout << c;
    }
//
//    while(file.get(c)){
//        v.push_back(c);
//        numChars++;
//
//    }

//
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i];
//    }

    cout << endl;
    if (file.eof()){
        cout << "True";
    }
    else{
        cout << "False";
    }
}