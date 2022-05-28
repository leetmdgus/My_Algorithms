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

  // 배열
  // const int MAX_SIZE = 10;  // 크기가 고정됨 -> 메모리 낭비. 
  // int arr[MAX_SIZE] = {};   // 복사할때 시간이 오래 걸림... ㅜㅜ

  // for(int i = 0; i<MAX_SIZE; i++)
  //   arr[i] = i;

  // for(int i = 0; i<MAX_SIZE; i++)
  //   cout<<arr[i]<<endl;
  
  // 동적 배열
  // 매우매우 중요한 개념 -> 어떻게 배열을 '유동적으로'사용한 것인가?

  // 1) (여유분을 두고)메모리를 할당한다. -> 배열이랑 다를게 없음.
  // 2) 여유분까지 꽉 찼으면, 메모리를 증설한다. 
  // ex) int *arr2 = new int[100];
  //     delete[] arr2;
  //     arr2 = new int[1000];
  
  // Q1) 여유분은 얼만큼이 적당할까?
  // Q2) 증설을 얼만큼 해야 할까?
  // Q3) 기존의 데이터를 어떻게 처리할까?
  

  vector<int> v; // vector<int> v(100, 3); 생성자 자체에서 크기(size)를 지정할 수 있고 값을 초기화 할 수도 있다.
  vector<int> v2 = v; //vector<int> v(10) 일때 값은 0으로 초기화된다. 
  
  vector<int> v3(10); 
  for(int i = 0; i<v3.size(); i++)
  {
    cout<<v3[i]<<" ";
  }
  // size (실제 사용 데이터 개수)
  // 1 2 3 4 5 6 7 . . .
  // capacity (여유분을 포함한 용량 개수)
  // 1 2 4 8 16 32 . . .

  // v.resize(숫자); -> size를 수정한다. 
  // v.reserve(숫자); -> capacity를 수정한다. 
  // capacity가 변화할때마다 기존에 있던 데이터를 복사하는 과정해서 비용이 들기때문에
  // 넉넉하게 capacity를 잡아줌으로써 더 효율적으로 동작 가능하다.  // but 메모리가 낭비될 위험이 있음
  
  // size가 작아진다고, capacity도 줄어들지는 않는다. 
  // capacity가 작아진다면 기존에 있던 데이터를 복사하여 작은 capacity를 가진 배열에 복사해야하는데 이때 비용이 들기 때문에 불필요한 이동은 하지 않는다. 

  v.resize(100);
  cout<<v.size()<<" "<<v.capacity()<<endl;
  // size가 수정되었으니 capacity도 수정된다. 

  for(int i = 0; i<100; i++)
  {
    v.push_back(100);
    cout<<v.size()<<" "<<v.capacity()<<endl;
  }
  // v[i] 처럼 접근 가능하다. 
  v.pop_back();//마지막 요소를 꺼낼 수 있다. 
  v.back(); //맨 마지막 요소를 볼 수 있다. 
  v.front(); //맨 처음 요소를 볼 수 있다. 

  v.clear();
  cout<<v.size()<<" "<<v.capacity()<<endl;
  // 벡터를 비워도 capacity는 남아 있다. 

  vector<int>().swap(v); // capacity까지 날리고 싶을때, Tip. 임시 벡터를 만든다. 
  cout<<v.size()<<" "<<v.capacity()<<endl;
  
  return 0;
}