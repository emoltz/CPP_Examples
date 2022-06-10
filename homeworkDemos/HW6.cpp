#include <iostream>
#include <cmath>
using namespace std;

int fib(int n){
    int output;
    int value1 = 0, value2 = 1;
    for (int i = 0; i < n; i++) {
        // first n Fib numbers
        output = value1 + value2;
        value1 = value2;
        value2 = output;
    }
    cout << output;
    return output;
}

void printDivisors(int num){
    int output, denominator;

    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0){
            cout << i << " ";
        }
    }

    denominator = sqrt(num);
    for (int i = 1; i <= sqrt(num); ++i) {
        output = num / denominator;
        if (num % output == 0){
            cout << output << " ";
        }
        denominator--;
    }
}

int main(){
    int userInput;

    cout << "Please enter a positive integer >= 2: ";
    cin >> userInput;

    printDivisors(userInput);
    cout << endl;

    return 0;
}