#include <iostream>
#include "linked_stack.h"

using namespace std;


LinkedStack::LinkedStack()
{
    Top = nullptr;  //탑 포인터 값을 널로 세팅
}

LinkedStack::~LinkedStack() //소멸자 함수
{
    int Temp;
    while(!IsEmpty())   //스택이 완전히 빌 때 까지
        Temp = Pop();   //계속해서 팝
}

bool LinkedStack::IsEmpty() //스택이 비어있는지 확인하는 함수
{
    return bool(Top == nullptr);    //Top이 Null 이면 True
}

bool LinkedStack::IsFull()  //꽉차 있는지 확인
{
    return !IsEmpty();    //isEmpty 함수가 True면 False
}


void LinkedStack::Push(element item)    //스택의 삽입 함수
{
    node *NewTop = new node;    // 새로운 노드 공간 할당
    NewTop->Data = item;        // 넘어온 데이터 복사
    NewTop->Next = Top;         // 새 노드가 현재 상태의 첫 노드를 가리킨다. 
    Top = NewTop;               // 탑이 새로운 노드를 가리킨다. 
}

element LinkedStack::Pop()
{
    if(IsEmpty())
        cout<<"스택이 비어있습니다."<<endl;
    else
    {
        node* Temp = Top;   //탑 포인터 백업
        element Item = Temp->Data;  //탑 노드의 데이터 백업
        
        Top = Top->Next;    //탑이 다음 노드를 기리키게 한다. 
        delete Temp; // 이전 탑 공간 반납
        return Item; // 이전 탑 데이터 리턴 
    }
}

