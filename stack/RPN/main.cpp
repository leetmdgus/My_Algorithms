#include <iostream>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();

    void Push(int element);
    int Pop();
    bool is_Empty();

    void operate(char oper);
    void printStack();

private: 
    int Top;
    int stack[10];
};

int main(void)
{
    Stack s1;
    s1.Push(2);
    s1.Push(5);
    s1.operate('+');
    s1.Push(3);
    s1.operate('*');
    s1.Push(1);
    s1.operate('-');
    s1.printStack();
}

Stack::Stack(): Top(-1){}

Stack::~Stack() {}

void Stack::Push(int element)
{
    ++Top;
    stack[Top] = element;
}

int Stack::Pop()
{
    if(is_Empty())
        return -1;

    int temp = Top;
    
    --Top;
    return stack[temp];
}

bool Stack::is_Empty()
{
    return bool(Top == -1);
}

void Stack::operate(char oper)
{
    int val1 = Pop();
    int val2 = Pop();

    int result;
    switch (oper)
    {
    case '+':
        result = val2+val1;
        break;
    case '-':
        result = val2-val1;
        break;
        
    case '*':
        result = val2*val1;
        break;
    
    case '/':
        result = val2/val1;
        break;
    
    default:
        break;
    }

    Push(result);

}

void Stack::printStack()
{
    for(int i = 0; i<=Top; i++)
        cout<<stack[i]<<" ";
        
    cout<<endl;
    cout<<"Top: "<<Top<<endl;


    if(Top > 1)
        cout<<"스택이 비어있지 않습니다." <<endl;
    else  if(Top == -1)
        cout<<"값: "<<0<<endl;
    else   
        cout<<"값: "<<stack[Top]<<endl;
}
