#include <iostream>
using namespace std;

void doubleTriangle(int n){
    char asterisk = '*';
    char space = ' ';
    int asteriskLimit = 1;
    int spaceLimit = 2 * n - 2; //8
    int numOfLines = n * 2 - 1;



    for (int i = 1; i <= numOfLines; i++) { //number of lines
        for (int j = 1; j <= asteriskLimit; j++) {
            cout << asterisk;

        }
        //spaces
        for (int j = 1; j <= spaceLimit; j++) {
            cout << space;
        }

        //other side
        for (int j = 1; j <= asteriskLimit; j++) {
            cout << asterisk;
        }

        //the switch:
        if(i < n){
            asteriskLimit++;
            spaceLimit -= 2;
        }
        else{
            asteriskLimit--;
            spaceLimit += 2;
        }

        cout << endl;

    }

}


int main(){
    doubleTriangle(5);
    return 0;
}