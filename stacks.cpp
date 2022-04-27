#include <iostream>
#include <stack>
#include <queue>
#include <list>
//#include <deque> //double ended queue
using namespace std;






void iterating1(){
    //this is the simplist way
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    auto q_copy = q;
    while (!q_copy.empty()){
        int front = q_copy.front();
        cout << front << endl;
        q_copy.pop();
    }
}

//really simple LL class
class node;
class linkedList;

class node{
public:
    int _data;
    node *_next;
};

class linkedList{
private:
    node *_head, *_tail;
public:
    linkedList(){
        _head = nullptr;
        _tail = nullptr;
    }

    node* front(){
        return _head;
    }

    node* back(){
        return _tail;
    }

    void add_node(int n){

        //why do we have to make this a pointer?
        node *temp = new node;
        temp->_data = n;
        temp->_next = nullptr;

        if(_head == nullptr){
            _head = temp;
            _tail = temp;
        }
        else{
            _tail->_next = temp;
            _tail = _tail->_next;
        }



    }
    void add_node_noTail(int n){
        node* temp = new node;
        temp->_data = n;
        temp->_next = nullptr;
        
        if (_head == nullptr){
            _head = temp;
        }
        else{
            node* iterator = _head;
            while(iterator->_next != nullptr){
                iterator = iterator->_next;
            }
            temp->_next = temp;
        }
        
    }
    void display(){
        node *temp = _head;
        while (temp != nullptr){
            cout << temp->_data << endl;
            temp = temp->_next;
        }

    }

    void displayRecursion(node* head){
        if (head != nullptr){
            cout << head->_data << endl;
            displayRecursion(head->_next);
        }
    }

    bool search(node* front, int x){
        node* curr = _head;
        while(curr != nullptr){
            if (curr->_data == x){
                return true;
            }
            else{
                curr = curr->_next;
            }
        }
        return false;
    }
};



int main(){
   linkedList l;
   l.add_node(5);
   l.add_node(10);
   l.displayRecursion(l.front());


    return 0;
}