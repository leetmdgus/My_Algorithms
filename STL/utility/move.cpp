#include <utility>
#include <vector>

int main(void)
{
  std::vector<int> myBigVec(10000000, 2011);
  std::vector<int> myVec;
  myVec = myBigVec;     // 복제 의미론
  myVec = std::move(myBigVec);// 이동 의미론
}