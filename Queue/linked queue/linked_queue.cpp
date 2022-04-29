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
    bool isEmpty;
    bool isOneData();

private:
    node * Front;
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
    
    cout<<"Dequeue: "; //스택이 비워질때까지 Dequeue한다.. 
    while(true) 
    {
        if(q.isEmpty == true)
            break;
        cout<<q.Dequeue()<<" ";
    }
    cout<<endl<<endl;
    //결과 : Dequeue: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    
    cout<<q.isEmpty<<endl;
    //결과 1

    return 0;
}

Queue::Queue()
{
    Front = nullptr;
    Rear = nullptr;
    isEmpty = true;
}

Queue::~Queue()
{
    int num;
    while(isEmpty == false)
        num = Dequeue();
    
    delete Front;
}

void Queue::Enqueue(int item)
{
    if(isEmpty == true)
    {
        Rear = new Node;
        Front = Rear;
    }    
    else
    {
        Rear->Next = new Node;
        Rear = Rear->Next;
    }
    
    Rear->Data = item;
    Rear->Next = nullptr;
    isEmpty = false;
}
int Queue::Dequeue()
{
    if(isEmpty == true)
        return -1;
    
    if(isOneData() == true)
        isEmpty = true;

    Node* old_front = Front;
    Front = Front->Next;

    int data = old_front -> Data;

    delete old_front;
    return data;

}


bool Queue::isOneData()
{
    return (Front == Rear && isEmpty ==false) ? true: false;
}