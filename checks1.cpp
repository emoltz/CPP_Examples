#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

using namespace std;

class Money
{
public:
    friend class Checkbook;
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money();
    //Initializes the object so its value represents $0.00.
    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

private:
    long all_cents;
};

class Checkbook{
    friend class Money;
    int checkID;
    vector <int> checkIDs;
    Money checkAmount;
    vector <Money> checkAmounts;
    bool checkCashed;
    vector <bool> checksCashed;
    Money bankGivenBalance;
    Money startingBalance;
    Money depositTotal;
    Money cashedCheckTotal;
    Money notCashedCheckTotal;
    vector <Money> deposits;


public:
    void printCashedChecks(){
        int size = checkIDs.size();
        for(int i = 0;i<size;i++){
            if(checksCashed[i]){
                cout<<"Check ID: "<<checkIDs[i]<<"\n";
                cout<<"Check Amount: "<<checkAmounts[i]<<"\n\n";
            }
        }
    }
    void printNotCashedChecks(){
        int size = checkIDs.size();
        for(int i = 0;i<size;i++){
            if(!checksCashed[i]){
                cout<<"Check ID: "<<checkIDs[i]<<"\n";
                cout<<"Check Amount: "<<checkAmounts[i]<<"\n\n";
            }
        }
    }
    void isBankRight(){
        if(bankGivenBalance==getNewBankBalance()){
            cout<<"\nYour bank calculated your balance correctly!\n";
        }
        else{
            cout<<"\nYour bank messed up!!!!\n";
            cout<<"Bank's Given - Actual Difference: "<<bankGivenBalance-getNewBankBalance()<<"\n";
        }
    }
    //Setters
    void setStartingBalance(Money m){startingBalance = m;}
    void setBankGivenBalance(Money m){bankGivenBalance = m;}
    void setDeposits(){
        Money temp;
        int numOfDeposits;

        cout<<"\nHow many deposits did you have? ";
        cin>>numOfDeposits;
        cout<<"\nPlease enter your "<<numOfDeposits<<" Deposit(s) with a space in between each one: ";

        for(int i =0;i<numOfDeposits;i++){
            cin>>temp;
            depositTotal = depositTotal + temp;
            deposits.push_back(temp);
        }
    }
    void setChecks(){

        while(checkID != -1){
            cout<<"\n\nEnter CheckID (or -1 to finish): ";
            cin>>checkID;
            if(checkID != -1){
                checkIDs.push_back(checkID);
                cout<<"Enter check amount: ";
                cin>>checkAmount;
                checkAmounts.push_back(checkAmount);
                cout<<"Was the check cashed? (1 = True|0 = False): ";
                cin>>checkCashed;
                checksCashed.push_back(checkCashed);
                if(checkCashed){
                    cashedCheckTotal = cashedCheckTotal + checkAmount;
                }
                else{
                    notCashedCheckTotal = notCashedCheckTotal + checkAmount;
                }
            }
        }
    }

    //Getters
    Money getDepositTotal(){return depositTotal;}
    Money getCashedCheckTotal(){return cashedCheckTotal;}
    Money getNewBankBalance(){return startingBalance+depositTotal-cashedCheckTotal;}
    Money getCheckbookBalance(){return startingBalance+depositTotal-cashedCheckTotal-notCashedCheckTotal;}
    Money getBankCheckbookDiff(Money m){return startingBalance+depositTotal-cashedCheckTotal-m;}

};


int digit_to_int(char c);
//Function declaration for function used in the definition of Money::input:
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int ('3') returns 3.

Money::Money(long dollars, int cents){
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }

    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars *100){
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0){
    //Body intentionally blank.
}

int main() {
    Checkbook user;
    Money temp;
    cout << "\nWelcome to the Checkbook Program \n\n";
    cout<<"Please Enter all monetary values in this format: $_.__     (NOTE: My Program will crash if you don't do this)\n";
    cout<<"Examples: $2.09, $0.55, $100.00, etc... Please do not forget the dollar symbol!\n";
    cout<<"\n-----------------------------------------------------------------------------------\n";

    cout<<"Enter your starting balance: ";
    cin>>temp;
    user.setStartingBalance(temp);

    cout<<"\nEnter the balance you recieved from the bank: ";
    cin>>temp;
    user.setBankGivenBalance(temp);

    user.setDeposits();

    user.setChecks();

    cout<<"--------------------------------------------------------------------------------\n";
    temp = user.getCashedCheckTotal();
    cout<<"Cashed Check Total: "<<temp<<"\n";

    temp = user.getDepositTotal();
    cout<<"Deposit Total: "<<temp<<"\n\n";

    temp = user.getNewBankBalance();
    cout<<"New Bank Balance: "<<temp<<"\n";

    temp = user.getCheckbookBalance();
    cout<<"New Checkbook Balance: "<<temp<<"\n";

    temp = user.getBankCheckbookDiff(temp);
    cout<<"Bank-Checkbook Difference: "<<temp<<"\n";

    user.isBankRight();

    cout<<"-------------------------------\n";
    cout<<"List of Cashed Checks:\n";
    user.printCashedChecks();
    cout<<"-------------------------------\n";
    cout<<"List of Uncashed Checks:\n";
    user.printNotCashedChecks();

    return 0;
}



Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}

Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point,
            digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
    ins >> one_char;

    if (one_char == '-'){
        negative = true;
        ins >> one_char; //read '$'
    }

    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.'|| !isdigit(digit1) ||!isdigit(digit2)){
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}

int digit_to_int(char c){
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "- $" << dollars << '.';

    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}
