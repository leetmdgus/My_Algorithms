#include <iostream>

using namespace std;

class Queue
{
public:
    Queue();
    ~Queue();

    void Enqueue(int item);
    void Dequeue();

    bool isEmpty();
    bool isFull();

private:
    int Front, Rear;
    int Count;          //원형 연결 배열에 사용
    int Array[100];
};
int main(void)
{
    return 0;
}