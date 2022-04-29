#include <iostream>
using namespace std;
typedef struct Node
{
    int Data;
    Node* Next;
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
    node* rear;
};

int main(void)
{
    Queue q;
    cout<<"Enqueue: ";
    for(int i = 1; i<14; i++)
    {
        cout<<i<<" ";
        q.Enqueue(i);
    }   
    cout<<endl;

    cout<<"Dequeue: ";
    for(int i = 1; i<14; i++)
    {
        cout<<q.Dequeue()<<" ";
    }
    return 0;
}
Queue::Queue():rear(nullptr), isEmpty(true){}
Queue::~Queue()
{
    int num;
    while(isEmpty ==false)
        num = Dequeue();
    
    delete rear;
    isEmpty = true;
}

void Queue::Enqueue(int item)
{
    if(isEmpty == true)
    {
        rear = new node;
        rear->Next = rear;
    }   

    node* new_rear = new node;
    rear->Next = new_rear;
    new_rear->Next = rear;

    rear = new_rear; 
    isEmpty = false;
}

int Queue::Dequeue()
{
    if(isEmpty == true)
        return -1;
    if(isOneData() == true)
    {   
        isEmpty = true;
    }    

    node* old_rear = rear->Next;
    rear->Next = old_rear->Next;
    

    old_rear->Next = nullptr;
    
    delete old_rear;
    
}


bool Queue::isOneData()
{
    return (rear->Next == rear) ? true : false;
}