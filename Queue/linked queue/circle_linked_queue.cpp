#include <iostream>
using namespace std;
typedef struct Node
{
    int Data;   
    Node* Next; 
    // 노드는 데이터와 
    // 다음 노드를카리키는 포인터로 이루어져있다. 
}node;


class Queue
{
public: 
    Queue();    // 생성자
    // rear = nullptr, isEmpty는 true로 설정한다.  
    ~Queue();   // 소멸자

    void Enqueue(int item); // item을 추가한다.
    int Dequeue();  // 요소를 삭제한다. 

    bool isEmpty;   // 큐가 비었습니까?
    bool isOneData();   //원소가 하나입니까?

private:
    node* rear; // rear 포인터 
};

int main(void)
{
    Queue q;
    // Enqueue: 1 2 3 4 5 6 7 8 9 10 11 12 13
    cout<<"Enqueue: ";
    for(int i = 1; i<14; i++)
    {
        cout<<i<<" ";
        q.Enqueue(i);

    }   
    cout<<endl;

    //Dequeue: 1 2 3 4 5 6 7 8 9 10 11 12 13
    cout<<"Dequeue: ";
    for(int i = 1; i<14; i++)
    {   
        cout<<q.Dequeue()<<" ";
    }
    cout<<endl;

    return 0;
}
Queue::Queue():rear(nullptr), isEmpty(true){}  
//생성자
Queue::~Queue()
{   //소멸자 
    //큐가 빌때까지 dequeue하고
    //큐가 할당되었던 공간을 반납한다.
    while(!isEmpty)
        Dequeue();
    
    delete rear;
    isEmpty = true;
}

void Queue::Enqueue(int item)
{   //큐에 요소를 추가한다. 
    // 만약 큐가 비어있다면,
    if(isEmpty == true)
    {   //rear는 새로운 노드를 가리킨다. 
        rear = new node();
        // rear-> Next는 rear을 가리킨다. 
        rear->Next = rear;
    }  
    else
    {
        // 새로운 리어는 새로운 노드를 카리킨다.
        node *new_rear = new node();
        // 새로운 리어의 Next는 기존에 리어가 가리키고 있던
        // Next를 가리킨다.
        new_rear->Next = rear->Next;
        // 기존의 rear->Next는 새로운 리어를 가리킨다.
        rear->Next = new_rear;
        //rear는 새로운 라어를 가리킨다.
        rear = new_rear; 
    } 

    // 리어에 데이터를 추가한다. 
    rear->Data = item;
    // 큐는 더이상 비어있지 않다. 
    isEmpty = false;
}

int Queue::Dequeue()  //요소를 반환한다. 
{   // 만약 큐가 비어있다면 -1을 반환한다. 
    if(isEmpty == true)
    {
        return -1;
    }    
    // 만약 요소가 하나라면
    if(isOneData())
    {   //그 요소가 dequeue되면 큐는 빈다.
        isEmpty = true;
    }    

    //old_rear는 기존의 rear->Next이다.
    // 그리고 우리는 rear-> Next에 할당되었던 공간을 
    // 해제할 것이다. 
    node* old_rear = rear->Next;

    rear->Next = old_rear->Next;
    //rear-> Next는 old_rear->Next로 가리킨다. 

    int data = old_rear->Data;
    //old_rear->Data값을 저장한다.
    
    //old_rear가 가리키고 있던 공간을 반납
    delete old_rear;
    return data;
}


bool Queue::isOneData()
{   
    //만약 rear->Next가 rear를 가리킨다면
    // 그 큐는 요소가 하나다. 
    return (rear->Next == rear && !isEmpty);
}

