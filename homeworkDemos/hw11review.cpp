#include <iostream>
#include <cmath>
using namespace std;

void printTriangle(int n);
void printOppositeTriangle(int n);
void printRuler(int n);
int sumOfSquares(int arr[], int arrSize);
bool isSorted (int arr[], int arrSize);
int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
int jumpIt (int arr[], int size);


void printTriangleIterative(int n){
    //runs in n^3 time
    char star = '*';
    int starLimit = 1, spaceLimit = n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < starLimit; j++) {
            cout << star;
        }
        for (int j = 0; j < spaceLimit; j++) {
            cout << " ";
        }
        cout << endl;
        starLimit++;
        spaceLimit--;


    }
}

void Q1(){
//    printTriangle(4);
//    printTriangleIterative(4);
//    printOppositeTriangle(4);
    printRuler(4);
}


int main(){
    int arr[5] = {4, 3, 1, 2, 5};
    int result = minInArray1(arr, 5);
    cout << result;

    return 0;
}

void printTriangle(int n){
    char star = '*';
    if (n == 1){
        cout << star << endl;
    }
    else{
        printTriangle(n-1);
        for (int i = 0; i < n; i++){
            cout << star;
        }
        cout << endl;
    }
}

void printOppositeTriangle(int n){
    char star = '*';
    if (n == 1){
        cout << star << endl;
    }
    else{
        for (int i = 0; i < n; i++) {
            cout << star;
        }
        cout << endl;
        printOppositeTriangle(n-1);
    }
    for (int i = 0; i < n; i++) {
        cout << star;
    }
    cout << endl;
}

void printRuler(int n){
    char dash = '-';
    if (n == 1){
        cout << dash << endl;
    }
    else{
        printRuler(n-1);
        for (int i = 0; i < n; i++) {
            cout << dash;
        }
        cout << endl;
        printRuler(n - 1);
    }
}

int sumOfSquares(int arr[], int arrSize){
    int currPower;
    if (arrSize == 1){
        return pow(arr[arrSize - 1],2);
    }
    else{
        currPower = pow(arr[arrSize - 1],2);
        return currPower + sumOfSquares(arr, arrSize - 1);
    }
}

bool isSorted (int arr[], int arrSize){
    bool temp = false;
    if (arrSize == 1){
        return true;
    }
    else{
        if (arr[arrSize - 1] < arr[arrSize - 2]){
            return false;
        }
    }
    temp = isSorted(arr, arrSize - 1);
    return temp;
}

int minInArray1(int arr[], int arrSize){
    int minValue;
    if (arrSize == 1){
        return arr[arrSize - 1];
    }
    else{
        minValue = minInArray1(arr, arrSize - 1);
        if (arr[arrSize - 1] < minValue){
            minValue = arr[arrSize - 1];
        }
        return minValue;
    }
}

int minInArray2(int arr[], int low, int high){
    int minValue;
    if (high == low){
        minValue =  arr[low];
        return minValue;
    }
    else{
        minValue = minInArray2(arr, low + 1, high);

        if (arr[low] < minValue){
            minValue = arr[low];
        }
        return minValue;


    }
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