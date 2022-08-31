#include <iostream>
using namespace std;

#define DEFAULT_CAPACITY 10
//디폴트 capacity는 10으로 한다. 

class Queue
{
public: 
    Queue();    //기본 생성자
    Queue(int capacity);    
    //객체의 capacity는 객체 생성시 적어놓은 capacity로 설정한다. 
    ~Queue();   //소멸자

    void Enqueue(int element);  //element를 rear에 집어 넣는다. 
    int Dequeue();  // front에 있는 element를 빼낸다. 
    bool IsEnd();    // rear가 끝까지 찼다면 더이상 요소를 넣을 수 없다.    
    bool IsFull();  // 큐가 가득찼다면 true를 반환한다. 

    bool IsEmpty;   // 디폴트 값은 true이다. 

    bool IsOneData();   
    // 큐에 데이터가 1개뿐이라면 true를 반환한다. 

    int GetCapacity();  //capacity를 반환한다.
    int GetFront();     //front를 반환한다.
    int GetRear();      //rear를 반환한다. 
private:
    int front, rear;    // 생성시 기본 값은 -1, -1로 초기화한다. 
    int capacity;       // 디폴트 생성자시 10이다. 
    int* array;         // 큐는 정수형 값만 넣는 것으로 한다. 
};                      // 0, -1을 넣으면 안 된다. 
                        // 0으로 초기화하기때문.
                        // 비어있을 때 -1을 반환하기때문.

int main(void)  //메인함수
{
    Queue q;    //기본 capacity는 10이다. 
    //1부터 10까지 큐에 숫자를 넣는다.
    for(int i = 1; i<11; i++)
        q.Enqueue(i);
    
    //비어있지 않고, 가득 차있고, rear가 끝에 가있으므로
    // 0 1 1
    cout<<q.IsEmpty<<" "<<q.IsFull()<<" "<<q.IsEnd()<<endl;

    for(int i = 1; i<11; i++)
        cout<<q.Dequeue()<<" ";
    //dequeue를 끝까지 한다. 

    cout<<endl;
    cout<<q.IsEmpty<<" "<<q.IsFull()<<" "<<q.IsEnd()<<endl;
    //비어있고, 가득 차있않고, rear가 끝에 가있으므로
    // 1 0 1

    return 0;
}

Queue::Queue() :front(-1), rear(-1), capacity(DEFAULT_CAPACITY)
{// 기본 생성자이다. front -1, rear -1, capacity는 10이다. 
    array = new int[capacity]();
    //capacity만큼의 공간을 할당하고
    //array가 가리키게 한다. 그 공간은 0으로 초기화한다. 
    IsEmpty = true;
    // 처음 만들었으니 큐는 비어있다. 
}
Queue::Queue(int capacity) :front(-1), rear(-1), capacity(capacity)
{//생성자이다. front -1, rear -1, capacity는 지정한 capacity로 설정한다. 
    array = new int[capacity]();
    //capacity만큼의 공간을 할당하고
    //array가 가리키게 한다. 그 공간은 0으로 초기화한다. 
    IsEmpty = true;
    // 처음 만들었으니 큐는 비어있다. 
}

Queue::~Queue()
{   // Empty가 될때까지 큐를 비운다. 
    int num;
    while(IsEmpty == false)
        num = Dequeue();
    //큐에 할당되었던 공간을 반납한다. 
    delete[] array;
}


void Queue::Enqueue(int element) //element를 큐에 넣는다. 
{
    //만약 rear가 끝에 가있다면 더이상 요소를 추가할 수 없다. 
    if(IsEnd() == true)
    {
        cout<<"rear가 큐의 끝에 있습니다. Dequeue를 통해 큐를 비워주세요."<<endl;
        return;
    }   
    
    rear++;
    
    array[rear] = element;
    IsEmpty = false;
    //요소가 들어왔으니 더이상 빈 큐가 아니다. 
}
int Queue::Dequeue()    //element를 꺼낸다. 
{
    //만약 빈 큐라면 값을 빼낼 수 없다. 
    if(IsEmpty == true)
        return -1;  

    // data가 하나뿐이라면 그 data를 뺀 후엔 
    // 빈 큐가 된다. 
    front++;    
    if(IsOneData() == true)
        IsEmpty = true;

    int data = array[front];
    array[front] = 0;

    return data;
}
bool Queue::IsFull()
{
    // 만약 front가 -1, 혹은 0이고, rear가 끝에 있다면 
    // 가득찬 큐다. 
    return (front <= 0 && IsEnd()) ? true : false;
}
bool Queue::IsEnd()
{
    // rear가 전체 설정 사이즈의 -1에 위치한다면
    // rear은 끝에 있다. 
    return (rear == capacity-1) ? true : false;
}
bool Queue::IsOneData()
{   // front 와 rear가 같은 값을 가리키며
    // 빈 큐가 아닐때 그 큐는 하나의 데이터를 가집니다. 
    return (front == rear && IsEmpty == false)? true : false;
}   


//capacity를 반환합니다.
int Queue::GetCapacity(){return capacity;}
//front를 반환합니다. 
int Queue::GetFront(){return front;}
//rear를 반환합니다.
int Queue::GetRear(){return rear;}