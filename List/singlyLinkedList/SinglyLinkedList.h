struct Node
{
	int Value;
	Node* Next;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	int Get(int index);
	int IndexTail();
	void AddHead(int val);
	void AddTail(int val);
	void AddIndex(int index, int val);
	int DeleteIndex(int index);
	bool IsEmpty();
	void ShowLinkedList();
private:
	Node *head, *tail;
};

