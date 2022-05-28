#include <iostream>
using namespace std;
#include <vector>
#include <list>

// 오늘의 주제 :list

int main()
{
  // list (연결 리스트)
  // - list 의 동작 원리
  // - 중간 삽입/삭제
  // - 처음/끝 삽입/삭제
  // - 임의 접근
  
  list<int> li;
  for(int i = 0; i<100; i++)
  {
    li.push_back(i);
  }
  
  int size = li.size();

  // li.capacity(); list는 capacity개념이 없다!

  int first = li.front();
  int last = li.back(); 

  
  


  return 0;
}