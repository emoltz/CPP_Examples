#include <iostream>
#include <vector>
using namespace std;


bool isSorted(int s[], int length){
    if (length == 1){
        return true;
    }
    else{
        if (s[0] >= s[1]){
            bool temp = isSorted(s + 1, length -1);
            if (temp){
                return true;
            }
        }
        else{
            return false;
        }
    }
}

int main(){

    int arr[5] = {60, 50, 30, 20, 10};
    cout << boolalpha << isSorted(arr, 5);

    return 0;

}