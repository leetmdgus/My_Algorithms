#include <iostream>
using namespace std;

typedef int element; //int형 자료형에 element라 별칭 붙임.

typedef struct Node //노드는 구조체 타입
{
    element Data;   //스택 데이터를 정수 타입으로 가정
    Node *Next; //다음 노드를 가리키는 포인터 변수

}node;

class LinkedStack
{
public:
    LinkedStack();  //생성자 함수
    LinkedStack(const LinkedStack & S); //복사 생성자 함수
    ~LinkedStack(); //소멸자 함수

    void Push(element item);    //item값을 스택에 삽입
    int Pop();                  //스택 탑의 데이터 값을 리턴함
    bool IsEmpty(); //비어 있는지 확인
    bool IsFull();  //꽉차 있는지 확인

private:
    node* Top;  //첫 노드를 가르키는 포인터
};


int main(void)
{
    int num = 26;
    int init = num;
    LinkedStack nc;

    while(num/2 != 1)
    {
        nc.Push(num%2);
        num = num/2;
    }
    nc.Push(num%2);
    nc.Push(num/2);


    cout<<init<<"(10): ";
    while(!nc.IsEmpty())
        cout<<nc.Pop();
    cout<<"(2)"<<endl;
}


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

