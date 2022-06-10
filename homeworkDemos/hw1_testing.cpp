#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int num1;
    int num2;
    cout << "Please enter two positive integers, separated by a space:";
    cin >> num1 >> num2;
    cout << num1 << " + " << num2 << " = " << (num1+num2) << endl;
    cout << num1 << " - " << num2 << " = " << (num1-num2) << endl;
    cout << num1 << " * " << num2 << " = " << (num1*num2) << endl;
    cout << num1 << " / " << num2 << " = " << (num1/num2) << endl;
    div_t result1 = div(num1, num2);
    cout << num1 << " div " << num2 << " = " << result1.quot<< endl;
    cout << num1 << " mod " << num2 << " = " << (num1%num2) << endl;
}