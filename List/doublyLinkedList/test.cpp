#include "dLinkedList.h"
#include <iostream>

void addValueIntoTailTest();
void addValueIntoIndexTest();
void removeTest();
void indexOfTest();
void getInIndexTest();
void setValueAtIndex();

int main() {
	setValueAtIndex();
	return 0;
}

void addValueIntoTailTest() {
	DoublyLinkedList<int> d;
	d.addValueIntoTail(1);
	d.printList();
	d.addValueIntoTail(2);
	d.printList();
	d.addValueIntoTail(3);
	d.printList();
	d.addValueIntoTail(4);
	d.printList();
	d.addValueIntoTail(5);
	d.printList();

	std::cout << d.getSize() << std::endl;
}

void addValueIntoIndexTest() {
	DoublyLinkedList<int> d;
	for (int i = 0; i < 10; i++) {
		d.addValueIntoTail(i);
	}
	d.printList();
	d.addValueIntoIndex(100, 3);
	d.printList();
	d.addValueIntoIndex(200, 3);
	d.printList();
	d.addValueIntoIndex(300, 3);
	d.printList();

	std::cout << d.getSize() << std::endl;
}

void removeTest() {
  DoublyLinkedList<int> d;
  for (int i = 0; i < 10; i++) {
		d.addValueIntoTail(i);
	}
  d.remove(1);
  d.printList();
  d.remove(1);
  d.printList();
  d.remove(1);
  d.printList();

	std::cout << d.getSize() << std::endl;  
}

void indexOfTest() {
  DoublyLinkedList<int> d;
  for (int i = 10; i < 20; i++) {
		d.addValueIntoTail(i);
	}
  d.printList();
  for(int i = 10; i<20; i++) {
    std::cout << d.indexOf(i) << " ";
  }
}

void getInIndexTest() {
  DoublyLinkedList<int> d;
  for(int i = 10; i<20; i++) {
    d.addValueIntoTail(i);
  }
  d.printList();
  for(int i = 0; i<10; i++) {
    std::cout << d.getInIndex(i) <<" ";
  }
  
}

void setValueAtIndex() {
  DoublyLinkedList<int> d;
  for(int i = 10; i<20; i++) {
    d.addValueIntoTail(i);
  }
  d.printList();
  d.setValueAtIndex(100,0);
  d.printList();
  d.setValueAtIndex(200,1);
  d.printList();
  d.setValueAtIndex(300,2);
  d.printList();
}