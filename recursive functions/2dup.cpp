#include <iostream>

using namespace std;

bool is2DupSequence(int arr[], int arrSize) {
    if (arrSize == 2) {
        if (arr[0] == arr[1]) {
            return true;
        } else {
            return false;
        }
    }

    if (arr[arrSize - 1] == arr[arrSize - 2]) {
        return is2DupSequence(arr, arrSize - 2);
    } else {
        return false;
    }

}

int main() {
    int arr[6] = {3, 3, 14, 14, 2, 2};
    cout << boolalpha << is2DupSequence(arr, 6);
}