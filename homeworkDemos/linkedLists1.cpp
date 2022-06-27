#include <iostream>
using namespace std;

class Person;
class Student;
class Employee;

//LinkedList class
class LinkedListPerson{
public:
    void insert(Person* p){
        //if p == Employee, then do this:
        //if p == Student, then do this:
    }
};

class Person{
    //abstract class
    //specify which functions the children classes will NEED and make them virtual
public:
    virtual void f (){

    };
};

class Employee : public Person{

};

class Student : public Person{

};

template <class T>
class Arithmetic{
public:
    T add(){

    }
};

int main(){
    LinkedListPerson l;
    Person* ethan = new Employee();
    Person* student1 = new Student();
    l.insert(student1);
}