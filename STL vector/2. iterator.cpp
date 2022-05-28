#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

int main()
{
  // STL(Standard Template Library)
  // 프로그래밍할 때 필요한 자료구조/ 알고리즘들을
  // 템플릿으로 제공하는 라이브러리
  
  // 컨테이너(Container): 데이터를 저장하는 객체 (자료구조 Data Structure)

  // vector (동적 배열)
  // - vector의 동작 원리 (size/capacity)
  // - 중간 삽입/삭제
  // - 처음/끝 삽입/삭제
  // - 임의 접근

  // 반복자(iterator) : 포인터와 유사한 개념, 컨테이너 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
  
  vector<int> v(10);

  for(vector<int>::size_type i = 0; i<v.size(); i++)
    v[i] = i;

  vector<int>::iterator it; 
  int* ptr;

  it = v.begin();
  ptr = &v[0];

  
  cout<<(*it)<<endl;  // operator overloading
  cout<<(*ptr)<<endl;

  // it++; ++it;
  // ptr++; ++ptr;

  vector<int>::iterator itBegin = v.begin();
  vector<int>::iterator itEnd = v.end();  //쓰레기값이 들어감. 유효한 데이터 다음 범위를 가리킴.

  // 더 복잡해 보이는데 왜쓰지?
  // iterator는 vector뿐 아니라, 다른 컨테이너에도 공통적으로 있는 개념!
  // STL한정 통일성을 준다. 
  // 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안 될 수 있다!

  // auto == vector<int>::iterator
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) // ++it하는 것이 미세하게 성능이 좋다. 
  {
    cout<<(*it)<<endl;
  }

  int* ptrBegin = &v[0]; // == v.begin()._Ptr;
  int* ptrEnd = ptrBegin+10; //== v.end()._Ptr;
  for(int *ptr = ptrBegin; ptr!=ptrEnd; ++ptr)
  {
    cout<<*(ptr)<<endl;
  }

  vector<int>::const_iterator cit = v.cbegin(); 
  // 포인터 기준 const pointer이다. 
  // 데이터 수정을 하지 않고 read만을 하고 싶을때!
  // 값을 수정할 수 없다. 

  for(vector<int>::reverse_iterator it = v.rbegin(); it!=v.rend(); ++it)
  {
    cout<<(*it)<<endl;
  }
  // 마지막 값부터 거꾸로 간다. 유후

 
  return 0;
}