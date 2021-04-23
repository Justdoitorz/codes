#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class minStack {
public:
    minStack()
    {

    }
    void push(T v)
    {
        if (_stack.empty()) {
            _min = v;
            _stack.push(0);
        } else {
            T delta = v - _min;
            _stack.push(delta);
            if (delta < 0) {
                _min = v;
            }
        }
    }

    T pop()
    {
        if (!_stack.empty()) {
            T top = _stack.top();
            _stack.pop();
            if (top < 0) {
                _min -= top;
            }
            return _min + top;
        }
        _min = 0xFFFFFF;
        return 0xFFFFFF;
    }

    T getMin()
    {
        return _min;
    }
protected:
    stack<T> _stack;
    T _min;
};

template <typename T>
class cson : public minStack<T> {
protected:
    using minStack<T>::_stack;
    using minStack<T>::_min;
public:

    int peek()
    {
        if (!_stack.empty()) {
            int top = _stack.top();
            _stack.pop();
            if (top < 0) {
                _min -= top;
            }
            return _min + top;
        }
        return 0;
    }
};

class father {

public:
    int a;
};

class son : public father {
public:
    //using father::a;
    int get_a()
    {
        return a;
    }
};


int main()
{
    minStack<int> ms;
    cson<int> s;
    cout << sizeof(ms) << endl;
    cout << sizeof(s) << endl;
    //cout << s._min << endl;
    ms.push(2);
    cout << "min:" << s.getMin() << endl;
    ms.push(-1);
    cout << "min:" << ms.getMin() << endl;
    ms.push(1);
    cout << "min:" << ms.getMin() << endl;
    ms.push(-3);
    cout << "min:" << ms.getMin() << endl;
    cout << "pop:" << ms.pop() << endl;
    cout << "min:" << ms.getMin() << endl;
    cout << "pop:" << ms.pop() << endl;
    cout << "pop:" << ms.pop() << endl;
    cout << "pop:" << ms.pop() << endl;
    cout << "pop:" << ms.pop() << endl;
    cout << "min:" << ms.getMin() << endl;
    //cout << ms.getMin() << endl;
    return 0;
}
