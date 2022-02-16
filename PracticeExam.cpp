#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Question5(){
    //Find sume of each individual digit
    int n;
    int sum = 0;
    
    cout << "Enter a positive integer: ";
    cin >> n;

    while (n!= 0){
        sum += n % 10;
        n /= 10;
    }

    for (int i = n; i != 0; i/=10) {
        sum += n % 10;
        n /= 10;
    }

    cout << sum;
}

void Question6(){
   int n;
   string star = "* ";
   char space = ' ';

   cout << "enter n: ";
   cin >> n;

   int initialSpaces = n - 1;
   int stars = n - initialSpaces;

   for (int i = 0; i < 2 * n + 1; i++){
       for (int j = 0; j <= initialSpaces; j++) {
           cout << " ";
       }
       for (int j = 1; j < stars; j++){
           cout << "* ";
       }
       cout << endl;

       if (i < n){
           initialSpaces--;
           stars++;
       }
       else{
           initialSpaces++;
           stars--;
       }
   }
}

void Question6_1(){
    int i, j, rowNum, space;
    cout<<"Enter the Number of Rows: ";
    cin>>rowNum;
    space = rowNum-1;
    for(i = 1; i <= rowNum; i++){
        for(j=1; j<=space; j++){
            cout<<"_";
        }
        space--;
        for(j=1; j<=(2*i-1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
    space = 1;
    for(i=1; i<=(rowNum-1); i++){
        for(j=1; j<=space; j++){
            cout<<"_";
        }
        space++;
        for(j=1; j<=(2*(rowNum-i)-1); j++){
            cout<<"*";
        }
        cout<<endl;
    }
    cout<<endl;
}

void barnDoor(){
    /*
     *
     * Target shape is below:
     *
        #######
        #$   $#
        # $ $ #
        #  $  #
        # $ $ #
        #$   $#
        #######
    */

    int userInput;
    char hash = '#';
    char dollar = '$';
    char space = ' ';

    userInput = 10;

    //top of door
    for (int i = 0; i < userInput; ++i) {
        cout << hash;
    }
    cout << endl;

    //middle section
    int leftSpaces = 0; // starting with 0 left spaces
    int middleSpaces = userInput - 4; //starting with 3 middle spaces
    int rightSpaces = 0; //starting with 0 right spaces

    for (int lineCount = 1; lineCount <= userInput - 2; ++lineCount) {
        //initial hash
        cout << hash;

        //print left spaces? If so, print those
        for (int j = 0; j < leftSpaces; ++j) {
            cout << space;
        }

        //print left dollar sign
        cout << dollar;

        //print middle spaces?
        for (int x = 0; x < middleSpaces; ++x) {
            cout << space;
        }

        //print right dollar sign? all times except the middle
        if (lineCount != userInput / 2) {
            cout << dollar;
        }

        //print right spaces? if so, print those
        for (int k = 0; k < rightSpaces; ++k) {
            cout << space;
        }

        //final hash
        cout << hash;
        cout << endl;

        if (lineCount < userInput / 2){
            leftSpaces++;
            rightSpaces++;
            middleSpaces -= 2;
        } else{
            leftSpaces--;
            rightSpaces--;
            middleSpaces += 2;
        }

    }
    for (int j = 0; j < userInput; ++j) {
        cout << hash;
    }

}

void circle(int radius)
{

    for (int i = 0; i <= 2 * radius; i++)
    {
        for (int j = 0; j <= 2 * radius; j++)
        {
            double distance = sqrt((double)(i - radius)
                                   * (i - radius) + (j - radius)
                                                    * (j - radius));

            if (distance > radius - 0.5 &&
                distance < radius + 0.5)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void heart(){
    double x, y, size=10;
    string message(" hello there ");
    int print_line = 4;
    if (message.length() % 2 != 0) message += " ";

    for (x=0;x<size;x++)
    {
        for (y=0;y<=4*size;y++)
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );

            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
                cout << "V";
            }
            else cout << " ";
        }
        cout<<"\n";
    }

    for (x=1;x<2*size;x++)
    {
        for(y=0;y<x;y++) cout << " ";

        for (y=0; y<4*size + 1 - 2*x; y++)
        {
            if (x >= print_line - 1 && x <= print_line + 1) {
                int idx = y - (4*size - 2*x - message.length()) / 2;
                if (idx < message.length() && idx >= 0) {
                    if (x == print_line) cout<<message[idx];
                    else cout << " ";
                }
                else cout << "V";
            }
            else cout << "V";
        }
        cout<<endl;
    }
}


int main(){
    barnDoor();
}