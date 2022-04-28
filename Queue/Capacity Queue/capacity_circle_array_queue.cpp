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
    bool IsFull();  // 큐가 가득찼다면 true를 반환한다. 
    bool IsEmpty;   // 디폴트 값은 true이다. 

    void Extend();  // 규가 가득 찼다면 큐를 확장한다. 
    void CopyArray(int* array, int* old_array); 
    // 새로 확장된 큐에 기존의 큐를 복사한다. 
    void ArrayClear(int* array);
    // 큐를 0으로 초기화시킨다. 

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
    Queue q234; //기본 q의 디폴트 capacity는 10이다. 
    Queue q(3); //capacity는 3이라 설정한다. 

    cout<<"enqueue: ";
    for(int i = 1; i<10; i++)
    {
        cout<<i<<" ";
        q.Enqueue(i);
    }
    //enqueue: 1 2 3 4 5 6 7 8 9 
    cout<<endl;

    cout<<"dequeue: ";
    for(int i = 1; i<2; i++)
    {
        cout<<q.Dequeue()<<" ";
    }
    //dequeue: 1 
    cout<<endl;
    
    cout<<"enqueue: ";
    for(int i = 1; i<3; i++)
    {
        cout<<i<<" ";
        q.Enqueue(i);
    }
    //enqueue: 1 2
    cout<<endl;
    
    cout<<"dequeue: ";
    for(int i = 1; i<20; i++)
    {
        cout<<q.Dequeue()<<" ";
    }
    // dequeue: 2 3 4 5 6 7 8 9 1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 
    cout<<endl;

    cout<<"capacity: "<<q.GetCapacity()<<endl;
    cout<<"front: "<<q.GetFront()<<", rear: "<<q.GetRear()<<endl;
    // capacity: 81
    // front: -1, rear: -1

    return 0;
}

Queue::Queue(): front(-1), rear(-1), capacity(DEFAULT_CAPACITY) 
{   //디폴트 생성자. front, rear =-1, capacity는 10으로 설정한다. 
    array = new int[capacity]();    
    //capacity만큼 공간을 할당한 후, 그 공간을 array가 가리킨다. 
    IsEmpty = true;
    // 처음 만들었기 때문에 큐는 비어있다. 
}

Queue::Queue(int capacity): front(-1), rear(-1), capacity(capacity)
{   //생성자, front, rear = -1, capacity는 사용자가 지정한다. 
    array = new int[capacity]();
    //capacity만큼 공간을 할당한 후, 그 공간을 array가 가리킨다. 
    IsEmpty = true;
    //큐는 비어있다. 
}

Queue::~Queue()//소멸자
{   
    ArrayClear(array);
    //큐의 내용을 0으로 초기화 해준다. 
    delete[] array;
    //array가 가리키고 있던 공간을 반납한다. 
}

void Queue::Enqueue(int element)
{   //element 를 큐의 rear쪽에 넣는다. 
    rear++; //rear은 다음 리어라고 생각한다. 

    if(IsFull() == true)        
    {   //만약 큐가 가득차있다면
        Extend();   //큐를 확장하라
    }
    if(IsEmpty == true)
    {   //만약 큐가 비어있었다면
        front = rear;   
    }   //프론트와 리어를 같은 값으로 가리켜라.
    if(rear == capacity)
        rear = 0;
        //만약 rear가 범위를 초과했다면 다시 0으로 돌아가라

    array[rear] = element;  //rear에 element를 넣는다.
    IsEmpty = false;    //Enqueue했으므로 비어있지 않다. 
}
int Queue::Dequeue()
{   //큐의 front의 값을 지우는 메서드입니다.     
    if(IsEmpty == true)
    {   //만약 큐가 비어있다면 -1을 반환합니다. 
        return -1;
    }
    int data = array[front];
    array[front] = 0;

    if(IsOneData() == true)
    {   // 만약 큐의 원소가 하나라면 
        // data를 반환합니다.
        // 그러면 큐는 비게 됩니다.  
        rear = -1;
        front = -1;
        IsEmpty = true;
        return data;
    } 
    //front에 1을 더해줍니다. 
    front++;
    //만약 front가 capacity와 같다면 범위 초과이므로 0으로 돌려줍니다. 
    if(front == capacity)
        front = 0;

    return data;
}

bool Queue::IsFull() 
{   //큐가 가득찼다면 ture, 아니면 false이다. 
    int next_front = front+1; 
    if(next_front == capacity)
    {//만약 next_front가 큐의 범위를 초과했다면 0이라 설정한다. 
        next_front = 0;
    }
    return (next_front == rear) ? true : false;
    // next_front가 rear와 같다면 이것은 가득 찬 큐다. 
}

bool Queue::IsOneData() 
{   //데이터가 하나만 있습니까?
    //큐가 비어있지 않고
    //rear와 front가 같다면, 데이터는 하나입니다.  
    if(IsEmpty == false)
        if(rear == front)   
            return true;
    return false;
}


void Queue::Extend()   
{//큐를 확장합니다. 
    int* old_array = array;
    //old_array는 기존의 큐를 가리킵니다. 

    int new_capacity = capacity*capacity;
    // 새로운 capacity는 기존 capacity*capacity입니다. 

    array = new int[new_capacity]();
    // 새로운 capacity로 공간을 할당합니다. 
    // array는 새로 만들어진 공간을 가리킵니다. 

    CopyArray(array, old_array);
    // array에 기존의 큐의 값을 복사합니다. 

    delete[] old_array;
    // 기존에 있는 공간을 반납합니다. 

    capacity = new_capacity;
    //이제 capacity는 확장되었습니다. 
}
void Queue::CopyArray(int* array, int* old_array)
{   //old_array값을 array에 복사합니다. 
    for(int i = 0; i<capacity; i++)
    {
        array[i] = old_array[i];
    }
}

void Queue::ArrayClear(int *array)
{   //큐의 요소를 0으로 초기화합니다. 
    for(int i = 0; i<capacity; i++)
        array[i] = 0;
    IsEmpty = true;
}

int Queue::GetCapacity()
{   //capacity를 반환합니다.
    return capacity;
}
int Queue::GetFront()
{   //front를 반환합니다. 
    return front;
}
int Queue::GetRear()
{   //rear를 반환합니다. 
    return rear;
}