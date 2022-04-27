#include<iostream>
using namespace std;

#define DEFAULT_CAPACITY 10

class Stack
{
public:
    Stack();
    Stack(int capacity);
    ~Stack();

    void Push(int element);
    int Pop();
    int Top();
    bool IsEmpty();
	void Extend(); 
    void ArrayCopy(int* new_array, int* old_array);
    
private:
    int *array;
    int top;
    int capacity;
};


int main(void)
{
    Stack s;
    Stack s1(3);

    cout<<"push: ";
    for(int i = 0; i<15; i++)
    {
        cout<<i<<" ";
        s1.Push(i);
    }
    cout<<endl;
    
    while(true)
    {
        if(s1.IsEmpty() == true)
            break;
        cout<<"pop: "<<s1.Pop()<<endl;
    }


    
    return 0;
}


Stack::Stack(): top(-1), capacity(DEFAULT_CAPACITY)
{
    array = new int[DEFAULT_CAPACITY];
}
Stack::Stack(int capacity): top(-1), capacity(capacity) 
{
    array = new int[capacity];
}
Stack::~Stack()
{
    int num;
    while(IsEmpty() == false)
        num = Pop();

    delete[] array;
}

void Stack::Push(int element)
{
    array[++top] = element;
    if(top == capacity)
        Extend();
}

int Stack::Pop()
{
    return (IsEmpty() == true) ? -1 : array[top--];
}
int Stack::Top()
{
    return IsEmpty() ? -1 : array[top];
}
bool Stack::IsEmpty()
{
    return bool(top == -1);
}

void Stack::Extend()
{
    int *old_array = array;
    capacity *= capacity;

    array = new int[capacity];

    ArrayCopy(array, old_array);
    
    delete[] old_array;

}

void Stack::ArrayCopy(int* new_array, int* old_array)
{
    
    for(int i = 0; i<=top; i++)
        array[i] = old_array[i];

}

