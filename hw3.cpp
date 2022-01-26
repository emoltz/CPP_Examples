#include <iostream>
using namespace std;
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

void Q1(){
    int firstItemPrice, secondItemPrice;
    char clubCard;
    double taxRate, basePrice, priceAfterDiscounts, totalPrice;


    cout << "Enter price of first item: ";
    cin >> firstItemPrice;

    cout << "Enter price of second item: ";
    cin >> secondItemPrice;



}

void Q2(){


}

void Q3(){


}

void Q4(){
    double userInput;
    int roundingMethod;

    cout << "Please enter a Real number:" << endl;
    cin >> userInput;

    int floorRound, ceilingRound, round;
    //the following int makes sure the rounding up works appropriately later
    int roundUp = userInput + 1;

    cout << "Choose your rounding method:" << endl << "1. Floor Round" << endl << "2. Ceiling Round" << endl << "3. Round to the nearest whole number" << endl;
    cin >> roundingMethod;

    //separate the number from its decimal
    double numberBeforeDecimal, numberAfterDecimal;
    numberBeforeDecimal = (int)userInput;
    numberAfterDecimal = userInput - numberBeforeDecimal;


    switch (roundingMethod) {
        //Floor round
        case FLOOR_ROUND:
            cout << numberBeforeDecimal;
            break;

            //Ceiling Round
        case CEILING_ROUND:

            cout << roundUp;
            break;

            //regular round
        case ROUND:
            if (numberAfterDecimal > .5){

                cout << roundUp;
            }
            else{
                cout << numberBeforeDecimal;
            }
            break;
        default: cout << "";

    }
}

int main() {
//    Q1();
//    Q2();
//    Q3();
    Q4();

    return 0;
}
