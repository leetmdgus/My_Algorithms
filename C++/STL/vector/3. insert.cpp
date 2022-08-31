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
  // - 중간 삽입/삭제 (BAD)
  // - 처음/끝 삽입/삭제 (BAD / GOOD)
  // - 임의 접근 (Random Access)

  // vector = 동적 배열 = 동적으로 커지는 배열 = 배열
  // 원소가 하나의 메모리 블록에 연속하게 저장된다!!!

  // [               ]
  // [0][1][2][3][][]
  // 중간 삽입 삭제가 비효율적!
  // 처음 삽입 삭제시 비효율적!
  // 끝 삽입 삭제에서는 효율적!
  // 임의 접근 시 인덱스로 접근할 수 있다!

  vector<int> v(100);
  v.push_back(1);
  v.pop_back();

  // 3번째 데이터는 어디있습니까?
  v[2];

  // vector<int>::iterator insertit = v.insert(v.begin()+2, 5);
  // vector<int>::iterator eraseit1 = v.erase(v.begin()+2);
  // vector<int>::iterator eraseit2 = v.erase(v.begin()+2, v.begin()+4); // [2] [3] 만 삭제
  
  //쭉 -스캔을 하면서, 3이라는 데이터 있으면 일괄 삭제하고 싶다!

  for(vector<int>::iterator it = v.begin(); it!=v.end();)//++it가 아닌 else문에서 ++it를 해주어야 한다. 
  {
    int data = *it;
    if(data == 3)
    {
      // v.erase(it); //에러 발생. it가 사라져 버려서..ㅜㅜ 바로 break;해줘야한다. 
      // crash발생..!
      it = v.erase(it); //삭제하는 순간 it가 사라지기 때문에 재갱신을 해주어야 한다. 
    
    }else
    {
      ++it;
    }
    // v.clear(); 를 한경우 바로 break;를 해주어야 한다. iterator날아가서 난리나유ㅜㅜ.
  }
  return 0;
}