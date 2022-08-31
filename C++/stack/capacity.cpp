#include<iostream>
using namespace std;

#define DEFAULT_CAPACITY 10

class Stack
{
public:
    Stack();
    Stack(int capacity);
    ~Stack();

    void Push(int element); // 정수 element 를 스택에 넣는다. 
    int Pop();      // Top에 있는 요소를 반환하고, Top에 있는 요소를 지운다. 
                    //만약 탑에 요소가 없다면 -1을 리턴한다. 
    int Top();      // Top에 있는 요소를 반환한다. 
    bool IsEmpty(); // 스택이 비었는지 확인한다. 만약 비었다면 true를 반환한다. 
	void Extend();  // capacity * capacity 크기만큼 스택을 확장한다.
    void ArrayCopy(int* new_array, int* old_array); 
    // new_array와 old_array는 배열을 가리키는 포인터다. 
    // 새롭게 크기가 커진 스택에 이전 스택의 요소를 복사한다. 
    // 예를 들어 new_array[100]이고 old_array[10]이라면 
    // old_arra의 요소를 new_array복사한다. 

    int GetCapacity();      //capacity의 값을 리턴한다. 

private:
    int *array;     // 스택의 index 0번을 가리키는 포인터다. 
    int top;        // 스택의 top을 가리킨다. 
    int capacity;   // 스택의 크기를 의미한다. 
};


int main(void)  //main함수이다. 
{
    Stack s;    //디폴트 생성자로 기본 capacity는 10으로 설정된다. 
    Stack s1(3);    //capacity는 3이다. 

    cout<<"push: "; // 스택에 0부터 14까지 push한다. 
    for(int i = 0; i<15; i++)
    {
        cout<<i<<" ";
        s.Push(i);
    }
    cout<<endl<<endl;
    //결과 : push: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    
    cout<<"pop: "; //스택이 비워질때까지 pop한다. 
    while(true) 
    {
        if(s.IsEmpty() == true)
            break;
        cout<<s.Pop()<<" ";
    }
    cout<<endl<<endl;
    //결과 : pop: 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0

    cout<<"capacity : "<<s.GetCapacity()<<endl;
    //결과 : capacity: 100

    return 0;
}


Stack::Stack(): top(-1), capacity(DEFAULT_CAPACITY) //디폴트 생성자다. 
{   // top은 -1, capacity의 값은 DEFAULT_CAPACITY(10)으로 한다. 
    array = new int[DEFAULT_CAPACITY];  
    // 힙 공간에 int[10]만큼의 공간을 동적 할당한 후, 그 공간을 array로 가리켜라.  
    // 즉, 크기 10의 int형 배열을 할당한 후 index 0번을 array로 가리켜라.
    
}
Stack::Stack(int capacity): top(-1), capacity(capacity) //생성자. 
{   // top은 -1, capacity는 객체 생성시 명시한 capacity로 설정한다. 
    array = new int[capacity];
    // 힙 공간에 capacity 크기의 배열을 할당한 후, 그 공간을 array로 가리켜라. 
    // 만약 Stack(3)이라면 capacity는 3이된다. 
}

Stack::~Stack() //소멸자.
{   
    int num;   
    while(IsEmpty() == false)   //스택을 비운다. 
        num = Pop();

    delete[] array; // array가 가리키고 있는 힙에 할당된 공간을 풀어준다.  
}

void Stack::Push(int element)   //스택에 element를 넣는 메서드이다. 
{
    array[++top] = element;     //top에 1을 더한 후 배열에 요소를 넣는다. 
    if(top == capacity) // 만약 top과 capacity가 같은 경우 == 스택이 꽉차있을 경우
        Extend();       // 스택을 capacity*capacity 만큼 확장한다. 
}

int Stack::Pop()    //스택에서 탑에 있는 요소를 리턴하고 탑에 있는 요소를 지운다. 
{
    return (IsEmpty() == true) ? -1 : array[top--]; 
    // 만약 스택이 비어있다면 -1을 리턴한다. 
}
int Stack::Top()    //스택에서 탑의 요소를 반환한다. 
{                   //만약 스택이 비어있다면 -1을 리턴한다. 
    return IsEmpty() ? -1 : array[top];
}
bool Stack::IsEmpty()   //스택이 비어있는지 확인한다. 
{                       //만약 비어있다면 true를 반환하고 아니면 false를 반환한다. 
    return bool(top == -1); 
}

void Stack::Extend()    //스택을 확장한다. 
{
    int *old_array = array; //old_array포인터는 기존의 스택을 가리킨다.  
    capacity *= capacity;   //capacity에 capacity*capacity만큼 크기를 키운다. 

    array = new int[capacity];  
    // 이전보다 확장된 int[capacity]만큼의 공간을 만들어 array가 가리키게 한다. 
    // 정리하자면 기존 스택은 old_array가 가리키고 있고
    // 확장된 새로 만든 스택은 array가 가리키고 있다. 

    ArrayCopy(array, old_array); //새로 만들어진 스택에 기존의 스택을 복사한다. 
    
    
    delete[] old_array; //기존의 스택 공간 할당을 풀어준다. 
}

void Stack::ArrayCopy(int* new_array, int* old_array)   
{//new_array가 가리키고 있는 스택에 old_array가 가리키고 있는 스택을 복사한다. 
    for(int i = 0; i<=top; i++) 
        array[i] = old_array[i];

}

int Stack::GetCapacity() //capacity의 값을 얻는다. 
{ 
    return capacity;
}
