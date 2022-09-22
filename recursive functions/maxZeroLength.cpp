#include <iostream>
#include <vector>

using namespace std;

int countZeros(int nums[], int len, int startIdx) {
    if (startIdx == len) {
        return 0;
    }
    if (nums[startIdx] == 0) {
        return countZeros(nums, len, startIdx + 1) + 1;
    } else {
        return countZeros(nums, len, startIdx + 1);
    }
}


int maxZeroLength(int nums[], int len, int startIdx) {
    int temp = 0, result = 0;
    while (startIdx < len) {
        if (nums[startIdx] == 0) {
            temp++;
            startIdx++;
        } else {
            if (temp > result) {
                result = temp;
            }
            temp = 0;
            startIdx++;
        }
    }
    if (temp > result) {
        result = temp;
    }
    return result;
}

int maxZeroLength2(int nums[], int len) {
    int res = 0, cnt = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] == 0) {
            res = max(res, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return res;
}

int maxZeroLengthRecursive(int *nums, int len, int startIdx) {
   if(startIdx == len){
       return 0;
   }
   int maxLen = 0;
   while (startIdx < len && nums[startIdx++] == 0){ //if it's not true, startIndex will still increment
       maxLen++;
   }
   return max(maxLen, maxZeroLengthRecursive(nums, len, startIdx));
}

int main() {
    int arr[6] = {0, 0, 1, 1, 0, 0};
//    vector<int> arr = {0, 0, 1, 0, 0, 0};
//    cout << maxZeroLength(arr, 6, 0);
//    cout << maxZeroLengthRecursive(arr, 6, 0);
    cout << countZeros(arr, 6, 0);
}