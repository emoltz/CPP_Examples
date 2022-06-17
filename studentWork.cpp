/* ahg342: This file contains code that reads in information from two files, one containing employees, and one containing their hours worked.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class LList;

template <class T>
class LListNode {
    T data;
    LListNode<T>* next;
public:
    LListNode(T newdata = T(), LListNode<T>* newNext = nullptr) :data(newdata), next(newNext) {};
    friend class LList<T>;
};

template <class T>
class LList {
    LListNode<T>* head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
    LList() :head(nullptr) {}
    LList(const LList& rhs) : head(nullptr) { *this = rhs; }
    LList<T>& operator=(const LList<T>& rhs);
    ~LList() { clear(); }
    T removeFromHead();
    bool isEmpty() const { return head == nullptr; }
    void clear();
    void insertAtHead(T newdata);
    void insertAtPoint(LListNode<T>* ptr, T newdata);
    void insertAtEnd(T newdata);
    int size() const;
    void sort();
    LListNode<T>* mergeSort(LListNode<T>* head);
    LListNode<T>* merge(LListNode<T>* head1, LListNode<T>* head2);
};

//Check if this works
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    return recursiveCopy(&rhs);
}

template <class T>
void LList<T>::insertAtHead(T newdata) {
    LListNode<T>* insertNode = new LListNode<T>(newdata, head);
    head = insertNode;
}

template <class T>
void LList<T>::insertAtPoint(LListNode<T>* ptr, T newdata) {
    LListNode<T>* insertNode = new LListNode<T>(newdata, ptr->next);
    ptr->next = insertNode;
}

template <class T>
void LList<T>::clear() {
    LListNode<T>* temp = head;
    LListNode<T>* next = temp;
    while (temp != nullptr) {
        next = temp->next;
        // OH Tomorrow!: do I need a delete function in Node?
        //delete temp;
        temp = next;
    }
}

template <class T>
T LList<T>::removeFromHead() {
    LListNode<T>* newHead = head->next;
    LListNode<T>* deletePtr = head;
    T toReturn = head->data;
    head = newHead;
    return toReturn;
}

template <class T>
int LList<T>::size() const {
    int count = 0;
    LListNode<T>* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
void LList<T>::insertAtEnd(T newdata) {
    if (isEmpty()) {
        insertAtHead(newdata);
        return;
    }
    LListNode<T>* temp = new LListNode<T>(newdata);
    LListNode<T>* end = head;
    while (end->next != nullptr)
        end = end->next;
    end->next = temp;
}

template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs) {
    if (rhs == nullptr) {
        return nullptr;
    }
    return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
}

template <class T>
void LList<T>::sort() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    else {
        head = mergeSort(head);
    }
}

template <class T>
LListNode<T>* LList<T>::mergeSort(LListNode<T>* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    LListNode<T>* head1 = head;
    LListNode<T>* halfwayPtr = head;
    LListNode<T>* endPtr = head;
    while (endPtr != nullptr) {
        endPtr = endPtr->next;
        if (endPtr != nullptr) {
            endPtr = endPtr->next;
        }
        halfwayPtr = halfwayPtr->next;
    }
    // Split here at the midpoint
    LListNode<T>* head2 = halfwayPtr;
    halfwayPtr = nullptr;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}

template <class T>
LListNode<T>* LList<T>::merge(LListNode<T>* head1, LListNode<T>* head2) {
    LListNode<T>* mergedPtr;
    LListNode<T>* trackingPtr;
    LListNode<T>* leftPtr;
    LListNode<T>* rightPtr;
    // Find first node:
    if (head1 == nullptr && head2 == nullptr) {
        return nullptr;
    }
    else if (head1 == nullptr) {
        return head2;
    }
    else if (head2 == nullptr) {
        return head1;
    }
    if (head1->data > head2->data) {
        mergedPtr = head1;
        leftPtr = head1->next;
        mergedPtr->next = nullptr;
        rightPtr = head2;
        trackingPtr = mergedPtr;
    }
    else {
        mergedPtr = head2;
        rightPtr = head2->next;
        mergedPtr->next = nullptr;
        leftPtr = head1;
        trackingPtr = mergedPtr;
    }
    while (leftPtr != nullptr && rightPtr != nullptr) {
        if (leftPtr->data > rightPtr->data) {
            trackingPtr->next = leftPtr;
            leftPtr = leftPtr->next;
            trackingPtr = trackingPtr->next;
            trackingPtr->next = nullptr;
        }
        else {
            trackingPtr->next = rightPtr;
            rightPtr = rightPtr->next;
            trackingPtr = trackingPtr->next;
            trackingPtr->next = nullptr;
        }
    }
    if (leftPtr != nullptr) {
        trackingPtr->next = leftPtr;
    }
    else if (rightPtr != nullptr) {
        trackingPtr->next = rightPtr;
    }
    return mergedPtr;
}

class Employee {
    int ID;
    double payRate;
    string name;
    int hours;
    // Change this to double
    double totalPay;
public:
    Employee(int ID = 0, double payRate = 0.1, string name = "John Doe") :ID(ID), payRate(payRate), name(name), hours(0), totalPay(0) {}
    int getID()const { return ID; }
    double getPayRate()const { return payRate; }
    string getName()const { return name; }
    int getHours()const { return hours; }
    double getTotalPay()const { return totalPay; }
    void setHours(int newHours) { hours = newHours; totalPay = payRate * (double)hours; }
    //bool operator<(Employee* rhs);
    void setTotalPay(double pay){
        totalPay = pay;
    }
    bool operator>(const Employee& emp2);
};


//bool Employee::operator<(Employee* rhs) {
//return this->totalPay < rhs->totalPay;
//}

bool Employee::operator>(const Employee& emp2) {
    cout << "Emp1 Total Pay: " << this->getTotalPay() << " Emp 2 Total Pay: " << emp2.getTotalPay() << endl;
    if (this->getTotalPay() > emp2.getTotalPay()) {
        return true;
    }
    return false;
}


void openInputFile(ifstream& inFile, string message);


int main() {
    Employee e1;
    Employee e2;
    e1.setTotalPay(12);
    e2.setTotalPay((10));
    cout << boolalpha << (e1 > e2);
    return 0;
}

void openInputFile(ifstream& inFile, string message) {
    string filename;
    cout << message;
    cin >> filename;
    inFile.open(filename);
    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << message;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}
