#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node{
    int _data;
    Node* _next;
};

class LinkedList{
public:
    int _id;
    string _name;
};

int main(){
    ofstream outstream;
    ifstream instream;

    outstream.open("output.txt");

    string filename;
    cout << "Enter filename:" << endl;
    cin >> filename;
    instream.open(filename);

    // first, we have to "load" the linked list with one record




    return 0;
}