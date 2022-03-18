#include <iostream>
#include <vector>
using namespace std;

void pointers1(){
    //some experimentation
    int x, n;
    int* pointer;
    x = 5;
    n = 5;

    pointer = &x;
    *pointer = 200;
    pointer = &n;
    *pointer = 100;
    cout << x << endl;
    cout << n << endl;

    cout << "________" << endl;
    cout << *pointer << endl;
    cout << &n << endl;
    cout << pointer << endl;
    cout << &pointer << endl;
}

void pointers2(){
    // the point of pointers is MEMORY.
    // a pointer is an INTEGER that stores a MEMORY ADDRESS
    // Think of a delivery man. He needs the address of the house because that's the location of the house.
    // What's the point of pointers? They can allocate memory dynamically. This means the program will be faster and use less memory. They can also be used to do some useful things within functions.
    // In the mailman analogy, you would be able to change the address a package goes to while the mailman is out delivering stuff.
    int var = 8;
    int* pointer = &var;


    cout << *pointer << endl;
    var = 10;
    cout << *pointer; //see?? These are LINKED!

}

void pointers3(){
    //linking values
   int var = 10;
   int *pointer = &var;
   *pointer = 20;

   int **pointer2 = &pointer;
   **pointer2 = 30;


    cout << "_____" << endl;
   cout << **pointer2 << endl;
   cout << var << endl;
   cout << *pointer << endl;

    var = 15;
    cout << "_____" << endl;
    cout << **pointer2 << endl;
    cout << var << endl;
    cout << *pointer << endl;

    *pointer = 50;
    cout << "_____" << endl;
    cout << **pointer2 << endl;
    cout << var << endl;
    cout << *pointer;
}

void pointers4(){
    //referencing and de-referencing

    int var = 20;
    int *pointer = nullptr;

    pointer = &var;

    cout << pointer << endl;
    //dereferenced
    cout << *pointer << endl;

}

void pointerToReference(){
    int var = 5;
    int *pointer = &var;
    cout << &*pointer << endl;
    cout << &var << endl;
}

void useCase1(){
    int *array = nullptr;
    int limit = 5;
    array = new int [limit];
    for (int i = 0; i < limit; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < limit; i++) {
        cout << array[i] << endl;
    }
    delete[] array;


}

void useCase2(){
    cout << "How many numbers do you have?" << endl;
    int *array = nullptr;
    int limit;
    cin >> limit;
    array = new int[limit];

    cout << "Enter your numbers: " << endl;
    for (int i = 0; i < limit; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < limit; i++) {
        cout << array[i] << endl;
    }
    delete[] array;

}

void useCase3(){
    int *pointer = nullptr;
    pointer = new int[10];

    for (int i = 0; i < 10; i++) {
        pointer[i] = i + 1;
    }
    *pointer++;
    *pointer++;
    *pointer++;
    cout << *pointer;
}

int myFunction2(int *p){

}

void vectors(){
    vector<int> myVector;
    myVector = {1, 2, 3, 4, 5};
    myVector.push_back(10);
    for (int i = 0; i < myVector.size(); i++) {
        cout << myVector[i] << endl;
    }
}

string* readText2(int &outTextArrSize){//What do you think the parameter does?
    string* textArr;
    string currLine;
    int textArrSize, textArrPhysicalSize;
    bool seenEndOfText;

    cout<<"Please enter a sequence of lines."<<endl;
    cout<<"End your input with an empty line."<<endl;

    textArr = new string[1];
    textArrSize = 0;
    textArrPhysicalSize = 1;

    seenEndOfText = false;
    while(seenEndOfText == false){
        getline(cin, currLine);
        if(currLine == "")
            seenEndOfText = true;
        else{
            if(textArrSize == textArrPhysicalSize){
                string* newTextArr;
                newTextArr = new string[2*textArrPhysicalSize];
                for(int i=0; i < textArrSize; i += 1)
                    newTextArr[i] = textArr[i];
                delete []textArr;
                textArr = newTextArr;
                textArrPhysicalSize *= 2;
            }
            textArr[textArrSize] = currLine;
            textArrSize += 1;
        }
    }

    outTextArrSize = textArrSize;
    return textArr;
}

int main (){
//    pointers4();
//    pointerToReference();
    vectors();

    return 0;
}