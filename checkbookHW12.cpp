#include <iostream>
using namespace std;

class Money{
private:
    long all_cents{};
    int digit_to_int(char c);

public:
    Money() : all_cents(0){};
    void input(istream& ins);
    void output (ostream& outs) const;
    friend Money operator + (const Money& amount1, const Money& amount2);
    friend Money operator - (const Money& amount1, const Money& amount2);
    friend Money operator - (const Money& amount); //returns negative value of money
    friend bool operator == (const Money& amount1, const Money& amount2); //returns true if amount1 and 2 have the same value
    friend bool operator < (const Money& amount1, const Money& amount2); //returns true if amount1 is less than amount2
    friend istream& operator >> (istream& ins, Money& amount); //used to input values of type Money.
    friend ostream& operator << (ostream& outs, const Money& amount); // output values of type Money
};



int main(){

}

void Money::input(istream &ins) {
    char one_char, decimal_point, digit1, digit2;
    //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative.

    ins >> one_char;
    if(one_char == ' '){
        negative = true;
        ins >> one_char; //read '$'
    }
    else{
        negative = false;
        //if input is legal, then one_char == '$'
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Illegal... enter with $X.XX" << endl;
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int((digit2));

    all_cents = dollars * 100 + cents;
    if (negative){
        all_cents = -all_cents;
    }
}
void Money::output(ostream &outs) const {
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if(all_cents < 0){
        outs << "-$" << dollars << '.';
    }else{
        outs << "$" << dollars << '.';
    }
    if (cents < 10){
        outs << '0';
    }
    outs << cents;
}
int Money::digit_to_int(char c){
    return (static_cast<int>(c) - static_cast<int>('0'));
}
Money operator + (const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
bool operator == (const Money &amount1, const Money &amount2) {
    return (amount1.all_cents == amount2.all_cents);
}
Money operator - (const Money &amount1, const Money &amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator - (const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

ostream& operator << (ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    char decimal_point = '.';
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0){
        outs << "-$" << dollars << decimal_point;
    }
    else{
        outs << "$" << dollars << decimal_point;
    }
    if (cents < 10){
        outs << '0';
    }
    outs << cents;
    return outs;
}
bool operator < (const Money& amount1, const Money& amount2){
    if (amount1.all_cents < amount2.all_cents){
        return true;
    }
    else{
        return false;
    }
}
istream& operator >> (istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;
    //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative.

    ins >> one_char;
    if(one_char == ' '){
        negative = true;
        ins >> one_char; //read '$'
    }
    else{
        negative = false;
        //if input is legal, then one_char == '$'
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)){
        cout << "Illegal (operator >> error)" << endl;
        exit(1);
    }
    cents = amount.digit_to_int(digit1) * 10 + amount.digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative){
        amount.all_cents = -amount.all_cents;
    }
    return ins;
}