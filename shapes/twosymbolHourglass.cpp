/*
 ******* row 1, 0 space 7 stars 2n - (2*row - 1) stars
  #####  row 2, 1 space 5 hashes
   ***   row 3, 2 space 3 stars
    #    row 4, 3 space 1 star
   ***   row 1, 2 space 3 stars n - row - 1 space
  #####  row 2, 1 space 5 stars 2*row + 1 stars
 ******* row 3, 0 space 7 stars
*/
#include <iostream>
#include <string>

using namespace std;

int main () {
    int n = 7;
    int row, sp;
    int numOfStarsOrHashes = 2 * n - 1;
    int numOfSpaces = 0;
    //top half of hourglass
    for(row = 1; row <= n; row++) {
        for (sp = 1; sp <= numOfSpaces; sp++)
            cout << " ";
        for (sp = 1; sp <= numOfStarsOrHashes; sp++)
        {
            if (row % 2 == 1)
                cout << "*";
            else
                cout <<"#";
        }
        cout << endl;
        numOfSpaces++;
        numOfStarsOrHashes -= 2;
    }
    //bottom half of hourglass:
    numOfSpaces = n - 2;
    numOfStarsOrHashes = 3;
    for (int i =  1; i < n -1; i++) {
        for (sp = 1; sp <= numOfSpaces; sp++) {
            cout <<" ";
        }
        for(int st = 1; st <= numOfStarsOrHashes; st++) {
            if((n % 2 == 0) && (i % 2 == 1))
                cout << "*";
            else if ((n % 2 ==0) && (i % 2 == 0))
                cout << "#";
            else if (i % 2 == 1)
                cout << "#";
            else
                cout << "*";
        }
        numOfSpaces--;
        numOfStarsOrHashes += 2;
        cout << endl;
    }

    return 0;
}