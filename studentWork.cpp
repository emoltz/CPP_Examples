
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){

    vector <string> vec;

    cout << "Please enter a non-empty sequence of Strings."
         << "Each string should be in a separate line and consists of only alphanumeric"
         << "characters and special characters @, #, $, !, &. To indicate the"
         << "end of the input, enter an empty string in one line." << endl;

    string str;

    do {
        getline(cin, str);
        vec.push_back(str+" ");

    } while(str != "");

    string temp1;
    string temp2 = "";

    for (int i = 0; i< vec.size(); i++){
        temp1 = (vec[i]);

        int j = 0;
        while ((j <temp1.length()) && (temp1[j] == 'a' || temp1[j] == 'A'
                                       || temp1[j] == 'b' || temp1[j] == 'B'
                                       || temp1[j] == 'c' || temp1[j] == 'C'
                                       || temp1[j] == 'd' || temp1[j] == 'D'
                                       || temp1[j] == 'e' || temp1[j] == 'E'
                                       || temp1[j] == 'f' || temp1[j] == 'F'
                                       || temp1[j] == 'g' || temp1[j] == 'G'
                                       || temp1[j] == 'h' || temp1[j] == 'H'
                                       || temp1[j] == 'i' || temp1[j] == 'I'
                                       || temp1[j] == 'j' || temp1[j] == 'J'
                                       || temp1[j] == 'k' || temp1[j] == 'K'
                                       || temp1[j] == 'l' || temp1[j] == 'L'
                                       || temp1[j] == 'm' || temp1[j] == 'M'
                                       || temp1[j] == 'n' || temp1[j] == 'N'
                                       || temp1[j] == 'o' || temp1[j] == 'O'
                                       || temp1[j] == 'p' || temp1[j] == 'P'
                                       || temp1[j] == 'q' || temp1[j] == 'Q'
                                       || temp1[j] == 'r' || temp1[j] == 'R'
                                       || temp1[j] == 'S' || temp1[j] == 'S'
                                       || temp1[j] == 't' || temp1[j] == 'T'
                                       || temp1[j] == 'u' || temp1[j] == 'U'
                                       || temp1[j] == 'v' || temp1[j] == 'V'
                                       || temp1[j] == 'w' || temp1[j] == 'W'
                                       || temp1[j] == 'x' || temp1[j] == 'X'
                                       || temp1[j] == 'y' || temp1[j] == 'Y'
                                       || temp1[j] == 'z' || temp1[j] == 'Z'))  // yes i know this is ugly :(. i can't remember the ascii conversion

        {
            temp2 = temp2+ temp1[j];
            j++;
        }

        vec[i] = temp2;
        temp2 = "";
    }

    int count = 0;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] =="")
            count++;
    }


    for (int i = 0; i < vec.size(); i++){
        if (vec[i] !="")
            cout << vec[i]<< endl;;
    }

    cout << "Number of Strings in the input sequence that contain only numeric characters and special characters: " << count<< endl;

    return 0;

}