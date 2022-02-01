#include <iostream>
using namespace std;

void liftoff(){
    for (int i = 3; i > 0; i--) {
        cout << i << ", ";
    }
    cout << "Blast off!";
}

void loop1(){
    int limit = 5;

    for (int i = 0; i < limit; i++){
        cout << "This loop has run " << i + 1 << " time(s)!" << endl;
    }
}

void sumLoop(){

    int numbersToSum = 5;
    int sum = 0;
    for (int i = 1; i < numbersToSum; i++) {
        sum += i;
    }
    cout << sum;
    
}

void iterate(){
    int nums[5] = {10, 11, 12, 13, 14};
    for (int i = 0; i < 5; i++) {
        cout << nums[i] << endl;
    }
}

int main(){
    liftoff();

    return 0;
}