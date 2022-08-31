#include <iostream>

template <typename T>
class Stack {
private:
    T *list;
    int head, tail;
    int capacity;
    int size;

public: 
    Stack(int capacity = 10): head(0), tail(0), size(0), capacity(capacity){
        list = new T[size];
    }
    ~Stack() {
        delete[] list;
    }

    void push(T data) {
        size++;
        if(isFull()) {
            expandArray();
        }
        list[++tail] = data;
    }
    T pop() {
        if(!isEmpty()) {
            size--;
            T result = list[tail--];
            return result;
        } 
    } 
    bool isFull() {
        return (capacity == size);
    }
    bool isEmpty() {
        return (size == 0);
    }
    
private:
    T* expandArray() {
        T *tmp = list;
        list = new T[capacity << 2];
        copyArrayAToB(tmp, list);
    }
    void copyArrayAToB(T* list, T* copiedList) {
        for(int i = 0; i<tail+1; i++) {
            copiedList[i] = list[i];
        }
    }
};

template <typename T>
class Queue {

};

template <typename T>
class Node {
private:
    T data;
    Node *leftChild;
    Node *rightChild; 
    Node *parent;

public:
    Node(): data(0), leftChild(nullptr), rightChild(nullptr), parent(nullptr){}
    Node(T data, Node* left, Node *right, Node *parent): data(data), leftChild(left), rightChild(right), parent(parent){}
    ~Node() {leftChild = nullptr; rightChild = nullptr; parent = nullptr;}

    Node* getLeftChild() {
        return leftChild;
    }
    Node* getRightChild() {
        return rightChild;
    }
    Node* getParent() {
        return parent;
    }
    void setLeftChild(Node node) {
        leftChild = node;
    }
    void setRightChild(Node node) {
        rightChild = node;
    }
    void setParent(Node node) {
        parent = node;
    }
    std::string toString() {
        std::string str;
        
        if(leftChild != nullptr && rightChild != nullptr) {
            str.append("leftChild: ").append(leftChild->data).append(",").append(" rightChild: ").append(rightChild->data);
        } else if(leftChild != nullptr) {
            // str = "leftChild: " + leftChild->data +", rightChild: " + "null";
        } else if(rightChild != nullptr) {
            // str = "leftChild: " + "null" +", rightChild: " + rightChild->data;
        } else {
            // str = "leftChild: " + "null" +", rightChild: " + "null";
        }
        return str; 
    }
};

class VirtualTreeTraversal {
public:
    virtual void preOrder()=0;
    virtual void inOrder()=0;
    virtual void postOrder()=0;
    virtual void levelOrder()=0;
};


template <typename T>
class TreeIterativeTraversal: public VirtualTreeTraversal{
private:
    Node<T> *root;
public:
    TreeIterativeTraversal(){}
    ~TreeIterativeTraversal(){}

    void preOrder() {
        Node<T> *node = root;
        Stack<Node<T>> stack();
        stack.push(node);
        while(!stack.isEmpty()) {
            Node<T>* currentNode = stack.pop();
            std::cout << currentNode->data << " ";

            if(currentNode->leftChild != nullptr) {
                stack.push(currentNode->leftChild);
            }
            if(currentNode -> rightChild != nullptr) {
                stack.push(rightChild -> data);
            }
        }
        std::cout << std::endl;
    }
    virtual void inOrder() {
        Node<T> *node = root;
        Stack<Node<T>> stack();
        stack.push(node);
        while(!stack.isEmpty()) {
            Node<T>* currentNode = stack.pop();
            std::cout << currentNode->data << " ";

            if(currentNode->leftChild != nullptr) {
                stack.push(currentNode->leftChild);
            }
            if(currentNode -> rightChild != nullptr) {
                stack.push(rightChild -> data);
            }
        }
        std::cout << std::endl;
    }

    virtual void postOrder(Node<T> node) {

    }
    virtual void levelOrder(Node<T> node) {
       
    }

};

class TreeIterativeTraversalString: public TreeIterativeTraversal<std::string>{
    TreeIterativeTraversalString(){}
    TreeIterativeTraversalString(std::string *data, int length) {
        
        Node<Node<std::string>*> *array = new Node<std::string>[length];
        
        for (int i = 0; i < length; i++) {
            array[i] = new Node<std::string>(data[i], nullptr, nullptr, nullptr);
            int *a = new int[3];

        }

        for (int i = 0; i < length; i++) {    // A B C D E F G H I J
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < length) {
                array[i]->left = array[left];
                array[left].parent = array[i];
            }
            if (right < array.length) {
                array[i].right = array[right];
                array[right].parent = array[i];
            }
        }
        root = array[0];
    }

};

class TreeIterativeTraversalStringChar: public TreeIterativeTraversal<char> {
    TreeIterativeTraversalStringChar(){}
    TreeIterativeTraversalStringChar(char *data, int size) {
    }

};

class TreeIterativeTraversalStringInt : public TreeIterativeTraversal<int> {

};

int main(void) {
    
    return 0;
} 