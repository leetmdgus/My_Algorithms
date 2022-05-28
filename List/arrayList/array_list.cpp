#include <iostream>

using namespace std;

struct Node
{
    int Data;
    Node *Prev, *Next;
}node;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Add(int item);
    int Delete(int item);

    bool Search(int item);
    int Count();
    bool IsEmpty();
private:
    Node* Head;
};

int main(void)
{
    LinkedList l;
    l.Add(3);
    l.Add(5);
    cout<<l.Count()<<endl;
    cout<<l.Delete(5)<<endl;
    cout<<l.Delete(7)<<endl;
    cout<<l.Delete(3)<<endl;
    cout<<l.IsEmpty()<<endl;
    l.Add(3);
    l.Add(5);
    cout<<l.IsEmpty()<<endl;
    cout<<l.Search(5)<<endl;
    cout<<l.Search(7)<<endl;
    
    return 0;
}

LinkedList::LinkedList()    
{//Head의 기본값은 nullptr이다. 
    Head = nullptr;
}

LinkedList::~LinkedList()
{//소멸할때 Head를 NextNode라 한다. 

    Node *NextNode = Head->Next;
    while(IsEmpty() == false)
    {
        Node *old_node = NextNode;
        NextNode = NextNode->Next;

        old_node->Data = 0;
        old_node->Prev = nullptr;
        old_node->Next = nullptr;
        delete old_node;
    }
}

void LinkedList::Add(int item)
{
    cout<<"Add item: "<<item<<endl;

    if(IsEmpty() == true)
    {    //만약 
        Head = new Node();
        Head->Prev = nullptr;
        Head->Data = item;
        Head->Next = nullptr;
    }
    
    Node * NextNode = Head -> Next;

    while(NextNode->Next != nullptr)
    {
        NextNode = NextNode->Next;
    }
    

    Node *NewNode = new Node();
    
    if(NextNode->Next != nullptr)
    {        
        Node *PrevNode = NextNode->Prev;
        NextNode = NextNode->Next;
        PrevNode->Next = NewNode->Prev;
        NewNode->Prev = PrevNode->Next;
        NewNode->Next = NextNode->Prev;
        NextNode->Prev = NewNode->Next;
        NewNode->Data = item;
        return;
    }
    
    NextNode->Next =NewNode->Prev;
    NewNode->Prev = NextNode->Next;
    NewNode ->Next = nullptr;
    NewNode->Data = item;
    
}
int LinkedList::Delete(int item)
{
    cout<<"delete item: "<<item<<endl;
    if(IsEmpty() == true)
        return -1;

    Node * NextNode = Head -> Next;
    while(NextNode->Data != item)
    {
        NextNode = NextNode->Next;
    }
    
    if(NextNode->Data == item && NextNode->Next != nullptr)
    {
        Node *old_node = NextNode;
        Node *PrevNode = NextNode->Prev;
        Node *NextNode = NextNode->Next;
        PrevNode->Next = NextNode->Prev;
        NextNode->Prev = PrevNode->Next;

        int data = old_node->Data;
        delete old_node;

        old_node->Prev = nullptr;
        old_node->Next = nullptr;
        return data;
    }
    else if(NextNode->Data == item && NextNode->Next == nullptr)
    {
        Node *old_node = NextNode;
        int data = old_node->Data;
        
        delete old_node;
        old_node->Prev = nullptr;
        old_node->Next = nullptr;
        return data;
    }
    return -1;

}


bool LinkedList::Search(int item)
{
    if(IsEmpty() == true)
        return false;

    Node * NextNode = Head -> Next;
    while(NextNode->Data != item)
    {
        NextNode = NextNode->Next;
    }
    
    if(NextNode->Data == item)
    {
        return true;
    }
    return false;


}
int LinkedList::Count()
{   //링크드 리스트 안 요소의 개수를 반환한다.
    //count는 0으로 한다. 
    int count = 0;
    // Head를 NextNode가 가리키게 한다.
    if(IsEmpty() == true)
        return count;
        //만약 요소가 비어있다면 0을 반환한다. 
     
    Node *NextNode = Head;
    // 만약 NextNoode->Next가 nullptr이라면
    // 요소는 하나만 남는다.  
    while(NextNode->Next != nullptr)
    {
        count++;
        NextNode = NextNode->Next;
    }
    count++;
    return count;
}
bool LinkedList::IsEmpty()
{
    return (Head->Data == 0)? true:false;
}