//
//  era8366_hw11_q4.cpp
//  Tandon_Bridge_Program
//
//  Created by Eric Acerno on 3/24/22.
//

#include <iostream>
using namespace std;
const int BOARD_SIZE = 6;

int jumpItCost(int arr[], int startIndex, int arrSize);
int main(){
    int arr[8] = {0, 56, 55, 54, 53, 52, 51, 50};
    int arrSize = 8;



    cout<<jumpItCost(arr, 0, arrSize)<<endl;

    return 0;
}
int jumpItCost(int arr[], int startIndex, int arrSize){
    if(startIndex == arrSize - 1)
        return 0;
    if(startIndex == arrSize - 2)
        return arr[startIndex + 1];

    return min(arr[startIndex + 1] + jumpItCost(arr, startIndex + 1, arrSize), arr[startIndex + 2] + jumpItCost(arr, startIndex + 2, arrSize));

}

