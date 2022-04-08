#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

// Constants
const int CASHED = 1;
const int NOT_CASHED = 0;
const int FINISHED = -1;

//---------------------------------------------------MONEY CLASS-----------------------------------------------------//
class Money
{
private:
    long all_cents;

public:
    // Constructors
    Money() : all_cents(0) {}
    Money(long dollars) : all_cents(dollars * 100){}
    Money(long dollars, int cents)
    {
        if(dollars*cents < 0)
        {
            cout << "Invalid input for dollars and cents." << endl;
            exit(1);
        }
        all_cents = dollars * 100 + cents;
    }
    double get_value() const
    {
        return (all_cents*0.01);
    }
    // Overloading Operators
    friend Money operator +(const Money& amount1, const Money& amount2)
    {
        Money temp;
        temp.all_cents = amount1.all_cents + amount2.all_cents;
        return temp;
    }
    friend Money operator -(const Money& amount1, const Money& amount2)
    {
        Money temp;
        temp.all_cents = amount1.all_cents - amount2.all_cents;
        return temp;
    }
    friend Money operator -(const Money& amount)
    {
        Money temp;
        temp.all_cents = -amount.all_cents;
        return temp;
    }
    friend bool operator ==(const Money& amount1, const Money& amount2)
    {
        return (amount1.all_cents == amount2.all_cents);
    }
    friend bool operator <(const Money& amount1, const Money& amount2)
    {
        return (amount1.all_cents < amount2.all_cents);
    }
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);
};
int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point, digit1, digit2;   // digits for the amount of cents
    long dollars;
    int cents;
    bool negative;  // set to true if input is negative

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char;    // read '$'
    }
    else
        negative = false;
    // if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if ( one_char != '$' || decimal_point != '.'
         || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);

    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}
//---------------------------------------------------MONEY CLASS-----------------------------------------------------//

//---------------------------------------------------CHECK CLASS-----------------------------------------------------//
class Check
{
private:
    int m_number;
    Money m_amount;
    bool m_is_cashed;

public:
    // Constructors
    Check()
        : m_number(0), m_amount(0.00), m_is_cashed(0) {}

    Check(int check_number, Money check_amount, bool check_cashed)
        : m_number(check_number), m_amount(check_amount), m_is_cashed(check_cashed) {}

    // Can't get the money objects to work right
    // Use this constructor for creating objects for calculating balances as a work around
    Check(Money check_amount)
            : m_number(0), m_amount(check_amount), m_is_cashed(0) {}

    // Get Methods
    const int& GetCheckNumber() const
    { return m_number; }

    const Money& GetAmount() const
    { return m_amount; }

    const bool& GetIsCashed() const
    { return m_is_cashed; }

    // Overloading Operators
    friend Check operator +(const Check& amount1, const Check& amount2)
    {
        Check temp;
        temp.m_amount = amount1.m_amount + amount2.m_amount;
        return temp;
    }
    friend Check operator -(const Check& amount1, const Check& amount2)
    {
        Check temp;
        temp.m_amount = amount1.m_amount - amount2.m_amount;
        return temp;
    }
};

ostream& operator <<(ostream& stream, const Check& info)
{
    stream << "Check #" << info.GetCheckNumber() << " | " << "Amount: " << info.GetAmount();
    return stream;
}

bool Checks_less_than(Check const &l, Check const &r)
{ return l.GetCheckNumber() < r.GetCheckNumber(); }
//---------------------------------------------------CHECK CLASS-----------------------------------------------------//

//------------------------------------------------------MAIN---------------------------------------------------------//

// Function Prototypes
vector<Check> get_deposits_list();
vector<Check> get_checks_list();
double get_deposits_total(const vector<double> &deposits);

int main()
{
    /* Note to TA: Could not get money objects working correctly
     * Needed to create a work-around using check objects
     * which results in some extra code lines. */

    // Get current balance from user
    double current_balance = 0;
    cout << "Please enter current balance: ";
    cin >> current_balance;
    Check old_balance(current_balance);
    cout << old_balance.GetAmount() << endl;
    cout << endl;

    // Get bank balance from user
    double bank_balance = 0;
    cout << "Please enter the balance you received from the bank: ";
    cin >> bank_balance;
    Check banks_balance(bank_balance);
    cout << banks_balance.GetAmount() << endl;
    cout << endl;
//    cout << "Bank Balance: " << bank_balance << endl;
//    cout << endl;

    // Get deposits from user
    vector<Check> deposits_list = get_deposits_list();

    // Get deposits deposits total
    Check deposits_total;
    for (const Check& d : deposits_list)
    {
        deposits_total = d + deposits_total;
    }
    cout << "Deposits Total: ";
    cout << deposits_total.GetAmount() << endl;
    cout << endl;

    // Get checks from user
    vector<Check> checks_list = get_checks_list();

    // Sort checks by check number
    sort(checks_list.begin(), checks_list.end(), &Checks_less_than);

    // Get cashed checks total
    cout << "-------------------" << endl;
    cout << "Cashed Checks List:" << endl;
    cout << "-------------------" << endl;
    Check cashed_checks_total;
    for (Check c : checks_list)
    {
        if (c.GetIsCashed())
        {
            cout << c << endl;
            cashed_checks_total = c + cashed_checks_total;
        }
    }
    cout << endl;
    cout << "Cashed Checks Total: ";
    cout << cashed_checks_total.GetAmount() << endl;
    cout << endl;

    // Get uncashed checks total
    cout << "---------------------" << endl;
    cout << "Uncashed Checks List:" << endl;
    cout << "---------------------" << endl;
    Check uncashed_checks_total;
    for (Check c : checks_list)
    {
        if (!c.GetIsCashed())
        {
            cout << c << endl;
            uncashed_checks_total = c + uncashed_checks_total;
        }
    }
    cout << endl;
    cout << "Uncashed Checks Total: ";
    cout << uncashed_checks_total.GetAmount() << endl;
    cout << endl;

    // Get all checks total
    Check all_checks_total;
    all_checks_total = cashed_checks_total + uncashed_checks_total;
    cout << "----------------------------" << endl;
    cout << "Total Amount of All Checks: " << endl;
    cout << all_checks_total.GetAmount() << endl;


    // Get new bank balance
    cout << "------------------" << endl;
    cout << "New Bank Balance: " << endl;
    Check new_account_balance;
    new_account_balance = old_balance + deposits_total - all_checks_total;
    cout << new_account_balance.GetAmount() << endl;

//    cout << "New Checkbook Balance: " << endl;
//    cout << "Bank & Checkbook Difference: " << endl;

    return 0;
}

vector<Check> get_deposits_list()
{
    vector <Check> deposits;
    double curr_deposit = 0;
    bool finish_deposits = false;
    cout << "Please enter the deposits (enter -1 to finish):" << endl;
    while(!finish_deposits)
    {
        cin >> curr_deposit;
        if (curr_deposit == FINISHED)
        {
            finish_deposits = true;
        }
        else
        {
            deposits.push_back({0,curr_deposit,0});
        }
    }
    return deposits;
}

vector<Check> get_checks_list()
{
    vector<Check> checks;
    int curr_check_num = 0;
    double curr_check_amount = 0;
    bool curr_is_cashed = false;
    bool finish_checks = false;
    cout << "Please enter the details for each check:" << endl;
    while(!finish_checks)
    {
        cout << "Check # (or -1 to finish): ";
        cin >> curr_check_num;
        if (curr_check_num == FINISHED)
        {
            finish_checks = true;
        }
        else
        {
            cout << "Check Amount: ";
            cin >> curr_check_amount;
            cout << "Was Check Cashed (i.e. 1 = Yes, 0 = No)?: ";
            cin >> curr_is_cashed;
            checks.push_back(   // IF I ENTER $ the PROGRAM RUNS AN INFINITE LOOP
                    {curr_check_num, curr_check_amount, curr_is_cashed});
            cout << endl;
        }
    }
    cout << endl;
    return checks;
}
