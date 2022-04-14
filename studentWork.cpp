#include <iostream>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

class Money {
private:
    long all_cents;
public:
    Money(long dollars, int cents);
    Money(long dollars): all_cents(dollars * 100) {};
    Money() :all_cents(0) {};
    friend Money operator+(const Money& amount1, const Money& amount2);
    friend Money operator-(const Money& amount1, const Money& amount2);
    friend bool operator==(const Money& amount1, const Money& amount2);
    double get_value() { return all_cents * 0.01; };
    friend istream& operator>>(istream& ins, Money& amount);
    friend ostream& operator<<(ostream& outs, const Money& amount);
};

class Check {
private:
    int number;
    bool is_cashed;
    Money amount;
public:
    Check() :number(0), is_cashed(false), amount(Money()) {};
    Check(int number, bool is_cashed, long dollars, int cents) :number(number), is_cashed(is_cashed), amount(Money(dollars, cents)) {};
    Check(int number, bool is_cashed, long dollars) :number(number), is_cashed(is_cashed), amount(Money(dollars)) {};
    int get_number() { return number; };
    bool get_is_cashed() { return is_cashed; };
    Money get_amount() { return amount; };
    void set_number(int number) { this->number = number; };
    void set_is_cashed(bool is_cashed) { this->is_cashed = is_cashed; };
    void set_amount(const Money& amount) { this->amount = amount; };
    friend bool operator<(const Check& lhs, const Check& rhs);
    friend istream& operator>>(istream& ins, Check& check);
    friend ostream& operator<<(ostream& outs, const Check& check);
};

int digit_to_int(char c);
Money get_cashed_check_total(Check* checks, int num);
Money get_uncashed_check_total(Check* checks, int num);
Money get_deposits_total(Money* money, int num);
vector<Check> get_list_cashed_checks(Check* checks, int num);
vector<Check> get_list_uncashed_checks(Check* checks, int num);
void print_checks(vector<Check> checks);

int main() {
    Money starting_balance, balance_from_bank;
    int amount_of_deposits, amount_of_checks;

    cout << "Enter starting balance (format: $##.##): ";
    cin >> starting_balance;
    cout << endl;

    cout << "Enter the balance you received from the bank (format: $##.##): ";
    cin >> balance_from_bank;
    cout << endl;

    cout << "Please enter the amount of deposits you have: ";
    cin >> amount_of_deposits;
    cout << endl;

    cout << "Please enter each deposit, all on a separate line (press enter)" << endl;
    cout << "Do so in the following format: $##.##" << endl;
    cout << "Example: $6.20" << endl;
    cout << "------------------------" << endl;

    Money* deposits = new Money[amount_of_deposits];

    for (int i = 0; i < amount_of_deposits; i++) {
        cin >> deposits[i];
    }

    cout << endl;

    cout << "Please enter the amount of checks you have: ";
    cin >> amount_of_checks;
    cout << endl;

    cout << "Please enter each check, all on a separate line (press enter)" << endl;
    cout << "For example, in the case of 2 checks" << endl;
    cout << "503 $302.00 1" << endl;
    cout << "400 $120.00 0" << endl;
    cout << "Do so in the following format (each info separated by space): " << endl;
    cout << "Check# Amount IsCashed" << endl;
    cout << "IsCashed should be either 0 or 1" << endl;
    cout << "------------------------" << endl;


    Check* checks = new Check[amount_of_checks];

    for (int i = 0; i < amount_of_checks; i++) {
        cin >> checks[i];
    }

    Money cashed_checks_total, uncashed_checks_total, deposits_total;
    cashed_checks_total = get_cashed_check_total(checks, amount_of_checks);
    uncashed_checks_total = get_uncashed_check_total(checks, amount_of_checks);
    deposits_total = get_deposits_total(deposits, amount_of_deposits);

    cout << "------------------------" << endl;
    cout << "Checkbook and Bank Info" << endl;
    cout << "------------------------" << endl;
    cout << "Cashed Checks Total: " << cashed_checks_total << endl;
    cout << "Deposits Total: " << deposits_total << endl << endl;

    Money new_bank_balance = starting_balance + deposits_total - cashed_checks_total;
    cout << "New Bank Balance: " << new_bank_balance << endl;

    Money new_checkbook_balance = starting_balance + deposits_total - (cashed_checks_total + uncashed_checks_total);
    cout << "New Checkbook Balance: " << new_checkbook_balance << endl;

    Money bank_checkbook_balance = new_bank_balance - new_checkbook_balance;
    cout << "Bank-Checkbook Difference: " << bank_checkbook_balance << endl << endl;

    Money actual_difference = new_bank_balance - balance_from_bank;

    if (actual_difference.get_value() != 0) {
        cout << "Your bank calculated its balance incorrectly!!!" << endl;
        cout << "Bank\'s Given-Actual Difference: " << actual_difference << endl;
    } else {
        cout << "Bank Balance Checks out!  No Difference!" << endl;
    }

    cout << endl;

    cout << "----------------------" << endl;
    cout << "List of Cashed Checks:" << endl;
    cout << "----------------------" << endl;

    vector<Check> cashed_checks = get_list_cashed_checks(checks, amount_of_checks);
    sort(cashed_checks.begin(), cashed_checks.end());
    print_checks(cashed_checks);

    cout << "----------------------" << endl;
    cout << "List of Uncashed Checks:" << endl;
    cout << "----------------------" << endl;

    vector<Check> uncashed_checks = get_list_uncashed_checks(checks, amount_of_checks);
    sort(uncashed_checks.begin(), uncashed_checks.end());
    print_checks(uncashed_checks);

    delete[] deposits;
    delete[] checks;

    return 0;
}

int digit_to_int(char c) {
    if (c < '0' || c > '9') {
        return 0;
    }
    return c - '0';
}

Money get_cashed_check_total(Check* checks, int num) {
    Money tmp;

    for (int i = 0; i < num; i++) {
        if (checks[i].get_is_cashed()) {
            tmp = tmp + checks[i].get_amount();
        }
    }

    return tmp;
}

Money get_uncashed_check_total(Check* checks, int num) {
    Money tmp;

    for (int i = 0; i < num; i++) {
        if (!checks[i].get_is_cashed()) {
            tmp = tmp + checks[i].get_amount();
        }
    }

    return tmp;
}

Money get_deposits_total(Money* money, int num) {
    Money tmp;

    for (int i = 0; i < num; i++) {
        tmp = tmp + money[i].get_value();
    }

    return tmp;
}

vector<Check> get_list_cashed_checks(Check* checks, int num) {
    vector<Check> cashed_checks;

    for (int i = 0; i < num; i++) {
        if (checks[i].get_is_cashed()) {
            cashed_checks.push_back(checks[i]);
        }
    }

    return cashed_checks;
}

vector<Check> get_list_uncashed_checks(Check* checks, int num) {
    vector<Check> uncashed_checks;

    for (int i = 0; i < num; i++) {
        if (!checks[i].get_is_cashed()) {
            uncashed_checks.push_back(checks[i]);
        }
    }

    return uncashed_checks;
}

void print_checks(vector<Check> checks) {
    for (int i = 0; i < checks.size(); i++) {
        cout << checks[i] << endl;
    }
}

Money operator+(const Money& amount1, const Money& amount2) {
    Money tmp;
    tmp.all_cents = amount1.all_cents + amount2.all_cents;
    return tmp;
}

Money operator-(const Money& amount1, const Money& amount2) {
    Money tmp;
    tmp.all_cents = amount1.all_cents - amount2.all_cents;
    return tmp;
}

bool operator==(const Money& amount1, const Money& amount2) {
    return amount1.all_cents == amount2.all_cents;
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Dollars and Cents must both be negative or positive" << endl;
        cout << "Exiting program..." << endl;
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

istream& operator>> (istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;

    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if (one_char == ' ') {
        negative = true;
        ins >> one_char;
    } else {
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input" << endl;
        cout << "Exiting program..." << endl;
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;

    return ins;
}

ostream& operator<< (ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';

    outs << cents;

    return outs;
}

bool operator<(const Check& lhs, const Check& rhs) {
    return lhs.number < rhs.number;
}

istream& operator>>(istream& ins, Check& check) {
    int is_cashed;
    ins >> check.number >> check.amount >> is_cashed;

    if (is_cashed == 1) {
        check.is_cashed = true;
    } else if (is_cashed == 0) {
        check.is_cashed = false;
    } else {
        cout << "Invalid entry for whether check is cashed or not" << endl;
        cout << "Exiting program..." << endl;
        exit(1);
    }

    return ins;
}

ostream& operator<<(ostream& outs, const Check& check) {
    cout << "Check Number: " << check.number << endl;
    cout << "Check Amount: " << check.amount << endl;
    cout << "Is Check Cashed: " << check.is_cashed << endl;

    return outs;
}

