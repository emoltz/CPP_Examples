//hw11 q4 recursive LowestTravelCost
#include <iostream>
using namespace std;
int LowestTravelCost (int arr [], int arrSize){
  int temp;
  if (arrSize == 3) {
    return arr[arrSize-1]; //Base case is {0, X, Y} and cost is Y
    }
  else {
    if ((arr[0] + arr[2]) < arr[1]) {
      temp = (arr[2]);
      return temp + LowestTravelCost (arr+1, arrSize-1);
      }
    else {
      temp = arr[1];
      return temp + LowestTravelCost (arr+1, arrSize-1);
      }
    }
}
int main() {
  int arrSize = 6;
  int arr[6] = {0, 3, 6, 80, 57, 10}; //should give 73
  int result = LowestTravelCost(arr, arrSize);
  cout << result << endl;
  return 0;
}