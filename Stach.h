#ifndef STACK_H
#define STACK_H

template <class Type>
class Stack {
public:
    Stack();
    Stack(int);
    Stack(const Stack&);
    ~Stack();

    void Push(Type);
    void Pop(Type&);
    int isEmpty() const;
    int isFull() const;

    void operator<<(Type);
    void operator>>(Type&);

private:
    static const int defaultStackSize;
    int topStack;
    int size;
    Type* data;
};

template <class Type>
const int Stack<Type>::defaultStackSize = 500;

template <class Type>
Stack<Type>::Stack()
{
    size = defaultStackSize;
    topStack = 0;
    data = new Type[size];
}

template <class Type>
Stack<Type>::Stack(int x)
{
    size = x;
    topStack = 0;
    data = new Type[size];
}

template <class Type>
Stack<Type>::Stack(const Stack& s)
{
    size = s.size;
    topStack = s.topStack;
    data = s.data;
}

template <class Type>
Stack<Type>::~Stack()
{
    delete []data;
}

template <class Type>
void Stack<Type>::Push(Type item)
{
    if (!isFull()) {
        data[topStack] = item;
        topStack++;
    }
}

template <class Type>
void Stack<Type>::Pop(Type& item)
{
    if (!isEmpty()) {
        topStack--;
        item = data[topStack];
    }
}

template <class Type>
int Stack<Type>::isEmpty() const
{
    if (topStack == 0)
        return 1;
    else
        return 0;
}

template <class Type>
int Stack<Type>::isFull() const
{
    if (topStack == size)
        return 1;
    else
        return 0;
}

template <class Type>
void Stack<Type>::operator<<(Type item)
{
    Push(item);
}

template <class Type>
void Stack<Type>::operator>>(Type& item)
{
    Pop(item);
}

#endif // STACK_H
