//Program reads user input strings and removes the letters/alhabets.
//Program prints the strings after removing the letters/alphabets.
//Program counts how many strings contained no letters/alphabets.
#include <iostream>
#include <string>
using namespace std;

string removeLetters(string str, int &numOfStrings);
void printString(string numString);
int main(){
    string str; //user input
    int *numOfStrings = 0; //Number of input strings
    cout<<"Please enter a non-empty sequence of Strings. Each string should"<<endl;
    cout<<"be in a separate line and consists of only alphanumeric"<<endl;
    cout<<"characters. To indicate the end of the input, enter an empty"<<endl;
    cout<<"string in one line."<<endl;

    getline(cin, str);

    string numOnlyString = removeLetters(str, numOfStrings);
    printString(numOnlyString); //Prints string containing only numbers

    cout<<"Number of Strings in the input sequence which contain no numeric"<<endl;
    cout<<"characters: "<<numOfStrings<<endl;

    return 0;
}
string removeLetters(string str, int &numOfStrings){
    for(int i = 0; i < numOfStrings; i++){
        for(int i = 0; i < str.length(); i++){
            if(str[i] >= '0' || str[i] <= '9'){
                string str = string *numString; //Tried to make dynamic string but not sure that's a thing
                str[i] = numString[i];//Creates string of just numbers
                delete[]str;
            }
            else if(str[i] >= 'a' || str[i] <= 'z'){
                numOfStrings--; //If string contains letters decrease counter for strings of just numbers
            }
        }
    }
    return numOfStrings; //Count of number only strings
}
void printString(string numString){
    for(int i = 0; i < numString.length(); i++){
        cout<<numString[i];
    }
    cout<<endl;
}