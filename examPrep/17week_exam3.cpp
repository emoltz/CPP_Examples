#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

//Q5
class Base{
public:
    Base(){}
    virtual void f(){
        cout << "BASE ";
    }
};

class Derived: public Base{
public:
    Derived(): Base(){}

    virtual void f(){
        cout << "Derived ";
    }
};

void q5(){
    vector<Base> base_objs;
    Base obj1 = Derived();
    Derived obj2 = Derived();
    Base obj3 = Base();

    base_objs.push_back(obj1);
    base_objs.push_back(obj2);
    base_objs.push_back(obj3);

    for (auto base_obj : base_objs){
        base_obj.f();
    }

    obj1.f();
    obj2.f();
    obj3.f();
}

class Person{
public:
    virtual void move() = 0;
};


class A{
private:
    int x;
    int y;
public:
    A(): x(0), y(0){
        cout << "Default constructor" << endl;
    }

    A(int x, int y): x(x), y(y){
        cout << "Constructor with two values" << endl;
    }

    A(const A& other){
        cout << "Copy constructor" << endl;
        x = other.x;
        y = other.y;
    }

};

void q8(){
    A a(1, 2);
    A b = a;
}


//Q9
class Sorting{
    virtual vector<int> sort(vector<int>& v) = 0;
    virtual string worst_case_runtime() = 0;
};

class InsertionSort: public Sorting{
public:
    string worst_case_runtime() override{
        return "O(n^2)";
    }

    vector<int>sort(vector<int>& v) override{
        //what is the general intuition for insertion sort?
    }

};


//Q10
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

ListNode* reverse_linked_list(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;

    //works better with a picture
    while(curr->next != nullptr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool is_target_in_list(ListNode* head, int target){
    ListNode* itr = head;
    while(itr != nullptr){
        if(itr->val == target){
            return true;
        }
        itr = itr->next;
    }
    return false;

}

int find_max(ListNode* head){
    int max = head->val;
    ListNode* itr = head;
    while(itr != nullptr){
        if (itr->val > max){
            max = itr->val;
        }
        itr = itr->next;
    }
    return max;
}

//Q11
list<int> get_integer(const string& filename){
    list<int> big_int;
    ifstream input(filename);
    string line;
    if(input.is_open()){
        while(getline(input, line)){
            for(auto num: line){
                int n = num - '0';
                big_int.push_front(n);
            }
        }
    }
    else{
        cout << "Could not open file" << endl;
    }
    return big_int;
}

list<int> add_integers(const list<int>& l1, const list<int> & l2){
    list<int> result;
    //assuming both lists are the same size
    int carry = 0;
    for(auto itr1 = l1.begin(), itr2 = l2.begin(); itr1 != l1.end() && itr2 != l2.end(); itr1++, itr2++){
        int total_val = *itr1 + *itr2 + carry;
        int insert_val = total_val % 10;
        carry = total_val / 10;
        result.push_back(insert_val);
    }
    if (carry > 0){
        result.push_back(carry);
    }
    return result;

}

//Q12
//Implement stack using queues

class Stack{
    queue<int> q1, q2;
    int curr_size;

public:
    Stack(){
        curr_size = 0;
    }
};


int main(){
    return 0;
}