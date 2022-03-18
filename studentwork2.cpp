#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize);

void reverseArray(int arr[], int arrSize);

void removeOdd(int arr[], int& arrSize);

void splitParity(int arr[],int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);#include <iostream>
    using namespace std;

    void reverseArray(int arr[], int arrSize)
    {
        for (int i = arrSize-1; i >= 0; i--)
        {
            cout<<arr[i]<<" ";
        }
        cout << endl;
    }


    void removeOdd(int arr[], int& arrSize)
    {
        for (int i = 0; i < arrSize; i++)
        {
            if (arr[i] % 2 == 0)
            {
                cout << arr[i]<<" ";
            }
        }
        cout << endl;
    }

    void splitParity(int arr[], int arrSize)
    {

        for (int i = 0; i < arrSize; i++)
        {
            if (arr[i] % 2 == 1)
            {
                cout << arr[i] << " ";
            }
        }
        for (int i = 0; i < arrSize; i++)
        {
            if (arr[i] % 2 == 0)
            {
                cout << arr[i] << " ";
            }
        }
    }
    return 0; }

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}


void reverseArray(int arr[], int arrSize)
{
    for (int i = arrSize-1; i >= 0; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

void removeOdd(int arr[], int& arrSize){
    int i = 0, j = 0;

    while(i < arrSize){
        if(arr[i] % 2 == 1){
            i++;
            continue;
        }
        else{
            arr[j] = arr[i];
            i++;
            j++;
        }
    }
    arrSize = j;
}

void splitParity(int arr[],int arrSize){
    int temp = 0,i = 0;

    for(int j=0;i<arrSize;i++){
        if(arr[j]%2!=0){
            temp=arr[j];
            arr[i]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
}
