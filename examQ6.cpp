#include <iostream>
using namespace std;

int findOccurrences(int *arr, int n, int x);
const int size = 5;

int main(){

    int array[size] = {1, 2, 2, 2, 5};
    cout << findOccurrences(array, size, 2);
}

int findOccurrences(int* arr, int n, int x){
    if (int n = 0){
        return 0;
    }else {
        int res = 0;
        if (arr[n-1] == x) {
            return res ++;
        }
        return findOccurrences(arr, int (n-2), int x);
    }
}

int findOccurrences_Ethan(int *arr, int n, int x){
    if (n == 0){
        return 0;
    }
    else{
        if(arr[0] == x){
            return 1 + findOccurrences(arr + 1, n - 1, x);
        }
        else{
            return findOccurrences(arr + 1, n - 1, x);
        }
    }

}