#include <iostream>
#include <cmath>
using namespace std;

const int eightam = 480;
const int sixpm = 1080;

int main () {

    int minutes, timehr, timemin, calllengthmin, cost;
    string day, time;

    cout << "What day is it (Mo, Tu, We, Th, Fr, Sa, Su): ";
    cin >> day;
    cout << "What hour did the call start (military time i.e. 2pm = 14): ";
    cin >> timehr;
    cout << "What minute did the call start: ";
    cin >> timemin;
    cout << "How long was the call (minutes): ";
    cin >> minutes;

    calllengthmin = (timehr * 60) + timemin;

    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {

        if (calllengthmin >= eightam && calllengthmin <= sixpm) {
            cost = (double) minutes * 0.4;
        } else {
            cost = (double) minutes * 0.25;
        }
    } else if (day == "Sa" || day == "Su"){
        cost = (double) minutes * 0.15;
    } else {
        cout << "Invalid" << endl;
    }

    cout << "The cost of the call is: $" << cost << endl;

    return 0;
}