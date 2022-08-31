template <typename T>
class Node {
public:
    Node(T value) :element(value), next(nullptr) {};
    
    T element;
    Node* next;
};

template <typename T>
class LinkedList {
public:
    LinkedList() :head(nullptr), tail(nullptr), size(0) { }
    ~LinkedList() 
    {
        while (!isEmpty())
        {
            remove(0);
        }
    }

    void add(T element)
    {
        Node<T>* newNode = instanceNode(element); 
        if (isEmpty())
        {
            tail = newNode;
            head = tail;
            return;  
        }
        tail->next = newNode;
        tail = newNode;

    }

    void add(T element, int index) //생각
    {
        if(indexCheck())
        {
            return;
        }    
        else if (size == 0 || index == size-1)
        {
            add(element);
            return;
        } 

        Node<T>* newNode = instanceNode(element);
        if (index == 0)  //생각
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node<T>* preNode = getNode(--index);
        newNode->next = preNode->next;
        preNode->next = newNode;

    }

    bool remove(int index)
    {  
        if(indexCheck())
        {
            return;
        }    
        if(isEmpty())
        {
          return;
        }

        size--;
        if (index == 0)
        {
            if (size == 1)  //size 1일때 생각해보기
            {
                head = nullptr;
                delete tail;
                tail = nullptr;
                return;
            }
            Node<T>* oldNode = head;
            head = head->next;
            delete oldNode;
            return;

        }
        else if (index == size - 1)
        {
            Node<T>* preNode = getNode(index);
            Node<T>* oldNode = tail;

            tail = preNode;
            tail->next = nullptr;
            delete oldNode;
            return;
        }

        Node<T>* preNode = getNode(--index);
        Node<T>* oldNode = preNode->next;

        preNode->next = oldNode->next;
        delete oldNode;
    }

    T get(int index)
    {
      Node<T>* node = getNode(index); // getNode indexCheck
      return node->element;
    }

    T set(T element, int index)
    {
      Node<T>* node = getNode(index);
      T oldValue = node->element;
      node->element = element;
      return oldValue;
    }

    
    
    int indexOf(T element)
    {
        if (!isEmpty())
        {
          Node<T>* node = head;
          for(int i = 0; i<size; i++) // nude == null일때 체크
          {
            if(node->element == element)
            {
              return i;
            }
            node = node->next;
          }
        }
        return -1;
    }
    
    int getSize()
    {
        return size;
    }
    bool isEmpty() 
    {
        return (size == 0);
    }

private: 
    bool indexCheck(int index)
    {
      return (index<0||index>size)
    }
    Node<T>* getNode(int index) 
    {
        Node<T>* node = head;
        
        while (index--) 
        {
            node = node->next;
        }
  
        return node;
    }
    Node<T>* instanceNode(T element)
    { 
      size++;
      return new Node<T>(element);  
    }
        
    
private:
    Node<T>* head, * tail;
    int size;
};