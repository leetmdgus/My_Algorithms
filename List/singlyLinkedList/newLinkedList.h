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
        if(index<0||index>size)
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
        if (index == 0)
        {
            if (size == 1)  //size 1일때 생각해보기
            {
                head = nullptr;
                delete tail;
                tail = nullptr;
            }
            else
            {
                Node<T>* oldNode = head;
                head = head->next;
                delete oldNode;
            }
        }
        else if (index == size - 1)
        {
            Node<T>* preNode = getNode(index);
            Node<T>* oldNode = tail;

            tail = preNode;
            tail->next = nullptr;
            delete oldNode;
        }
        else
        {
            Node<T>* preNode = getNode(--index);
            Node<T>* oldNode = preNode->next;

            preNode->next = oldNode->next;
            delete oldNode;
        }

        size--;
    }

    T get(int index)
    {
      Node<T>* node = getNode(index);
      T value = node->element;
      return value;
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
        int index = -1;
        Node<T>* node = head;
        if (!isEmpty())
        {
          for(int i = 0; i<size; i++)
          {
            index = i;
            if(node->element == element)
            {
              break;
            }
            node = node->next;
          }
        }
        return index;
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