#include <iostream>

using namespace std;

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
    int Front, Rear;
    int capacity;
    int Array[100];
};
int main(void)
{

    return 0;
}

Queue::Queue(): Front(-1), Rear(-1){}
Queue::~Queue()
{

}

void Queue::Enqueue(int item)
{
    Rear++;
    Array[Rear] = item;
    if(isFull() == true);
        //만약 스택이 가득 찼다면,, 어떡하냐!. capacity를 늘려야지.
}
int Queue::Dequeue()
{
    Front++;
    if(Front > Rear)
        return -1;
    

}

bool Queue::isEmpty()
{

}
bool Queue::isFull()
{

}