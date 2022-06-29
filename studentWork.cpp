#include <iostream>
#include <string>
using namespace std;

void f(int n){
    for (int i = n; i >= 0; i /= 2) {
        for (int j = 0; j < 10000; j++) {
            //O(1) operations
        }
    }
}