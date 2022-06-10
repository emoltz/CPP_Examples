// ma6934_hw3_q6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string startTime, day;
    int minutes;
    double cost;
    cout << "Please enter the time when the call started in 24-hour notation ex: 13:30  : ";
    cin >> startTime;
    cout << "please enter the day of the week :(Mo Tu We Th	Fr Sa Su): ";
    cin >> day;
    cout << "Please enter the number of minutes: ";
    cin >> minutes;

    if (tolower(day[0]) == 's') {
        cost = minutes * 0.15;
    }
    else if (startTime > "8:00" && startTime < "18:00") {
        cost = minutes * 0.40;

    }
    else {
        cost = minutes * 0.25;

    }
    cout << " cost is: " << cost;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file