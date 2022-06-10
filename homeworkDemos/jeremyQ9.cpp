
template <class T>
class EnhancedQueue
{
public:
    EnhancedQueue() : _queue<T>(), RBTree<T>() {};

    void enqueue(T data)
    {
        _queue.enqueue(data);
        _tree.insert(data);
        ++_size;
    };

    void dequeue()
    {
        if (_size != 0) {
            T data = _queue.front();
            _queue.dequeue();
            _tree.remove(data);
            --_size;
        }
    };

    T front()
    {
        return _queue.front();
    }

    bool isEmpty()
    {
        return (_size == 0);
    }

    int size()
    {
        return _size;
    }

    bool contains(T data) {
        RBNode* curr = _tree.getRoot();
        while (curr != nullptr) {
            if (data == curr->val) {
                return true;
            } else if (data < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return false;
    }

    void clear()
    {
        _queue.clear();
        _tree.clear();
        _size = 0;
    }

private:
    queue<T> _queue;
    RBTree<T> _tree;
    int _size;
};