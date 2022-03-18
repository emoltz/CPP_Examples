#include <iostream>
#include <string>
using namespace std;

const int PASSWORD[5] = {1,2,3,4,5};
const int SIZE_OF_PASSWORD = 5;
const int RAND_RANGE = 3 + 1;
const int PIN_VALUES_SIZE = 10;
const int PIN [PIN_VALUES_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void generateNum(int arr[], int arraySize);
void convertPassword(int password[], int codePassword[], int passwordSize);
void convertIntToArray(int convertFrom, int convertTo[], int arrSize);
bool doArraysMatch(int arr1[], int arr2[], int arr1Size);

int main() {
    //copy the password into a temporary array
    int passwordCopy[SIZE_OF_PASSWORD];
    for (int i = 0; i < SIZE_OF_PASSWORD; ++i) {
        passwordCopy[i] = PASSWORD[i];
    }

    int userInput;
    int userInputArray[SIZE_OF_PASSWORD];
    int numArray[PIN_VALUES_SIZE];

    //GENERATE THE NUMBERS
    generateNum(numArray,PIN_VALUES_SIZE);

    //+++++++ USER INTERFACE DISPLAY +++++++
    cout << "Please enter your PIN according to the following mapping:" << endl << "PIN:\t ";
    for (int i = 0; i < PIN_VALUES_SIZE; ++i) {
        cout << PIN[i] << " ";
    }
    cout << endl << "NUM:\t ";
    for (int i = 0; i < PIN_VALUES_SIZE; ++i) {
        cout << numArray[i] << " ";
    }
    cout << endl;
    //+++++++ END USER INTERFACE DISPLAY +++++

    //GET THE USER INPUT
    cin >> userInput;

    //CONVERT USER INPUT INTO AN ARRAY
    convertIntToArray(userInput, userInputArray, SIZE_OF_PASSWORD);

    //CONVERT PIN TO MATCH NUM[] CODE
    convertPassword(passwordCopy, numArray, SIZE_OF_PASSWORD);

    //IF USERINPUT ARRAY MATCHES NEW PASSWORD... HUZZAH!
    if(doArraysMatch(userInputArray,passwordCopy,SIZE_OF_PASSWORD)){
        cout << "Your PIN is correct";
    }else{
        cout << "Your PIN is not correct";
    }

    return 0;
}

void generateNum(int arr[], int arraySize){
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        arr[i] = rand() % RAND_RANGE;
    }

}
void convertPassword(int password[], int codePassword[], int passwordSize){
    for (int i = 0; i < passwordSize; ++i) {
        password[i] = codePassword[password[i]];
    }
}
void convertIntToArray(int convertFrom, int convertTo[], int arrSize){
    for (int i = arrSize - 1; i >= 0; --i) {
        convertTo[i] = convertFrom % 10;
        convertFrom /= 10;
    }
}
bool doArraysMatch(int arr1[], int arr2[], int arr1Size){
    bool isTrue;

    for (int i = 0; i < arr1Size; ++i) {
        if (arr1[i] != arr2[i]){
            isTrue = false;
        }
        else{
            isTrue = true;
        }
    }
    return isTrue;



}