#include <iostream>
using namespace std;

typedef int element; //int�� �ڷ����� element�� ��Ī ����.

typedef struct Node //���� ����ü Ÿ��
{
    element Data;   //���� �����͸� ���� Ÿ������ ����
    Node *Next; //���� ��带 ����Ű�� ������ ����

}node;

class LinkedStack
{
public:
    LinkedStack();  //������ �Լ�
    LinkedStack(const LinkedStack & S); //���� ������ �Լ�
    ~LinkedStack(); //�Ҹ��� �Լ�

    void Push(element item);    //item���� ���ÿ� ����
    int Pop();                  //���� ž�� ������ ���� ������
    bool IsEmpty(); //��� �ִ��� Ȯ��
    bool IsFull();  //���� �ִ��� Ȯ��

private:
    node* Top;  //ù ��带 ����Ű�� ������
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
    Top = nullptr;  //ž ������ ���� �η� ����
}

LinkedStack::~LinkedStack() //�Ҹ��� �Լ�
{
    int Temp;
    while(!IsEmpty())   //������ ������ �� �� ����
        Temp = Pop();   //����ؼ� ��
}

bool LinkedStack::IsEmpty() //������ ����ִ��� Ȯ���ϴ� �Լ�
{
    return bool(Top == nullptr);    //Top�� Null �̸� True
}

bool LinkedStack::IsFull()  //���� �ִ��� Ȯ��
{
    return !IsEmpty();    //isEmpty �Լ��� True�� False
}


void LinkedStack::Push(element item)    //������ ���� �Լ�
{
    node *NewTop = new node;    // ���ο� ��� ���� �Ҵ�
    NewTop->Data = item;        // �Ѿ�� ������ ����
    NewTop->Next = Top;         // �� ��尡 ���� ������ ù ��带 ����Ų��. 
    Top = NewTop;               // ž�� ���ο� ��带 ����Ų��. 
}

element LinkedStack::Pop()
{
    if(IsEmpty())
        cout<<"������ ����ֽ��ϴ�."<<endl;
    else
    {
        node* Temp = Top;   //ž ������ ���
        element Item = Temp->Data;  //ž ����� ������ ���
        
        Top = Top->Next;    //ž�� ���� ��带 �⸮Ű�� �Ѵ�. 
        delete Temp; // ���� ž ���� �ݳ�
        return Item; // ���� ž ������ ���� 
    }
}

