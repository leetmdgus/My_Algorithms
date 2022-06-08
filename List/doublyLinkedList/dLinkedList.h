#include <iostream>
template <typename T>
class Node {
public:
    Node(T element) : element(element), prev(nullptr), next(nullptr) {}
    ~Node() {}
    T element;
    Node* prev, * next;
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() :size(0), tail(nullptr), head(nullptr) {}
    ~DoublyLinkedList() {
        while (!isEmpty()) {
            remove(0);
        }
    }

    void addValueIntoTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            size++;
            tail = newNode;
            head = tail;
            return;
        }
        size++;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void addValueIntoIndex(T value, int index) {
        if (isIndexOutOfRange(index)) {
            return;
        }
        if (isEmpty() || index == size) {
            addValueIntoTail(value);
            return;
        }

        size++;
        Node<T>* newNode = new Node<T>(value);
        if (index == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node<T>* node = getNodeAtIndex(index)->prev;
        newNode->prev = node;
        newNode->next = node->next;
        node->next = newNode;
        node->next->prev = newNode;

    }

    void remove(int index) {
        if (isIndexOutOfRange(index)) {
            return;
        }
        if (isEmpty()) {
            return;
        }
        else if ((size - 1) == 0) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }

        Node<T>* node = getNodeAtIndex(index);
        size--;
        if (index == 0) {
            head = head->next;
            head->prev = nullptr;

            node->next = nullptr;
            delete node;
            return;
        }
        else if (index == size - 1) {
            tail = tail->prev;
            tail->next = nullptr;

            node->prev = nullptr;
            delete node;
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
        delete node;

    }
    
    // isIndexOutOfRange(index) == true일 경우 반환값 추가하기
    T getInIndex(int index) {
        if (!isIndexOutOfRange(index)){
            Node<T>* node = getNodeAtIndex(index);
            T value = node->element;
            return value;
        }
    }
    T setValueAtIndex(T value, int index) {
        if (!isIndexOutOfRange(index)) {
            Node<T>* node = getNodeAtIndex(index);
            T element = node->element;
            node->element = value;
            return element;
        }
    }

    int indexOf(T value) {
        Node<T>* node = head;
        for (int i = 0; i < size; i++) {
            if (node->element == value) {
                return i;
            }
            node = node->next;
        }
        return -1;
    }

    int getSize() {
        return size;
    }

    void printList() {
        if (isEmpty()) {
            return;
        }
        Node<T>* node = head;
        while (node != tail) {
            std::cout << node->element << " -> ";
            node = node->next;
        }
        std::cout << node->element << std::endl;

    }
private:
    bool isEmpty() {
        return (size == 0);
    }
    bool isIndexOutOfRange(int index) {
        return (index<0 || index>size);
    }

    Node<T>* getNodeAtIndex(int index) {
        int repeat;
        Node<T>* node;

        if (index <= (size - 1) / 2) {
            node = head;
            repeat = index;
            while (repeat--) {
                node = node->next;
            }
        }
        else {
            node = tail;
            repeat = (size - 1) - index;
            while (repeat--) {
                node = node->prev;
            }
        }
        return node;
    }

private:
    int size;
    Node<T>* head, * tail;

};