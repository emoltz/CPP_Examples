#include <iostream>
#include <vector>
using namespace std;
// POINT OF POINTERS! -> Memory.
// pointers are just an INTEGER that stores a MEMORY ADDRESS

void pointers1(){
    int var = 10;
    int *pointer = &var;

    *pointer = 12;
    cout << *pointer << endl;

}

void pointers2(){
    int x, n;
    int *pointer;
    x = 5;
    n = 5;

    pointer = &x;
    *pointer = 200;

    x = 100;

    cout << x << endl;
}

void pointers3(){
    int var = 10;
    int *pointer = &var;

    int **pointer2 = &pointer;
    **pointer2 = 30;

    cout << "_____" << endl;
    cout << **pointer2 << endl;
    cout << var << endl;
}

void pointers4(){
    //referencing and de-referencing
    int var = 20;
    int *pointer = nullptr;

    pointer = &var;

    cout << &var << endl;
    cout << &pointer << endl;
}

void useCase1(){
   cout << "How many numbers do you have?" << endl;
   int *array = nullptr;
   int arraySize;
   cin >> arraySize;
   array = new int[arraySize];

   cout << "Enter your numbers: " << endl;
    int userInput;
    for (int i = 0; i < arraySize; i++) {
        cin >> userInput;
        array[i] = userInput;
    }

    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << endl;
    }

    delete[] array;
}

void useCase2(){
    string *array = nullptr;
    array = new string[10];
}

string* useCase3(int &outTextArrSize){ //pass by reference
    string* textArray = new string[1];
    string currLine;
    int textArraySize = 0;
    int textArrayPhysicalSize = 1;

    cout << "Please enter a sequence of lines:" << endl;
    cout << "End your input with an empty line" << endl;
    bool end = false;

    while(end == false){
        // when someone types in a "" -> then it'll break out of the loop
        getline(cin, currLine);
        if(currLine == ""){
            end = true;
        }
        else{
            if(textArraySize == textArrayPhysicalSize){ //is the array full?
                string *newTextArray = nullptr;
                newTextArray = new string[2 * textArrayPhysicalSize];
                for (int i = 0; i < textArraySize; i++) {
                    newTextArray[i] = textArray[i];
                }
                delete []textArray;
                textArray = newTextArray;
                textArrayPhysicalSize *= 2;
            }
            textArray[textArraySize] = currLine;
            textArraySize++;
        }
    }
    outTextArrSize = textArraySize;
    return textArray;

}

void vectorPractice(){
    vector<int> array = {1, 2, 3};
    array.push_back(4);
    array.size();

    int *pointer = nullptr;

}

void final(){
    int *pointer= nullptr;
    pointer = new int[10];

    for (int i = 0; i < 10; i++) {
        pointer[i] = i + 1;
    }

    cout << *pointer;
}

int main(){
//    useCase1();
//    vectorPractice();
    final();
    return 0;
}


