#include <iostream>
#include <vector>
using namespace std;

void resizeArr(int*& arr, int arrSize, int newArrSize);
int main1();
int main2();
int main(){

    main1();
    cout << endl;
    main2();

    return 0;

}

void resizeArr(int*& arr, int arrSize, int newArrSize) {

    int* temp = new int[newArrSize];

    for (int i = 0; i < arrSize; i++)
        temp[i] = arr[i];

    delete[] arr;
    arr = temp;

}

int main1() {

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    int userInput = 0;
    int size = 10;
    int userArrCount = 0;
    int* userInputArr = new int[10];

    while (userInput >= 0) {

        cin >> userInput;

        if (userArrCount <= size) {

            userInputArr[userArrCount] = userInput;
            userArrCount++;

        }
        else {

            resizeArr(userInputArr, size, size * 2);
            userInputArr[userArrCount] = userInput;
            userArrCount++;
            size *= 2;

        }

    }

    int search;

    cout << "Please enter a number you want to search." << endl;
    cin >> search;

    int* finder = new int[1];
    int finderSize = 1;
    int finderIndexPos = 0;

    for (int userInputArrPos = 0; userInputArrPos < userArrCount; userInputArrPos++) {

        if (userInputArr[userInputArrPos] == search) {

            finder[finderIndexPos] = userInputArrPos + 1;
            finderIndexPos++;

        }

        if (finderIndexPos == finderSize) {

            resizeArr(finder, finderSize, finderSize * 2);
            finderSize *= 2;

        }

    }

    if (finderSize == 1) {

        cout << search << " does not appear in this list.";

    }
    else {

        cout << search << " shows in lines ";

        for (int i = 0; i < finderIndexPos; i++) {

            if (i == finderIndexPos - 1)
                cout << finder[i] << ".";
            else
                cout << finder[i] << ", ";

        }

    }

    delete[] userInputArr;
    userInputArr = nullptr;
    delete[] finder;
    finder = nullptr;

    return 0;

}

int main2() {

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    int userInput = 0;
    vector<int> userInputArr;

    while (userInput >= 0) {

        cin >> userInput;

        userInputArr.push_back(userInput);

    }

    int search;

    cout << "Please enter a number you want to search." << endl;
    cin >> search;

    vector<int> finder;
    int listTracker = 1;

    for (int i = 0; i < userInputArr.size(); i++) {

        if (userInputArr[i] == search) {

            finder.push_back(i + 1);
            listTracker++;

        }

    }

    if (listTracker == 1) {

        cout << search << " does not appear in this list.";

    }
    else {

        cout << search << " shows in lines ";

        for (int i = 0; i < finder.size(); i++) {

            if (i == finder.size() - 1)
                cout << finder[i] << ".";
            else
                cout << finder[i] << ", ";

        }

    }

    return 0;

}
