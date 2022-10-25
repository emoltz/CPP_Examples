#include<iostream>
#include<vector>
using namespace std;

void getUserInput(vector<string> &outputVector);
void removeSymbols(vector<string> userInput, vector<string> &outputArray, int &allSymbol, int &noSymbol);

int main(){

    vector<string> userInputs;
    vector<string> cleanStrings;
    vector<string> charString;
    int allSymbol = 0;
    int noSymbol = 0;

    getUserInput(userInputs);

    removeSymbols(userInputs, cleanStrings, allSymbol, noSymbol);

    cout<<endl;
    for (int i = 0; i<cleanStrings.size(); i++){
        cout<<cleanStrings[i]<<endl;
    }
    cout<<"Number of Strings in the input sequence that contain only special\ncharacters: "<<allSymbol<<endl;
    cout<<"Number of Strings in the input sequence that contain only lowercase\nEnglish letters: "<<noSymbol<<endl;


    return 0;
}

void getUserInput(vector<string> &outputVector){

    string tempString;

    cout<<"Please enter a non-empty sequence of Strings. Each string should\nbe in a separate line and consists of only lowercase English\nletters and/or special characters @, #, $, !, &. To indicate the\nend of the input, enter a -1.\n";
    do{
        cin>>tempString;
        outputVector.push_back(tempString);

    } while (tempString != " ");
    outputVector.pop_back();

}

void removeSymbols(vector<string> userInput, vector<string> &outputArray, int &allSymbol, int &noSymbol){

    vector<int> lineCheck;
    string tempString = "";
    int tempLen;
    string newString;
    int symbolCount;

    for (int i = 0; i < userInput.size(); i++){
        tempString = userInput[i];
        newString = "";
        symbolCount = 0;
        for (int i = 0; i < tempString.length(); i++){
            if (tempString[i] >= 'a' && tempString[i] <= 'z'){
                lineCheck.push_back(1);
            } else {
                lineCheck.push_back(0);
            }
        }
        for (int i = 0; i < lineCheck.size(); i++){
            if (lineCheck[i] == 1){
                newString += tempString[i];
            } else {
                symbolCount++;
            }
        }
        lineCheck.clear();
        if (symbolCount < tempString.length()){
            outputArray.push_back(newString);
        } else {
            allSymbol++;
        }
        if (symbolCount == 0){
            noSymbol++;
        }
    }



}