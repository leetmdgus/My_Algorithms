typedef int element; //int형 자료형에 element라 별칭 붙임.

typedef struct Node
{
    element Data;   //스택 데이터를 정수 타입으로 가정
    Node *Next; //다음 노드를 가리키는 포인터 변수

}node;  //노드는 구조체 타입

class LinkedStack
{
public:
    LinkedStack();  //생성자 함수
    LinkedStack(const LinkedStack & S); //복사 생성자 함수
    ~LinkedStack(); //소멸자 함수

    void Push(element item);    //item값을 스택에 삽입
    int Pop();                  //스택 탑의 데이터 값을 리턴함
    bool IsEmpty(); //비어 있는지 확인
    bool IsFull();  //꽉차 있는지 확인

private:
    node* Top;  //첫 노드를 가르키는 포인터
};
