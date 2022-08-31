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
    Queue();    //생성자
    ~Queue();   //소멸자

    void Enqueue(int item); //item을 넣는다.
    int Dequeue();          //front에서 item을 반환한다.
    bool isEmpty;   //기본값은 true라고 한다.
    bool isOneData();   //큐 안 데이터가 하나라면, true이다. 

private:
    node * Front; // 기본값은 nullptr이다. 
    node* Rear;     //기본값은 nullptr이다. 
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

Queue::Queue(): Front(nullptr), Rear(nullptr), isEmpty(true){}

Queue::~Queue()
{   
    //큐가 빌때동안 dequeue한다. 
    int num;
    while(isEmpty == false)
        num = Dequeue();
    
    //큐가 가지고 있던 공간을 반납한다. 
    delete Front;

    Front = nullptr;
    Rear = nullptr;
}

void Queue::Enqueue(int item)   //item을 넣는다. 
{
    if(isEmpty == true) //만약 큐가 비어있다면
    {   //새로운 노드를 만들어 Rear와 Front가 가리키게 한다. 
        Rear = new Node;
        Front = Rear;
    }    
    else//만약 큐가 비어있지 않다면
    {   //기존 Near->Next에 새로운 노드를 가리키게 한다. 
        Rear->Next = new Node;
        Rear = Rear->Next;
        //Rear는 새로운 노드를 가리킨다. 
    }

    //새로 만든 노드의 Data에 item을 넣는다.
    Rear->Data = item;
    //노드의 Next= nullptr로 지정한다. 
    Rear->Next = nullptr;
    //item이 들어왔으니 큐는 비어있지않다. 
    isEmpty = false;
}
int Queue::Dequeue()    //front에서 item을 반환한다.
{   //만약 큐가 비어있다면 -1을 반환한다. 
    if(isEmpty == true)
        return -1;
    
    //만약 Data가 하나뿐이었다면
    if(isOneData() == true)
        isEmpty = true;
        //그 Data가 리턴된다면 빈큐가 된다. 

    // Front를 다음 노드를 가리킨다. 
    Node* old_front = Front;
    Front = Front->Next;

    //기존 노드의 데이터를 저장한다. 
    int data = old_front -> Data;
    //이전 노드를 지운다. 
    delete old_front;
    return data;
    //데이터를 반환한다. 
}


bool Queue::isOneData()
{   //큐가 비어있지 않고, Front와 Rear가 같다면 그 큐는 원소를 하나 갖는다. 
    return (Front == Rear && isEmpty ==false) ? true: false;
}