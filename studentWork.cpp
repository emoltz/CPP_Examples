#include <iostream>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

void printArray(int* arr, int size);
void resizeArray(int*& arr, int& arrSize);

int main() {
    int arrSize = 0;
    int* arr = nullptr;

    resizeArray(arr, arrSize);

    int numOfPositives1;
    int* retArr1 = getPosNums1(arr, arrSize, numOfPositives1);
    cout<<"Version 1:"<<endl;
    printArray(retArr1, numOfPositives1);

    int numOfPositives2 = 0;
    int* outPosArrSizePtr2 = &numOfPositives2;
    int* retArr2 = getPosNums2(arr, arrSize, outPosArrSizePtr2);
    cout<<"Version 2:"<<endl;
    printArray(retArr2, *outPosArrSizePtr2);

    int numOfPositives3 = 0;
    int* outPosArr3 = nullptr;
    getPosNums3(arr, arrSize, outPosArr3, numOfPositives3);
    cout<<"Version 3:"<<endl;
    printArray(outPosArr3, numOfPositives3);

    int numOfPositives4 = 0;
    int* ptrToNumOfPositives4 = &numOfPositives4;
    int* firstDegreePointerToPosArr4 = nullptr;
    int** secondDegreePointerToPosArr4 = &firstDegreePointerToPosArr4;
    getPosNums4(arr, arrSize, secondDegreePointerToPosArr4, ptrToNumOfPositives4);
    cout<<"Version 4:"<<endl;
    printArray(*secondDegreePointerToPosArr4, *ptrToNumOfPositives4);

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize++;
        }
    }

    int* positives = new int[outPosArrSize];

    for (int originalCounter = 0, posCounter = 0; originalCounter < arrSize; originalCounter++) {
        if (arr[originalCounter] > 0) {
            positives[posCounter++] = arr[originalCounter];
        }
    }

    return positives;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            *outPosArrSizePtr += 1;
        }
    }

    int* positives = new int[*outPosArrSizePtr];

    for (int originalCounter = 0, posCounter = 0; originalCounter < arrSize; originalCounter++) {
        if (arr[originalCounter] > 0) {
            positives[posCounter++] = arr[originalCounter];
        }
    }

    return positives;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize += 1;
        }
    }

    int* positives = new int[outPosArrSize];

    for (int originalCounter = 0, posCounter = 0; originalCounter < arrSize; originalCounter++) {
        if (arr[originalCounter] > 0) {
            positives[posCounter++] = arr[originalCounter];
        }
    }

    outPosArr = positives;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    //count number of positives
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            *outPosArrSizePtr += 1;
        }
    }

    //create array of positive numbers
    int* ptrToPosArr = new int[*outPosArrSizePtr];

    //store positive values in the new positive array
    for (int originalArrCounter = 0, posArrCounter = 0; originalArrCounter < arrSize; originalArrCounter++) {
        if (arr[originalArrCounter] > 0) {
            ptrToPosArr[posArrCounter++] = arr[originalArrCounter];
        }
    }

    *outPosArrPtr = ptrToPosArr;
    //things that will still exist after this function ends: first and second degree pointers, array values stored on the heap, numOfPositives4
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void resizeArray(int*& arr, int& arrSize) {
    cout<<"Enter length of array: ";
    cin>>arrSize;

    int* temp = new int[arrSize];

    int input;

    cout<<"Enter array values separated by a space:"<<endl;
    for (int i = 0; i < arrSize; i++) {
        cin>>input;
        temp[i] = input;
    }

    delete [] arr;
    arr = temp;
}