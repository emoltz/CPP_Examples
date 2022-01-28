#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> &A){
    int comparisons = 0, swaps = 0;

    for(int i = 1; i < A.size(); i++){
        for(int j = i; j >= 1; j--){
            comparisons++;
            if(A[j] < A[j-1]){
                swaps++;
                swap(A[j], A[j-1]);
            }
            else{
                break;
            }
        }
    }
    cout << "Comparisons: " << comparisons << " ::: " << "Swaps: " << swaps << endl;
    return A;
}

int main(){
    vector<int> nums = {8, 7, 6, 5, 4, 3, 2, 1};
    InsertionSort(nums);
    for (int i: nums){
        cout << i;
    }

}