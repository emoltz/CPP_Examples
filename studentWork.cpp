#include <iostream>
#include <queue>
using namespace std;

// LList
/*
Since I am using a linked list, you must set the pointer to
the head of the linked list (the first node), before pointing towards the address of the next node.
Each node will have their stored values and addresses. The last node that will not
have a node after it, will be the tail and it points to NULL.
*/

class EnhancedQueue()
{
// initialize the variables. The new node will be the head of the queue.
int *node = new node();

//Enqueue: is the end of the queue and where the tail is. This will be the last element that you pop and push.
node->enqueue();

// Dequeue: is the front of the queue where we will pop and push the elements. This is the head.
node->dequeue();

// front: is the front of the queue where you will pop and push the element first, before moving onto the next element.
node->front();

//isEmpty: to check if the queue is empty. If the location in queue is empty then move to the next location, if there is none left then exit.
node->isEmpty();

/*
size: to check the size of the queue
*/
node->size();

/*
contains: to check the queue if that element is in it. If it is in it, then you can add it
next to that value in the queue, otherwise insert it in between the value that is less than it and greater than it.
*/
node->contains();

//clear: clear so you don't end up overloading
node->clear();

// delete the node
delete node;
};

int main()
{
    // call the class
    EnhancedQueue(node);

    // push and pop the values
    node.push();
    node.pop();
    return 0;
}
