
template<class T>
class EnhancedQueue{
private:
	Llist<T> alist;
	RBT<T> tree;
	int size;
public:
	EnhancedQueue(Llist<T> newList = Llist<T>(), RBT<T> newTree = RBT<T>(), int newSize = 0): alist(newList), tree(newTree), size(newSize){};
    void enqueue(T data){alist.push_back(data); tree.insert(data); size++;} //runtime should be theta logn
    void dequeue(){
        T front = alist.front();
        alist.pop_front();
        tree.remove(front);
        if (size > 0)
        {
            size--;
        } else if (size == 0)
        {
            cout<<"Error dequeueing an empty queue\n";
        }
        } //runtime theta logn
    T front(){return alist.front();} //runtime theta 1
    bool isEmpty(){return alist.empty();} //runtime theta 1

    //for size.. size function in our LList in class was linear, so cant use that
    //so I'm storing a size int in this class to access it in theta 1
    int size(){return size;}
    
    bool contains(T data){return tree.search(data);} //assumes we have a search function in our RBT class.
    //Because of the binary search tree quality of RBT, a search in the RBT is logn.
    //Therefore this contains function's runtime is theta logn.
    void clear(){alist.clear(); tree.clear(); size = 0;} //runtime is n + n + 1 so theta(n)
};