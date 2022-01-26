#include <iostream>
using namespace std;

const double TAX_RATE = 0.10;
int main() {

    double item1 = 0.0, item2 = 0.0, taxRate = 0.0, basePrice = 0.0, discountPrice = 0.0, totalPrice = 0.0;
    char clubMember = 'n';

    cout<<"Enter price of first item: ";
    cin>>item1;
    cout<<"Enter price of second item: ";
    cin>>item2;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>clubMember;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;

    basePrice = item1 + item2;

    if (item1 < item2) {
        item1 = item1 * 0.5;
    } else {
        item2 = item2 * 0.5;
    }

    discountPrice = item1 + item2;

    if (clubMember == 'y' || clubMember == 'Y' ) {
        double discount = discountPrice * TAX_RATE;
        discountPrice = discountPrice - discount;
    }

    totalPrice = ((taxRate / 100.0) * discountPrice) + discountPrice;

    //set precision of cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    //the number in the parens below can set the precision of the decimal points.
    cout.precision(5);
    cout<<"Base price: "<<basePrice<<endl;
    cout<<"Price after discounts: "<<discountPrice<<endl;
    cout<<"Total price: "<<totalPrice<<endl;

    return 0;
}