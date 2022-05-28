template <typename T>
class Node {
public:
    Node(T value) :element(value), next(nullptr) {};
    
    T element;
    Node* next;
};

template <typename T>
class CircularLinkedList
{
public:
  CircularLinkedList():tail(nullptr),size(0){};
  ~CircularLinkedList()
  { 
    while(!isEmpty())
    {
      pop();
    }
  } 

  void push(T element)
  {
    if(isEmpty())
    {
      tail = new Node<T>(element);
      tail->next = tail;
    } 
    else
    {
      Node<T>* newNode = new Node<T>(element);
      newNode->next = tail->next;
      tail->next = newNode;
      tail= newNode;
    }
    size++;
  }
  void unshift(T element)
  {
    if(isEmpty())
    {
      tail = new Node<T>(element);
      tail->next = tail;
    } 
    else
    {
      Node<T>* newNode = new Node<T>(element);
      newNode->next = tail->next;
      tail->next = newNode;
    }
    size++;
  }
  T pop()
  {
    Node<T>* oldNode = tail;
    Node<T>* preNode = getNode(size-2);

    tail = preNode;
    tail->next = oldNode->next;

    T value = oldNode->element;
    oldNode->next = nullptr;
    delete oldNode;
    return value;
  }
  T shift()
  {
    Node<T>* oldNode = tail->next;
    tail->next = oldNode->next;
    
    T value = oldNode->element;
    oldNode->next = nullptr;
    delete oldNode;
    return value;
  }
  
  int getSize()
  {
    return size;
  }
  bool isEmpty()
  {
    return (size == 0);
  }

  Node<T>* getNode(int index) 
    {
        Node<T>* node = tail->next;
        if !(index<0 || index > size - 1)
        {
          while (index--) 
          {
              node = node->next;
          }
        }
  
        return node;
    }
private:
  Node<T>* tail;
  int size;
};