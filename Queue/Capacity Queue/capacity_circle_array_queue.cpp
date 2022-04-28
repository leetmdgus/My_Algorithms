#include <iostream>
using namespace std;

#define DEFAULT_CAPACITY 10
//����Ʈ capacity�� 10���� �Ѵ�. 

class Queue
{
public: 
    Queue();    //�⺻ ������
    Queue(int capacity);    
    //��ü�� capacity�� ��ü ������ ������� capacity�� �����Ѵ�. 
    ~Queue();   //�Ҹ���

    void Enqueue(int element);  //element�� rear�� ���� �ִ´�. 
    int Dequeue();  // front�� �ִ� element�� ������. 
    bool IsFull();  // ť�� ����á�ٸ� true�� ��ȯ�Ѵ�. 
    bool IsEmpty;   // ����Ʈ ���� true�̴�. 

    void Extend();  // �԰� ���� á�ٸ� ť�� Ȯ���Ѵ�. 
    void CopyArray(int* array, int* old_array); 
    // ���� Ȯ��� ť�� ������ ť�� �����Ѵ�. 
    void ArrayClear(int* array);
    // ť�� 0���� �ʱ�ȭ��Ų��. 

    bool IsOneData();   
    // ť�� �����Ͱ� 1�����̶�� true�� ��ȯ�Ѵ�. 

    int GetCapacity();  //capacity�� ��ȯ�Ѵ�.
    int GetFront();     //front�� ��ȯ�Ѵ�.
    int GetRear();      //rear�� ��ȯ�Ѵ�. 
private:
    int front, rear;    // ������ �⺻ ���� -1, -1�� �ʱ�ȭ�Ѵ�. 
    int capacity;       // ����Ʈ �����ڽ� 10�̴�. 
    int* array;         // ť�� ������ ���� �ִ� ������ �Ѵ�. 
};                      // 0, -1�� ������ �� �ȴ�. 
                        // 0���� �ʱ�ȭ�ϱ⶧��.
                        // ������� �� -1�� ��ȯ�ϱ⶧��.

int main(void)  //�����Լ�
{
    Queue q234; //�⺻ q�� ����Ʈ capacity�� 10�̴�. 
    Queue q(3); //capacity�� 3�̶� �����Ѵ�. 

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
{   //����Ʈ ������. front, rear =-1, capacity�� 10���� �����Ѵ�. 
    array = new int[capacity]();    
    //capacity��ŭ ������ �Ҵ��� ��, �� ������ array�� ����Ų��. 
    IsEmpty = true;
    // ó�� ������� ������ ť�� ����ִ�. 
}

Queue::Queue(int capacity): front(-1), rear(-1), capacity(capacity)
{   //������, front, rear = -1, capacity�� ����ڰ� �����Ѵ�. 
    array = new int[capacity]();
    //capacity��ŭ ������ �Ҵ��� ��, �� ������ array�� ����Ų��. 
    IsEmpty = true;
    //ť�� ����ִ�. 
}

Queue::~Queue()//�Ҹ���
{   
    ArrayClear(array);
    //ť�� ������ 0���� �ʱ�ȭ ���ش�. 
    delete[] array;
    //array�� ����Ű�� �ִ� ������ �ݳ��Ѵ�. 
}

void Queue::Enqueue(int element)
{   //element �� ť�� rear�ʿ� �ִ´�. 
    rear++; //rear�� ���� ������ �����Ѵ�. 

    if(IsFull() == true)        
    {   //���� ť�� �������ִٸ�
        Extend();   //ť�� Ȯ���϶�
    }
    if(IsEmpty == true)
    {   //���� ť�� ����־��ٸ�
        front = rear;   
    }   //����Ʈ�� ��� ���� ������ �����Ѷ�.
    if(rear == capacity)
        rear = 0;
        //���� rear�� ������ �ʰ��ߴٸ� �ٽ� 0���� ���ư���

    array[rear] = element;  //rear�� element�� �ִ´�.
    IsEmpty = false;    //Enqueue�����Ƿ� ������� �ʴ�. 
}
int Queue::Dequeue()
{   //ť�� front�� ���� ����� �޼����Դϴ�.     
    if(IsEmpty == true)
    {   //���� ť�� ����ִٸ� -1�� ��ȯ�մϴ�. 
        return -1;
    }
    int data = array[front];
    array[front] = 0;

    if(IsOneData() == true)
    {   // ���� ť�� ���Ұ� �ϳ���� 
        // data�� ��ȯ�մϴ�.
        // �׷��� ť�� ��� �˴ϴ�.  
        rear = -1;
        front = -1;
        IsEmpty = true;
        return data;
    } 
    //front�� 1�� �����ݴϴ�. 
    front++;
    //���� front�� capacity�� ���ٸ� ���� �ʰ��̹Ƿ� 0���� �����ݴϴ�. 
    if(front == capacity)
        front = 0;

    return data;
}

bool Queue::IsFull() 
{   //ť�� ����á�ٸ� ture, �ƴϸ� false�̴�. 
    int next_front = front+1; 
    if(next_front == capacity)
    {//���� next_front�� ť�� ������ �ʰ��ߴٸ� 0�̶� �����Ѵ�. 
        next_front = 0;
    }
    return (next_front == rear) ? true : false;
    // next_front�� rear�� ���ٸ� �̰��� ���� �� ť��. 
}

bool Queue::IsOneData() 
{   //�����Ͱ� �ϳ��� �ֽ��ϱ�?
    //ť�� ������� �ʰ�
    //rear�� front�� ���ٸ�, �����ʹ� �ϳ��Դϴ�.  
    if(IsEmpty == false)
        if(rear == front)   
            return true;
    return false;
}


void Queue::Extend()   
{//ť�� Ȯ���մϴ�. 
    int* old_array = array;
    //old_array�� ������ ť�� ����ŵ�ϴ�. 

    int new_capacity = capacity*capacity;
    // ���ο� capacity�� ���� capacity*capacity�Դϴ�. 

    array = new int[new_capacity]();
    // ���ο� capacity�� ������ �Ҵ��մϴ�. 
    // array�� ���� ������� ������ ����ŵ�ϴ�. 

    CopyArray(array, old_array);
    // array�� ������ ť�� ���� �����մϴ�. 

    delete[] old_array;
    // ������ �ִ� ������ �ݳ��մϴ�. 

    capacity = new_capacity;
    //���� capacity�� Ȯ��Ǿ����ϴ�. 
}
void Queue::CopyArray(int* array, int* old_array)
{   //old_array���� array�� �����մϴ�. 
    for(int i = 0; i<capacity; i++)
    {
        array[i] = old_array[i];
    }
}

void Queue::ArrayClear(int *array)
{   //ť�� ��Ҹ� 0���� �ʱ�ȭ�մϴ�. 
    for(int i = 0; i<capacity; i++)
        array[i] = 0;
    IsEmpty = true;
}

int Queue::GetCapacity()
{   //capacity�� ��ȯ�մϴ�.
    return capacity;
}
int Queue::GetFront()
{   //front�� ��ȯ�մϴ�. 
    return front;
}
int Queue::GetRear()
{   //rear�� ��ȯ�մϴ�. 
    return rear;
}