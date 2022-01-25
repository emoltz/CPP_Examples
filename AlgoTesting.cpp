#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printVect(vector<int> v){
    for (int i : v){
        cout << i << " ";
    }
}

void Reverse(vector<int> &v){
    int mid = ceil(v.size() /2);
    int end = v.size() - 1;
    for (int i = 0; i < mid; i++){
        swap(v[i], v[end]);
        end -= 1;
    }
}

vector<int> RSort(vector<int> &A){
    for (int i = 0; i < A.size(); i++){
        int count = 0;
        for (int j = 0; j < A.size() - 1; j++){
            if (A[j] > A[j + 1]){
                //should be Reverse(), but this works the same way:
                swap(A[j], A[j + 1]);
                count++;
            }
        }
        if (count == 0){
            break;
        }
        i = 0;
    }


    return A;
}

int main() {
    vector<int> myVect = {10, 9, 8, 1};
    auto result = RSort(myVect);
    printVect(result);
    return 0;
}
