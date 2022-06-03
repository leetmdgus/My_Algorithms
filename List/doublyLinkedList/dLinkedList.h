template <typename T>
class Node{
public:
    Node(T element): element(element), prev(nullptr), next(nullptr) {}
    ~Node(){}
    T element;
    Node *prev, *next; 
};

template <typename T>
class DoublyLinkedList {
public: 
  DoublyLinkedList():size(0), tail(nullptr), head(nullptr){}
  ~DoublyLinkedList()
  {
    while(!isEmpty())
    {
      remove(0);
    }
  }

  void add(T value)
  {
    size++;
    Node<T>* newNode = new Node(value);
    if(isEmpty())
    {
      tail = newNode;
      head = tail;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void add(T value, int index)
  {
    if(indexCheck(index))
    {
      return;
    }
    
    if(isEmpty() || index == size)
    {
      add(value);
      return;
    }

    size++;
    Node<T>* newNode = new Node(value);
  if(index == 0)
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      return;
    }

    Node<T>* node = getNode(index)->prev;
    newNode->prev = node;
    newNode->next = node->next;
    node->next = newNode;
    node->next->prev = newNode;

  }
  
  void remove(int index)
  {
    if(indexCheck(index))
    {
      return;
    }
    if(isEmpty())
    {
      return;
    } 
    else if(head == tail) // size == 1;/// size-1 == 0; 
    {
      delete head;
      head = nullptr;
      tail = nullptr;
      size = 0;
      return;
    }
  
    Node<T>* node = getNode(index);
    size--;
    if(index == 0)
    {
      head = head->next;
      head->prev = nullptr; 

      node->next = nullptr;
      delete node;
      return;
    }
    else if(index == size-1)
    {
      tail = tail->prev;
      tail->next = nullptr;

      node->prev = nullptr;
      delete node;
      return;
    }
    
    node->prev->next = node->next;
    // prevNode->next = nextNode;

    node->next->prev = node->prev;

    node->next = nullptr;
    node->prev = nullptr;
    delete node;

  }
  T get(int index)
  {
    if(indexCheck(index)) // get 이랑 set이랑 너무 비슷한데
    {
      return;
    }
    Node<T>* node = getNode(index);
    T value = node->element;
    return value;
  }
  T set(T value, int index)
  {
    if(indexCheck(index))
    {
      return;
    }
    
    Node<T>* node = getNode(index);
    T element = node->element;
    node->element = value; 
    return element;
  }

  int indexOf(T value)
  {
    Node<T>* node = head;
    for(int i = 0; i<size; i++)
    {
      if(node->element == value)
      {
        return i;
      }
      node -> node->next;
    }
    return -1;
  }

  int getSize()
  {
    return size;
  }
  bool isEmpty()
  {
    return (size==0);
  }
private: 
  bool indexCheck(int index)
  {
    return (index<0 || index>size);
  }

  Node<T>* getNode(int index){
    int repeat;
    Node<T>* node;
    
    if(index <= (size-1)/2)
    {
      node = head;
      repeat = index;
      while(repeat--)
      {
        node = node->next;
      }
    }
    else
    {
      node = tail;
      repeat = (size-1)-index;
      while(repeat--)
      {
        node = node->prev;
      }
    }

    return node;
  }

private:
  int size;
  Node<T> *head, *tail;

};