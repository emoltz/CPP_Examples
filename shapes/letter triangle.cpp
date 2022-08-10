#include <iostream>
using namespace std;

int main() {
    //question 11, exam 1

    char inLetter;

    cout << "Please enter firstLetter lower-case letter:" << endl;
    cin >> inLetter;

//    char inLetter = 'e';
    char firstLetter = 'a';
    char spaceChar = ' ';
    int letterPosition = ((int)inLetter - (int)firstLetter) + 1;

    int outsideSpaceLimit = ((int)inLetter - (int)firstLetter) + 1;
    int charLimit = 1;

    char currentLetterLower = 'a';
    char currentLetterUpper = 'A';

    //run 5 line loop
    for (int lineCounter = 1; lineCounter <= letterPosition; ++lineCounter) {
        //print outside spaces
        for (int s = 1; s < outsideSpaceLimit; ++s) {
            cout << spaceChar;
        }

        //print characters
        if (lineCounter % 2 == 1){
            for (int c = 0; c < charLimit; ++c) {
                cout << currentLetterLower;
            }
        }else{
            for (int k = 0; k < charLimit; ++k) {
                cout << currentLetterUpper;
            }
        }



        //cut the line
        cout << endl;


        outsideSpaceLimit--;
        charLimit += 2;
        currentLetterLower++;
        currentLetterUpper++;
    }

    return 0;
}