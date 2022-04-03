//Objects within objects - 2 classes
#include <iostream>
#include <string>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    void checkDate(int day, int month);

public:
    Date (int dayIn, int monthIn, int yearIn): day(dayIn), month(monthIn), year(yearIn) { checkDate (day, month);}

    Date ( ): day(1), month(1), year(1900) {}

    void update (int newDay, int newMonth, int newYear) { day = newDay; month = newMonth; year = newYear; }

    void output (ostream& outs) const;
};

class Person
{
    string firstName;
    string lastName;
    Person* spouse = nullptr;
    Person* child = nullptr;
    Person* parent1 = nullptr;
    Person* parent2 = nullptr;

public:
    Date birthday; // how to handle functions usign this in main if this is private?

    Person (string first, string last): firstName(first), lastName(last) {} // If date is not entered, calls the default date constructor to 1/1/1900

    Person (string first, string last, int dayIn, int monthIn, int yearIn): firstName(first), lastName(last), birthday(dayIn,monthIn,yearIn) {} // If date is entered

    void output (ostream& outs) const;

    void marry (Person& partner);
    void children (Person& offspring);
    void parent (Person& parent);

    void outputFamilyTree (ostream& outs) const;

    friend ostream& operator<< (ostream&, const Person&);
};


int main ()
{
    Date myBirthday (7,3,1978), momBirthday (3,3,1923);
    myBirthday.output(cout);
    momBirthday.output(cout);
    momBirthday.update (3,3,1953);
    momBirthday.output(cout);

    Person dad ("Aziz", "Kalagoglu");
    dad.output(cout);
    dad.birthday.update (6,8,1946);
    dad.output(cout);
    Person mom ("Canan", "Kalagoglu");
    mom.birthday = momBirthday;
    mom.output(cout);
    Person me ("Nil","Kalagoglu",7,3,1978);
    me.output(cout);
    mom.marry (dad);
    mom.children (me);
    me.parent (mom);
    dad.children(me);
    me.parent (dad);
    me.outputFamilyTree (cout);


    cout << me; // DOES THIS WORK?
    return 0;
}

void Date:: output (ostream& outs) const
{
    outs << day << '/' << month << '/' << year << endl;
}

void Date ::checkDate (int day, int month)
{
    if (month < 0 || month > 12 || day < 0 || day > 31)
        cout << "Invalid date, please update the date.\n";
}

void Person:: output (ostream& outs) const
{
    outs << firstName << ' ' << lastName << " born on: ";
    birthday.output (cout);
}

void Person:: marry (Person& partner)
{
    if (this->spouse != nullptr)
        cout << this <<" is already married to someone else!\n";
    else if (partner.spouse != nullptr)
        cout << "That person is already married to someone else!\n"; //why does cout << partner <<" is already ... not work? need to overlead <<?
    else {
        spouse = &partner;
        partner.spouse = this;
    }
}
void Person:: children (Person& offspring)
{
    child = &offspring;
}

void Person:: parent (Person& parent)
{
    if(parent1 == nullptr) {
        parent1 = &parent;
        parent.child = this;
    }
    else if (parent2 == nullptr) {
        parent2 = &parent;
        parent.child = this;
    }
}

void Person:: outputFamilyTree (ostream& outs) const
{
    outs << firstName << ' ' << lastName << "'s parents are: "<< parent1 << " and " << parent2 << endl; // How to dereference parent pointers?
}

ostream& operator<< (ostream& outs, const Person& object)
{
    outs << "My name is ";
    object.output(outs);
    outs << "My parents are: " << object.parent1 << " and " << object.parent2<< endl; // How to dereference parent pointers?


    return outs;
}