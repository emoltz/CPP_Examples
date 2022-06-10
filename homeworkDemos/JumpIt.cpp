#include <iostream>
using namespace std;

const int ARR_SIZE = 6;
int jumpIt (int arr[], int size);

int main() {
    int arr[ARR_SIZE] = {0, 3, 80, 6, 57, 10};
    int totalCost;
    totalCost = jumpIt(arr, ARR_SIZE);
    cout << totalCost;

    return 0;
}

int jumpIt (int arr[], int size) {
    int totalCost = arr[size-1];

    if(size == 1 || size == 0){
        totalCost += arr[size - 1]; //10 at the end/final value
        return totalCost;
    }
    else{
        if (jumpIt(arr, size - 1) < jumpIt(arr, size - 2)){
            totalCost += jumpIt(arr,size - 1);
        }
        else{
            totalCost += jumpIt(arr, size - 2);
        }
    }
    return totalCost;
}