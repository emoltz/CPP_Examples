#include <iostream>
#include <vector>
#include <string>
using namespace std;

//example1: remove the even numbers of an array
int* removeEven(int *arr, int arrSize, int &outPosArrSize){

    int newArrayIndex = 0;
    int j = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] %2 != 0){
            outPosArrSize++;
        }
    }
    int* newArray = new int[outPosArrSize];
    for (int i = 0; i < arrSize; i++) {
        //how to determine parity of number?
        if (arr[i] % 2 != 0){
            //if it is odd
            newArray[j] = arr[i];
            j++;

        }
    }
    return newArray;
}

int* findDuplicates(int arr[], int arrSize, int &outSize){
    for (int i = 0; i < arrSize; i++) {

    }
}


//example2: pointer arithmetic.
void pointerArithmetic(){
    int arraySize = 5;
    int *d = new int[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cout << d[i] << " ";
    }


    //is the same as...
    for (int i = 0; i < arraySize; i++){
        cout << *(d + i) << " ";
    }
}

void question(){
    //What does this print?
    int arraySize = 10;
    int *a;
    a = new int[arraySize];
    int i;
    for (i = 0; i < arraySize ; i++) {
        *(a + i) = i;
    }
    for (i = 0; i < arraySize; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
}

int main(){
    int var = 10;
    int *ptr = &var;
    *ptr = 20;
    int **ptrptr = &var;
    **ptrptr = 30;
    cout << var;
}