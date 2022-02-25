#include <iostream>
#include <vector>
using namespace std;

int main_arr();
int main_vector();
string* readText1(int &outTextArrSize);
string* readText2(int &outTextArrSize);
string* readText2test(int &outTextArrSize);
vector<string> readText3();

int main(){
    int n = 5;
    readText2test(n);
    return 0;
}

int main_arr() {
    string* textArr;
    int textArrSize;

    textArr = readText2test(textArrSize);
    //textArr = readText2(textArrSize);

    cout<<"Your text is:"<<endl;
    for(int i=0; i < textArrSize; i += 1)
        cout<<i+1<<". "<<textArr[i]<<endl;

    delete []textArr;
    return 0;
}


string* readText2(int &outTextArrSize){
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

string* readText2test(int &outTextArrSize){
    string* textArr;
    string currLine;
    int textArrSize, textArrPhysicalSize;
    bool seenEndOfText;

    cout<<"Please enter a sequence of lines."<<endl;
    cout<<"End your input with an empty line."<<endl;

    textArr = new string[1];
    textArrSize = 0;
    textArrPhysicalSize = 1;

    int i = 0;
    string* newTextArr = new string[textArrPhysicalSize];

    seenEndOfText = false;
    while(seenEndOfText == false){
        getline(cin, currLine);
        if(currLine == "")
            seenEndOfText = true;
        else{
            newTextArr[i] = currLine;
            i++;
            textArrPhysicalSize++;
        }
    }

    delete []textArr;
    textArrPhysicalSize = textArrPhysicalSize -1;
    textArr = newTextArr;
    outTextArrSize = textArrPhysicalSize;
    return textArr;

}
