#include <iostream>
#include <string>
using namespace std;

int main() {

    //Making these variables double to allow for decimals
    double item1, item2;
    double taxRate;
    char clubCard;

    //begin gathering input
    cout << "Enter price of first item: ";
    cin >> item1;

    cout << "Enter price of second item: ";
    cin >> item2;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubCard;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    double basePrice = item1 + item2;

    //apply lower item discount, feed back into original variable
    if (item1 > item2) {
        item2 = item2 / 2;
    }
    else
        item1 = item1 / 2;

    double postBuyOneGetOne = item1 + item2;

    //Club member?
    if (clubCard == 'y' || clubCard == 'Y'){
        postBuyOneGetOne = postBuyOneGetOne + -(postBuyOneGetOne * .1);
    }


    double postTax = postBuyOneGetOne + (postBuyOneGetOne * (taxRate / 100));

    //set precision of cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    //the number in the parens below can set the precision of the decimal points.
    cout.precision(1);

    cout << "Base price: " << basePrice << endl << "Price After Discounts: " << postBuyOneGetOne << endl;

    //set precision of cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    //the number in the parens below can set the precision of the decimal points.
    cout.precision(5);

    //final output:
    cout << "Total Price: " << postTax;




    return 0;
}
