#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
#include <algorithm>
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

class Check{
private:
    int checkNum{};
    bool checkCashed = false;
public:
    Money checkAmount{};
    Check() : checkNum(), checkAmount(), checkCashed() {}
    int setCheckNumber(int newNumber){checkNum = newNumber;return checkNum;}
    int getCheckNumber() const{return checkNum;}
    void setCheckCashed(string& answer);
    bool getCheckCashed() const;
    friend bool operator < (const Check& amount1, const Check& amount2); //returns true if amount1 is less than amount2
};

int main() {
    int numberOfChecks;
    long enteredCheckNumber;
    string cashed;

    cout << "Input number of checks:" << endl;
    cin >> numberOfChecks;
    Check* userChecks;
    userChecks = new Check[numberOfChecks];

    vector<Check>listOfCashedChecks;
    vector<Check>listOfUncashedChecks;

    for (int i = 0; i < numberOfChecks; i++) {
        cout << "For check index " << i << ", please enter the check number: ";
        cin >> enteredCheckNumber;
        userChecks[i].setCheckNumber(enteredCheckNumber);
        cout << "Enter the amount of check (index " << i << ")? Enter in format $X.XX" << endl;
        userChecks[i].checkAmount.input(cin);
        cout << "Has it been cashed? Yes or no." << endl;
        cin >> cashed;
        userChecks[i].setCheckCashed(cashed);

        if (!userChecks[i].getCheckCashed()){
            listOfUncashedChecks.push_back(userChecks[i]);
        }
        else{
            listOfCashedChecks.push_back(userChecks[i]);
        }
    }

    cout << "Please enter old bank account balance as $X.XX:" << endl;
    Money oldAccountBalance;
    oldAccountBalance.input(cin);

    cout << "Please enter current balance:" << endl;
    Money currentBalance;
    currentBalance.input(cin);

    cout << "Please enter number of deposits:" << endl;
    int numberOfDeposits;
    cin >> numberOfDeposits;

    cout << "Please enter each deposit amount in new line:" << endl;
    Money* deposits;
    Money totalOfDeposits;
    deposits = new Money[numberOfDeposits];
    //fillMoneyArray member function here?
    for (int i = 0; i < numberOfDeposits; i++) {
        deposits[i].input(cin);
    }

    cout << "Total checks cashed: " << listOfCashedChecks.size() << endl;
    cout << "Total uncashed checks: " << listOfUncashedChecks.size() << endl;

    Money totalOfCashedChecks, totalOfUncashedChecks;
    Money newAccountBalance;

    cout << "Total of cashed checks: " << endl;
    for (int i = 0; i < listOfCashedChecks.size(); i++) {
        totalOfCashedChecks = totalOfCashedChecks + listOfCashedChecks[i].checkAmount;
    }
    for (int i = 0; i < listOfUncashedChecks.size(); i++) {
        totalOfUncashedChecks = totalOfUncashedChecks + listOfUncashedChecks[i].checkAmount;
    }
    totalOfCashedChecks.output(cout);
    cout << endl;

    cout << "Total of deposits: " << endl;
    for (int i = 0; i < numberOfDeposits; i++) {
        totalOfDeposits = totalOfDeposits + deposits[i];
    }
    totalOfDeposits.output(cout);
    cout << endl;

    newAccountBalance = oldAccountBalance + totalOfDeposits - totalOfCashedChecks;
    cout << "Your new balance after deposits is: " << endl;
    newAccountBalance.output(cout);
    cout << endl;

    cout << "Difference between bank and your balance: " << endl;
    Money difference;
    difference = newAccountBalance - currentBalance;
    difference.output(cout);
    cout << endl;

    //SORTING!
    sort(listOfCashedChecks.begin(),listOfCashedChecks.end());
    sort(listOfUncashedChecks.begin(),listOfUncashedChecks.end());

    //listing checks:
    cout << "__________LISTS______________" << endl;
    cout << endl << "List of cashed checks:" << endl;
    cout << "ID\tAmount\t \n";
    for (int i = 0; i < listOfCashedChecks.size(); i++) {
        cout << listOfCashedChecks[i].getCheckNumber() << "\t";
        listOfCashedChecks[i].checkAmount.output(cout); cout << "\t";
        cout << endl;
    }

    cout << endl << "List of uncashed checks:" << endl;
    cout << "ID\tAmount\t\n";
    for (int i = 0; i < listOfUncashedChecks.size(); i++) {
        cout << listOfUncashedChecks[i].getCheckNumber() << "\t";
        listOfUncashedChecks[i].checkAmount.output(cout); cout << "\t";
        cout << endl;
    }
    delete[] deposits;
    delete[] userChecks;

    return 0;
}

//__________FUNCTION DEFINITIONS__________//

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


void Check::setCheckCashed(string& answer){
    if (answer == "Yes" || answer == "yes" || answer == "Y" || answer == "y"){
        checkCashed = true;
    }
    else if (answer == "No" || answer == "no" || answer == "N" || answer == "n"){
        checkCashed = false;
    }
    else{
        cout << "ERROR: Please use yes or no (or y or n) to denote whether the check has been cashed. Common man. Don't be weird. Now you have to start over. :(" << endl;
        exit(1);
    }
}

bool Check::getCheckCashed() const {
    if (checkCashed){
        return true;
    }
    else{
        return false;
    }
}

bool operator<(const Check &amount1, const Check &amount2) {
    if (amount1.getCheckNumber() < amount2.getCheckNumber()){
        return true;
    }
    else{
        return false;
    }
}
