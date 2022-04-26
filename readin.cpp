#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out_stream;
    ifstream in_stream;




    out_stream.open("output.txt");
    in_stream.open("data.txt");
    if (!in_stream){
        cout << "Fail";
    }

    //outputting something to the output file
    out_stream << "Output!!!";

    //reading in characters
     char myChar;
     while (in_stream){
         //getting one character at a time
         myChar = in_stream.get();
         cout << myChar << "-";
     }

    //reading in numbers
     int temp, temp2;
     in_stream >> temp >> temp2;
     cout << temp << " " << temp2;

    //printing to console
     int tempID;
     string tempName;
     while (in_stream >> tempID){
         getline(in_stream, tempName);
         cout << "ID: " << tempID << endl;
         cout << "Name: " << tempName << endl;
     }


    while (in_stream >> tempID){
        getline(in_stream, tempName);
        out_stream << "ID: " << tempID << endl;
        out_stream << "Name: " << tempName << endl;
    }





}