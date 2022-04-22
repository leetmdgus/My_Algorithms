#define ARRAY_SIZE 100

typedef int element; //int형 자료형에 element라 별칭 붙임.

class ArrayStack
{
public:
    ArrayStack();
    ArrayStack(const ArrayStack &copy);
    ~ArrayStack();

    void Push(element item);    //item값을 스택에 삽입
    int Pop();                  //스택 탑의 데이터 값을 리턴함
    bool IsEmpty(); //비어 있는지 확인
    bool IsFull();  //꽉차 있는지 확인

private:
    int top;
    int Stack[ARRAY_SIZE];
};