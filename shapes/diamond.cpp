#include <iostream>
using namespace std;

int main() {
    //you can set this to anything you like:
    int userInput = 5;

    char letter = 'a';
    char spaceChar = ' ';

    int outsideSpaceLimit = userInput;
    int insideSpaceLimit = 0;

    for (int lineCounter = 1; lineCounter < (userInput * 2); ++lineCounter) {

        //print outside spaces
        for (int o = 1; o < outsideSpaceLimit; ++o) {
            cout << spaceChar;
        }
        //print letter
        cout << letter;
        //print inside spaces
        for (int i = 0; i < insideSpaceLimit; ++i) {
            cout << spaceChar;
        }
        //print letter
        if (lineCounter != 1 && lineCounter != ((userInput * 2)-1)){
            cout << letter;
        }
        cout << endl;
        if (lineCounter < userInput){
            letter++;
            insideSpaceLimit += 2;
            outsideSpaceLimit--;
        }
        else{
            letter--;
            insideSpaceLimit -= 2;
            outsideSpaceLimit++;
        }

    }


    return 0;
}
