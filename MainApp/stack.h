#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(T t);
    T pop();
    bool isEmpty();

private:
    T *pT;
    int maxSize;
    int size;
};


template<typename T>
Stack<T>::Stack()
{
    maxSize = 100;
    size = 0;
    pT = new T[maxSize];
}
template<typename T>
Stack<T>::~Stack()
{
    delete [] pT;
}

template<typename T>
void Stack<T>::push(T t)
{
    size++;
    pT[size] = t;
}
template<typename T>
T Stack<T>::pop()
{
    T t = pT[size-1];
    size--;
    return t;
}
template<typename T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}

#endif // STACK_H
