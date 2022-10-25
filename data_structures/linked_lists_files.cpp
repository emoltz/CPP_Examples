#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//PROTOTYPES
class EmployeeData;
class Payroll;
typedef EmployeeData* EmployeeDataPtr;
typedef Payroll* PayrollPtr;

//CLASSES
class EmployeeData{
private:
    int _id;
    double _rate;
    string _name;
    double _salary;
public:
    EmployeeData() : _id(-1), _rate(-1.00), _name("N/A"), _link(nullptr){}
    EmployeeData(int id, double wage, string& name, EmployeeDataPtr next) : _id(id), _rate(wage), _name(name), _link(next){}

    double getSalary()const {return _salary;}
    void addToSalary(double newSalary){ _salary += newSalary;}
    int getID() const{return _id;}
    void setID(int newID){_id = newID;}
    double getRate() const{return _rate;}
    void setRate(double newWage){ _rate = newWage;}
    string getName(){return _name;}
    void setName(string newName){_name = newName;}
    EmployeeDataPtr getLink(){return _link;}
    void setLink (EmployeeDataPtr next){_link = next;}

    EmployeeDataPtr _link;
};

class Payroll{
private:
    int _id;
    int _hoursWorked;
    PayrollPtr _link;
public:
    //constructors
    Payroll() : _id(0), _hoursWorked(0), _link(nullptr){}
    Payroll(int id, int hoursWorked, PayrollPtr next) : _id(id), _hoursWorked(hoursWorked), _link(next){}

    int getID() const{return _id;}
    int getHoursWorked() const{ return _hoursWorked;}
    PayrollPtr getLink(){return _link;}
    void setLink (PayrollPtr next){ _link = next;}
};

template <class T>
void headInsert(T& head, int id, double wage, string name);
void headInsert(EmployeeDataPtr& head, int id, double wage, string name);
void headInsert(PayrollPtr& head, int id, int hours);

EmployeeDataPtr search (EmployeeDataPtr head, int target);
void displayList(EmployeeDataPtr head);
void displayListToOutputFile(EmployeeDataPtr head, ofstream& outs);
void displayList(PayrollPtr head);

EmployeeData* swap ( EmployeeData* ptr1,  EmployeeData* ptr2);
void bubbleSortLinkedLists (EmployeeData*& head, int count);
void calcSalaries(EmployeeDataPtr employees, PayrollPtr payroll, vector<EmployeeData>& outV);
template <class T>
void printNameandSalary (vector<T> v, ofstream& outs){
    for (int i = 0; i < v.size(); i++) {
        outs << v[i].getName() << ", $" << v[i].getSalary() << endl;
    }
}
void bubbleSortVector(vector<EmployeeData>& vector);
void printPayrollInformation(EmployeeDataPtr& head1, PayrollPtr& head2, ofstream& outs);

int main() {
    //user selects files
    ofstream out_stream;
    ifstream in_stream;

    out_stream.open("output.txt");

    string filename;
    cout << "Enter filename ('employeeData.txt')" << endl;
    cin >> filename;
    in_stream.open(filename);

//FIRST FILE
//    in_stream.open("employeeData.txt");
    EmployeeDataPtr head_employee = nullptr, temp_employee = nullptr;
    int tempID;
    double tempWage;
    string tempName;

    in_stream >> tempID >> tempWage;
    in_stream.ignore(1);
    getline(in_stream, tempName);
    head_employee = new EmployeeData (tempID, tempWage, tempName, temp_employee);

    while(in_stream >> tempID) {
        in_stream >> tempWage;
        in_stream.ignore(1);
        getline(in_stream, tempName);
        headInsert(head_employee, tempID, tempWage, tempName);
    }
    cout << endl;
    in_stream.close();

//SECOND FILE
//    in_stream.open("id_and_hours.txt");
    cout << "Enter filename ('id_and_hours.txt')" << endl;
    cin >> filename;
    in_stream.open(filename);
    PayrollPtr head_payroll, temp_payroll;
    int hoursWorked;
    int payrollID;

    while (in_stream >> payrollID){
        in_stream >> hoursWorked;
        headInsert(head_payroll, payrollID, hoursWorked);
    }

    printPayrollInformation(head_employee,head_payroll,out_stream);

    return 0;
}

//FUNCTION DEFINITIONS
void headInsert(EmployeeDataPtr& head, int id, double wage, string name){
    EmployeeDataPtr tempPtr;
    tempPtr = new EmployeeData(id, wage, name, nullptr);

    tempPtr->setLink(head);
    head = tempPtr;

}
template <class T>
void headInsert(T& head, int id, double wage, string name){
    T tempPtr;
    tempPtr = new T(id, wage, name, nullptr);

    tempPtr->setLink(head);
    head = tempPtr;

}

void headInsert(PayrollPtr& head, int id, int hours){
    PayrollPtr tempPtr;
    tempPtr = new Payroll(id, hours, nullptr);

    tempPtr->setLink(head);
    head = tempPtr;
}

EmployeeDataPtr search (EmployeeDataPtr head, int target){
    EmployeeDataPtr here = head;

    if (here == nullptr){
        cout << "nope";
        return nullptr;
    }
    else{
        while (here->getID() != target && here->getLink() != nullptr){
            here = here->getLink();
        }

        if (here->getID() == target){
            cout << "found";
            return here;
        }
        else{
            cout << "else";
            return nullptr;
        }
    }
}

void displayList(EmployeeDataPtr head){
    while(head != nullptr){
        cout << head->getID() << ": " <<  head->getName() << "\n";
        head = head->getLink();
    }
    cout << endl;
}
void displayListToOutputFile(EmployeeDataPtr head, ofstream& outs){
    while(head != nullptr){
        outs <<  head->getName() << ", $" <<head->getSalary() << "\n";
        head = head->getLink();
    }
    outs << endl;
}
void displayList(PayrollPtr head){
    while(head != nullptr){
        cout << head->getID() << " " << head->getHoursWorked() << endl;
        head = head->getLink();
    }
    cout << endl;
}
EmployeeData* swap ( EmployeeData* ptr1,  EmployeeData* ptr2){
    struct EmployeeData* temp = ptr2->getLink();
    ptr2->setLink(ptr1);
    ptr2->setLink(temp);
    return ptr2;
}
void bubbleSortLinkedLists (EmployeeData*& head, int count){
    EmployeeData** h;
    int swapped;
    for (int i = 0; i < count; i++) {
        h = &head;
        swapped = 0;

        for (int j = 0; j < count - i - 1; j++) {
            EmployeeData* p1 = *h;
            EmployeeData* p2 = p1->getLink();

            if(p1->getSalary() >= p2->getSalary()){
                //update link
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->_link;
        }
        if (swapped == 0){
            break;
        }
    }

}
void calcSalaries(EmployeeDataPtr employees, PayrollPtr payroll, vector<EmployeeData>& outV){
    vector<Payroll> payroll_v;
    while (employees != nullptr){
        outV.push_back(*employees);
        employees = employees->getLink();
    }
    while (payroll != nullptr){
        payroll_v.push_back(*payroll);
        payroll = payroll->getLink();
    }

    for (auto & i : payroll_v) {
        for (auto & j : outV) {
            if (i.getID() == j.getID()){
                j.addToSalary(
                        i.getHoursWorked() * j.getRate()
                );
            }
        }
    }

}
void bubbleSortVector(vector<EmployeeData>& vector){
    EmployeeData temp;
    for (unsigned int i = vector.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (vector[j].getSalary() < vector[j + 1].getSalary()){
                //swap the numbers
                temp = vector[j + 1];
                vector[j + 1] = vector[j];
                vector[j] = temp;
            }
        }
    }
}
void printPayrollInformation(EmployeeDataPtr& head1, PayrollPtr& head2, ofstream& outs){
    vector<EmployeeData> e;
    outs << "*********Payroll Information********" << endl;
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
//the number in the parens below can set the precision of the decimal points.
    outs.precision(2);
    calcSalaries(head1, head2,e);
    bubbleSortVector(e);
    printNameandSalary(e, outs);

    outs << "*********End payroll**************";
}