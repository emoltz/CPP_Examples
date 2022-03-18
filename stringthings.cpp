#include <iostream>
using namespace std;

int findOccurrences(int* arr, int n, int x);

int main(){
    int arr[6] = {0,1,2,3,4,5};
    int result;
    result = findOccurrences(arr, 6, 0);

    cout<<result<<endl;

    return 0;
}

int findOccurrences(int* arr, int n, int x){
    int counter = 0;
    int i = n-1;
    if (i == 0){
        return counter;
    } else if (arr[i]==x){
        counter++;
    } else {
        counter = findOccurrences(arr, i-1, x);
    }

    return counter;
}