#include <iostream>
#include "array stack.h"

using namespace std;

ArrayStack::ArrayStack()
{
    top = 0;    //탑 인덱스 0으로 초기화
}

ArrayStack::ArrayStack(const ArrayStack & S): top(top)  // Stack은 배열구조기 때문에 깊은복사를 하려면 배열에 있는 요소 하나하나를 복사해야한다. 
{
    for(int index = 0; index<=S.top; ++index)
        Stack[index] = S.Stack[index];
}

ArrayStack::~ArrayStack()
{
}

void ArrayStack::Push(element item)
{
    top++; 
    Stack[top] = item;
}

int ArrayStack::Pop()
{
    if(IsEmpty())
        cout<<"빈스택입니다."<<endl;
    else
    {
        int temp = Stack[top];  //top 데이터 저장
        Stack[top] = 0;         //top값 pop
        top--;  
        return temp;    // 이전 top값 반환
    }
    
}

bool ArrayStack::IsEmpty()
{
    return bool(top == 0);
}

bool ArrayStack::IsFull()
{
    return !IsEmpty;
}
