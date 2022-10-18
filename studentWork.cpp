// QUESTION 6:
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string remove_special(string str){
    string new_str = "";
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] >= 'a') && (str[i]) <= 'z'){
            new_str += str[i];
        }
    }
    return new_str;
}
int count_special_str(vector<string> new_strVec, int size){
    int count = 0;
    for(int i = 0; i < size-1; i++){
        if (new_strVec[i].length() == 0){
            count++;
        }
    }
    return count;
}

int count_letter_str(vector<string> strVec, vector<string> new_strVec, int size){
    int count = 0;
    for (int i = 0; i < size-1; i++) {
        if (new_strVec[i] == strVec[i]){
            count++;
        }
    }
    return count;
}

int main() {
    string input = " ";
    int size = 0;
    vector<string> strVec;
    vector<string> new_strVec;
    cout<<"Please enter a non-empty sequence of Strings. Each string should be in a separate line and consists of only lowercase English letters and/or special characters @, #, $, !, &. To indicate the end of the input, enter an empty string in one line."<<endl;
    while (input != ""){
        getline(cin,input);
        strVec.push_back(input);
        size++;
    }
    for (int i = 0; i < size; i++){
        string new_str = remove_special(strVec[i]);
        new_strVec.push_back(new_str);
        if (new_strVec[i].length() != 0){
            cout<<new_strVec[i]<<endl;
        }
    }
    cout<<"Number of Strings in the input sequence that contain only special characters: "<<count_special_str(new_strVec, size)<<endl;
    cout<<"Number of Strings in the input sequence that contain only only lowercase English letters: "<<count_letter_str(strVec, new_strVec, size)<<endl;

    return 0;
}
