// c:/mingw/bin/../lib/gcc/mingw32/6.3.0/../../../libmingw32.a(main.o):(.text.startup+0xa0): undefined reference to `WinMain@16'
// collect2.exe: error: ld returned 1 exit status
// 터미널 프로세스 "C:\WINDOWS\System32\WindowsPowerShell\v1.0\powershell.exe -Command g++ c:\ALGORITHMS\List\singlyLinkedList\newLinkedList.cpp -o c:\ALGORITHMS\List\singlyLinkedList/newLinkedList"이(가) 종료되었습니다(종료 코드: 1).
// -> template은 선언과 정의를 분리해서는 안됨

// 이게 뭔 에러야..ㅜㅜ
#include "newLinkedList.h"
#include <iostream>
using namespace std;

// string 안됨
// char 일때 결과가 영어가 아닌 ASCII로 나옴.

int main(void)
{
	try {
		LinkedList<int> list;

	}
	catch (int size) {
		cout << "list size: " << size << endl;
	}
	
	return 0;
}

// template <typename T>
// LinkedList<T>::LinkedList() :head(nullptr), tail(nullptr), size(0) { }

// template <typename T>
// LinkedList<T>::~LinkedList() {
//     while (!isEmpty())
//     {
//       remove(0);
//     }
// }

// template <typename T>
// bool LinkedList<T>::add(T element)// tail쪽에 data삽입
// {
//     if (isEmpty())
//     {
//         tail = new Node<T>(element);
//         head = tail;
//     }
//     else
//     {
//         Node<T>* preTail = tail;
//         tail = new Node<T>(element);
//         preTail->next = tail;
//     }
//     size++;
// }

// template <typename T>
// bool LinkedList<T>::add(T element, int index) {
    // if (index < 0 || size < index) {
    // }
    
    // Node<T>* preNode = head;
    // int preIndex = index - 1;
    // while (preIndex--)
    // {
    //     preNode = preNode->next;
    // }

    // Node<T>* newNode = new Node<T>(element);

    // size++;
// }

// template <typename T>
// T LinkedList<T>::get(int index) {
//     if (index < 0 || size < index) {
//     }
//     Node<T>* currentNode = head;
//     while (index--)
//     {
//         currentNode = currentNode->next;
//     }
//     return currentNode->element;
// }

// template <typename T>
// T LinkedList<T>::set(T newElement, int index) {
//     if (index < 0 || size < index) {
//     }

//     Node<T>* currentNode = head;
//     while (index--)
//     {
//         currentNode = currentNode->next;
//     }
//     T oldElement = currentNode->element;
//     currentNode->element = newElement;
//     return oldElement;
// }

// template <typename T>
// bool LinkedList<T>::remove(int index) {
//     if (index < 0 || size < index) {
//     }
//     if (size == 1)
//     {
//         delete tail;
//     }
//     else if(index == 0)
//     {
//         Node<T>* oldHead = head;
//         head = head->next;
//         delete oldHead;
//     }
//     else if (index == size - 1)
//     {
//         Node<T>* oldTail = tail;
        
//         Node<T>* newTail = head;
//         while (index--)
//         {
//             newTail = newTail->next;
//         }

//         tail = newTail;
//         tail->next = nullptr;
//         delete oldTail;
//     }
//     else 
//     {
//         Node<T>* preNode = head;
//         while(index--) 
//         {
//             preNode = preNode->next;
//         }
//         Node<T>* oldNode = preNode->next;
//         preNode->next = oldNode->next;
//         delete oldNode;
//     }

//     size--;
// }

// template <typename T>
// int LinkedList<T>::indexOf(T element) {
//     int index = -1;
//     Node<T>* currentNode = head;
//     if (!isEmpty())
//     {
//         while (size--)
//         {
//             currentNode = currentNode->next;
//             index++;
//         }
//     }
//     return index;
// }

// template <typename T>
// int LinkedList<T>::getSize() {
//     return size;
// }

// template <typename T>
// bool LinkedList<T>::isEmpty() {
//     return (size == 0);
// }

// template <typename T>
// void LinkedList<T>::print() 
// {

// }