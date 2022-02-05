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

void whileLoop(){
    int i = -3;
    while(i != 5){
        cout << "[i] is not yet 5..." << endl;
        i++;
    }
    cout << "[i] turned 5!";
}

void nestedLoops(){
    int numberOfTimes = 5;
    for (int i = 0; i < numberOfTimes; i++) {
        cout << "___" << endl;
        cout << "Outer " << i + 1 << endl;

        for (int j = 0; j < numberOfTimes; j++) {
            cout << "Inner " << j + 1 << " ";
        }

        cout << endl;
    }
}

void daysInWeek() {
    int weeks = 3, days_in_week = 7;

    for (int i = 1, j = 0; i <= weeks; ++i) {
        cout << "Week: " << i << endl;

        for (; j <= days_in_week; ++j) {
            cout << "    Day:" << j << endl;
        }
    }
}

int main(){
//    liftoff();
//    whileLoop();
//    nestedLoops();
    daysInWeek();
    return 0;
}