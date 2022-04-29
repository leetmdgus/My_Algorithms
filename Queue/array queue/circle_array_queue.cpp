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
    int Dequeue();              // front�� �ִ� element�� ������. 
    bool IsEnd(int rf);         // rf�� ���� ���ִٸ� true�� ��ȯ�Ѵ�.     
    bool IsFull();          // ť�� ����á�ٸ� true�� ��ȯ�Ѵ�. 

    bool IsEmpty;   // ����Ʈ ���� true�̴�. 

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
    Queue q;    //�⺻ capacity�� 10�̴�. 
    //1���� 4���� ť�� ���ڸ� �ִ´�.
    for(int i = 1; i<5; i++)
        q.Enqueue(i);
    // ť ����: 1 2 3 4
    cout<<q.IsEmpty<<" "<<q.IsFull()<<" "<<endl;
    // 0 0

    for(int i = 1; i<3; i++)
        cout<<q.Dequeue()<<" ";
    // ť����: 3 4  
    // 1 2 ���
    
    for(int i = 1; i<5; i++)
        q.Enqueue(i);
    // ť���� 3 4 1 2 3 4

    cout<<endl;
    for(int i = 1; i<7; i++)
        cout<<q.Dequeue()<<" ";
    //ť ���� :  
    // 3 4 1 2 3 4 ���

    cout<<endl;
    cout<<q.IsEmpty<<" "<<q.IsFull()<<" "<<endl;
    //����ְ�, ���� ���־����Ƿ�
    // 1 0

    return 0;
}

Queue::Queue() :front(-1), rear(-1), capacity(DEFAULT_CAPACITY)
{// �⺻ �������̴�. front -1, rear -1, capacity�� 10�̴�. 
    array = new int[capacity]();
    //capacity��ŭ�� ������ �Ҵ��ϰ�
    //array�� ����Ű�� �Ѵ�. �� ������ 0���� �ʱ�ȭ�Ѵ�. 
    IsEmpty = true;
    // ó�� ��������� ť�� ����ִ�. 
}
Queue::Queue(int capacity) :front(-1), rear(-1), capacity(capacity)
{//�������̴�. front -1, rear -1, capacity�� ������ capacity�� �����Ѵ�. 
    array = new int[capacity]();
    //capacity��ŭ�� ������ �Ҵ��ϰ�
    //array�� ����Ű�� �Ѵ�. �� ������ 0���� �ʱ�ȭ�Ѵ�. 
    IsEmpty = true;
    // ó�� ��������� ť�� ����ִ�. 
}

Queue::~Queue()
{   // Empty�� �ɶ����� ť�� ����. 
    int num;
    while(IsEmpty == false)
        num = Dequeue();
    //ť�� �Ҵ�Ǿ��� ������ �ݳ��Ѵ�. 
    delete[] array;
}


void Queue::Enqueue(int element) //element�� ť�� �ִ´�. 
{
    //.ť�� ���� ä���� ���¶�� ���̻� ��Ҹ� ���� �� ����. 
    if(IsFull() == true)
    {
        cout<<"ť�� ���� á���ϴ�. "<<endl;
        return;
    }
    //���� rear�� ���� ���ִٸ� rear�� ���� -1�� �ʱ�ȭ�Ѵ�. 
     if(IsEnd(rear) == true)
        rear = -1;
    
    rear++;
    
    array[rear] = element;
    IsEmpty = false;
    //��Ұ� �������� ���̻� �� ť�� �ƴϴ�. 
}
int Queue::Dequeue()    //element�� ������. 
{
    //���� �� ť��� ���� ���� �� ����. 
    if(IsEmpty == true)
        return -1;  

    // data�� �ϳ����̶�� �� data�� �� �Ŀ� 
    // �� ť�� �ȴ�. 
    front++;    
    if(IsOneData() == true)
        IsEmpty = true;

    int data = array[front];
    array[front] = 0;

    return data;
}

bool Queue::IsFull() 
{   //ť�� ����á�ٸ� ture, �ƴϸ� false�̴�. 
    int next_rear = rear+1; 
    if(IsEnd(rear) == true)    //front���� ���� ��ġ�ߴٸ�
    {// next_rear 0�̶� �����Ѵ�. 
        next_rear = 0;
    }
    return (array[next_rear] != 0) ? true : false;
    // next_front�� rear�� ���ٸ� �̰��� ���� �� ť��. 
}


bool Queue::IsEnd(int rf)
{
    // rear Ȥ�� front�� ��ü ���� �������� -1�� ��ġ�Ѵٸ�
    // �׵��� ť�� ���� �ִ�. 
    return (rf == capacity-1) ? true : false;
}
bool Queue::IsOneData()
{   // front �� rear�� ���� ���� ����Ű��
    // �� ť�� �ƴҶ� �� ť�� �ϳ��� �����͸� �����ϴ�. 
    return (front == rear && IsEmpty == false)? true : false;
}   


//capacity�� ��ȯ�մϴ�.
int Queue::GetCapacity(){return capacity;}
//front�� ��ȯ�մϴ�. 
int Queue::GetFront(){return front;}
//rear�� ��ȯ�մϴ�.
int Queue::GetRear(){return rear;}

