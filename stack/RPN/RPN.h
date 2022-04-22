class Stack_
{
public:
    Stack_();
    ~Stack_();

    void Push(int element);
    int Pop();
    bool is_Empty();

    void operate(char oper);
    void printStack();

private: 
    int Top;
    int stack[10];
};
