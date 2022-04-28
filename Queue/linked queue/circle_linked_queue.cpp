#include <iostream>

using namespace std;
typedef struct Node
{
    int Data;   //큐 데이터를 정수 타입으로 가정
    Node *Next; //다음 노드를 가리키는 포인터 변수
}node;


class Queue
{
public:
    Queue();
    ~Queue();

    void Enqueue(int item);
    int Dequeue();
    bool isEmpty();
    bool isFull();

private:
    node* Rear;
};

int main(void)
{
    Queue q;

    cout<<"enqueue: "; // 스택에 0부터 14까지 enqueue한다. 
    for(int i = 0; i<15; i++)
    {
        cout<<i<<" ";
        q.Enqueue(i);
    }
    cout<<endl<<endl;
    //결과 : enqueue: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    
    cout<<q.isEmpty()<<endl;
    cout<<"Dequeue: "; //스택이 비워질때까지 Dequeue한다.. 
    while(true) 
    {
        if(q.isEmpty() == true)
            break;
        cout<<q.Dequeue()<<" ";
    }
    cout<<endl<<endl;
    //결과 : Dequeue: 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

    return 0;
}

Queue::Queue():Rear(nullptr){}

Queue::~Queue()
{
    while(isEmpty() == false)
        Dequeue();
}

void Queue::Enqueue(int item)
{
    if(!isEmpty())
    {
        node* ptr = new node;
        ptr->Data = item;
        ptr ->Next = Rear->Next;

        Rear->Next = ptr;
        Rear = ptr;
    }  
    else
    {
        node* ptr = new node;
        ptr->Data = item;
        ptr->Next = ptr;
        Rear = ptr;
    }
}
int Queue::Dequeue()
{

}

bool Queue::isEmpty()
{

}
bool Queue::isFull()
{

}
