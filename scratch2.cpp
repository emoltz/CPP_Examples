
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int inputInteger;
    int counter = 0;
    vector<int> input;
    vector<int> numberOfDigits;
    vector<int> mostFrequent;
    int mostFrequentDigit = 0;
    int holder;

    cout << "Please enter a non-empty sequence of positive integers. Each\ninteger should be in a separate line.\nTo indicate the end of the input, enter 0 in one line.\n";
    do
    {
        cin >> inputInteger;
        if (inputInteger != 0) {
            input.push_back(inputInteger);
            counter++;
        }

    } while (inputInteger != 0);

    for (int i = 0; i < counter; i++)
    {
        mostFrequent.push_back(0);
        numberOfDigits.push_back(0);
        holder = input[i];
        while (holder != 0) {
            holder /= 10;
            numberOfDigits[i] = numberOfDigits[i] + 1;
        }
    }
    for (int i = 0; i < counter; i++)
    {
        mostFrequent[numberOfDigits[i]]++ ;
    }
    for (int i = 0; i < counter; i++) {
        if (mostFrequent[i] > mostFrequentDigit) {
            mostFrequentDigit = i;
        }
    }

    cout << "The most frequent length is: " << mostFrequentDigit << endl;
    cout << "The positive integers with the most frequent length are:\n";

    for (int i = 0; i < counter; i++) {
        if (numberOfDigits[i] == mostFrequentDigit){
            cout << input[i] << ", ";
        }

    }
    cout << "\b\b";

}