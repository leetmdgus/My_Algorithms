#include <iostream>
#include "RPN.h"

using namespace std;

Stack_::Stack_(): Top(-1){}

Stack_::~Stack_() {}

void Stack_::Push(int element)
{
    ++Top;
    stack[Top] = element;
}

int Stack_::Pop()
{
    if(is_Empty())
        return -1;

    int temp = Top;
    --Top;

    return stack[temp];
}

bool Stack_::is_Empty()
{
    return bool(Top == -1);
}

void Stack_::operate(char oper)
{
    switch (oper)
    {
    case '+':
        stack[Top-1] += stack[Top];
        break;
    case '-':
        stack[Top-1] -= stack[Top];
        break;
        
    case '*':
        stack[Top-1] *= stack[Top];
        break;
    
    case '/':
        stack[Top-1] /= stack[Top];
        break;
    
    default:
        break;
    }
}

void Stack_::printStack()
{
    if(Top > 0)
        cout<<"스택이 비어있지 않습니다." <<endl;
    else  if(Top == -1)
        cout<<"값: "<<0<<endl;
    else   
        cout<<"값: "<<stack[Top]<<endl;
}
